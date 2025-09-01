#include "defs.h"


void show_stack(struct z_number **p);
void help(void);

int main(void)
{

	int a;
	int i;    
	int p;
	int x;	
	struct z_number *z_stack[SIZE];
	
	struct z_number *result;
	
	float real;
	float im;
	
	char opcode;
	int drop_flag;
	int polar_flag=0;
	int null_flag = 0;
	char line[20];

    /* Initializing the stack */

/*	printf("Clearing stack....\n"); */
	for(i=0;i<SIZE;++i)
	{
		z_stack[i] = make_z(0,0,0);
	}
	
	show_stack(z_stack);
	
	i = 0;

	while(1)
	{	
		while(1)
		{
			printf("Enter Real (or #_ command) : ");
			fgets(line, sizeof(line), stdin);
			if (line[0] == 35) /* # to enter opcode */
			{
				opcode = line[1];
				printf(" %c \n",opcode);
				break;
			}
/*
 *
 *
 *	need something on inputi handling to decide if existing z_stack[0] is
 *	POLAR 
 *
 *	 if so then to treat a new entry as POLAR also
 *
 *
 *
 */
			else
			{
				if (line[0] == '\n')
					real = 0;
/*				{
					real = z_stack[0]->abs_zre;
					if(z_stack[0]->sign_zre[0] == '-')
					{
						real = -1*real;
					}
				} */
				else if (line[0] > 44 && line[0] < 58)
				{
					sscanf(line, "%f", &real);
				 /* printf(" %.3f \n", real); */
				}
				else
				{
					real = 0;
				}				
				polar_flag = 0;	
					
				printf("Enter Imaginary : ");
				fgets(line, sizeof(line), stdin);
				if (line[0] == '\n')
					im = 0;
/*				{
					im = z_stack[0]->abs_zim;
					if(z_stack[0]->sign_zim[0] == '-')
					{
						im = -1*im;
					}
				} */
				else if (line[0] > 44 && line[0] < 58)
				{
					sscanf(line, "%f", &im);
				/*	printf(" %.3f \n", im); */
				}
				else if (line[0] == 64)  /* @ for polar argument */
				{
					for (i = 0;i<strlen(line);++i)
					{
						line[i] = line[i+1];
					}
					sscanf(line, "%f", &im);
				/*	printf("POLAR %.3f \n", im); */
					polar_flag = 1;
				}
				else
				{
					im = 0;
				}	


		
			/**********************************
			 *
			 * STACK RAISE
			 *
			 * ********************************/
				a=i;
				while(a>0)
				{
					z_stack[a] = z_stack[a-1];
					--a;
				}
				
				if (real == 0 && im == 0)
				{

					real = z_stack[0]->abs_zre;
					if(z_stack[0]->sign_zre[0] == '-')
					{
						real = -1*real;
					}


					im = z_stack[0]->abs_zim;
					if(z_stack[0]->sign_zim[0] == '-')
					{
						im = -1*im;
					}

				}

				z_stack[0] = make_z(real, im, polar_flag);
				++i;
		
				if(i > SIZE-1)
					i = SIZE - 1;

			/********************
			 * 
			 * print stack after raise
			 *
			 * **************************/
				polar_flag = 0;	
					
				show_stack(z_stack);
		
			}
		}	
		
		polar_flag = 0;
		null_flag = 0;
		switch (opcode)
		{
			case '+':
		  	/*  printf("Adding \n");  */
				result = add_z(z_stack[1], z_stack[0]);
				drop_flag = 1;
				break;
			case '-':
			/*	printf("Subtracting \n"); */
				result = subtract_z(z_stack[1], z_stack[0]);
				drop_flag = 1;
				break;
			case '*':
			/*	printf("Multilying \n");  */
				result = multiply_z(z_stack[1], z_stack[0]);
				drop_flag = 1;
				break;
			case '/':
			/*	printf("Dividing \n");  */
				result = divide2_z(z_stack[1], z_stack[0]);
				drop_flag = 1;
				break;
			case 'i':
			case 'I':
			/*	printf("Inverse \n");  */
				result = invert_z(z_stack[0]);
				drop_flag = 0;
				break;
			case 'c':
			/*	printf("Complex Conjugate \n"); */
				result = conjugate_z(z_stack[0]);
				drop_flag = 0;
				break;
			case 'p':
			/*	printf(" -> Polar \n");  */
				if(!z_stack[0]->polar)
					result = rect_to_polar(z_stack[0]);
				else
					result=z_stack[0];
				polar_flag = 1;
				drop_flag = 0;
				break;
			case 'r':
			/*	printf(" -> Rect \n");  */
				if(z_stack[0]->polar)
					result = polar_to_rect(z_stack[0]);
				else
					result=z_stack[0];
				polar_flag = 0;
				drop_flag = 0;
				break;
			case 'h':
				help();
				drop_flag = 0;
				null_flag = 1;
				break;
			case 'q':
			case 'Q':
				return(0);
			default:
			/*	printf("Not understood... \n"); */
				drop_flag = 0;
				null_flag = 1;

		}

		/*************************************
		 *
		 *  DROP STACK
		 *
		 * **********************************
		 */

		/*
		printf("Drop flag %d \n", drop_flag);
		printf("Polar_flag %d \n", polar_flag);
		printf("null_flag %d \n", null_flag);	
		*/

		/* make new stack-value from result */
		if(polar_flag)
		{
				z_stack[0]->sign_zre[0] = result->sign_zre[0];
				z_stack[0]->sign_zim[0] = result->sign_zim[0];;	
				z_stack[0]->abs_zre = result->abs_zre;
				z_stack[0]->abs_zim = result->abs_zim;
				z_stack[0]->polar = 1;
			
		}

		if(drop_flag)
		{
			a = 0;
				
			while(a<i)
				{
					z_stack[a] = z_stack[a+1];
					++a;
				}
				z_stack[0]->sign_zre[0] = result->sign_zre[0];
				z_stack[0]->sign_zim[0] = result->sign_zim[0];	
				z_stack[0]->abs_zre = result->abs_zre;
				z_stack[0]->abs_zim = result->abs_zim;
				z_stack[0]->polar = result->polar;
		
		}
		else
		{
			if(null_flag)
				;

			else if(!polar_flag)
			{
				z_stack[0]->sign_zre[0] = result->sign_zre[0];
				z_stack[0]->sign_zim[0] = result->sign_zim[0];	
				z_stack[0]->abs_zre = result->abs_zre;
				z_stack[0]->abs_zim = result->abs_zim;
				z_stack[0]->polar = result->polar;
			}
		}

		/***************************************
		 *
		 *   PRINT STACK AFTER DROP
		 *
		 ***************************************/

		show_stack(z_stack);

		}
    return 0;
}

void show_stack(struct z_number **p)
{
	char polar_char;
	int x;

	polar_char = ' ';

	printf("\n\n=========================================================\n\n");

	for (x=SIZE-1;x>=1;--x)
	{
		if(p[x]->polar == 1)
			polar_char = '@';
		else
			polar_char = ' ';
    	printf("z_stack[%0d]\t\t%c%.3f %c %c%.3f j \n", 
			x,
			p[x]->sign_zre[0], p[x]->abs_zre,
			polar_char,
			p[x]->sign_zim[0], p[x]->abs_zim);
	}



		if(p[0]->polar == 1)
			polar_char = '@';
		else
			polar_char = ' ';
    		printf("\nz_stack[%0d]\t\t%c%.3f %c %c%.3f j \n\n", 
			x,
			p[0]->sign_zre[0], p[0]->abs_zre,
			polar_char,
			p[0]->sign_zim[0], p[0]->abs_zim);
}


void help(void)
{
	printf("Experimental RPN calculator with complex stack\n\n");
	printf("Usage:\n");
	printf("\nAt \"Enter Real\" propmt type either a command prefixed by the # sign\n");
	printf("......or a number to put on the stack \n");
	printf("\nFor number entry type the number and press <Enter>\nFor zero just press Enter\n");
	printf("For a complex number : \nat the \"Enter Imaginary:\" prompt enter the imaginary part.\nFor zero just press Enter\n\n");
	printf("Commands (prefix by #): \n");
	printf("Add		+\n");
	printf("Subtract	-\n");
	printf("Multiply	*\n");
	printf("Divide		/\n\n");
	printf("Inverse 1/z		i\n");
	printf("Complex Conjugate	c\n");
	printf("Rect -> Polar		p\n");
	printf("Polar -> Rect		r\n\n");
	printf("This HELP		h\n");
	printf("Quit			q\n");



}

