#include "defs.h"


void show_stack(struct z_number **p);

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
	int polar_flag;

	char line[20];

    /* Initializing the stack */

	printf("Clearing stack....\n");
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
			printf("Enter Real : ");
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
				{
					real = z_stack[0]->abs_zre;
					if(z_stack[0]->sign_zre[0] == '-')
					{
						real = -1*real;
					}
				}
				else if (line[0] > 44 && line[0] < 58)
				{
					sscanf(line, "%f", &real);
					printf(" %.3f \n", real);
				}
		
				printf("Enter Imag : ");
				fgets(line, sizeof(line), stdin);
				if (line[0] == '\n')
				{
					im = z_stack[0]->abs_zim;
					if(z_stack[0]->sign_zim[0] == '-')
					{
						im = -1*im;
					}
				}
				else if (line[0] > 44 && line[0] < 58)
				{
					sscanf(line, "%f", &real);
					printf(" %.3f \n", real);
				}
		
		
				if (line[0] > 44 && line[0] < 58)
				{
					sscanf(line, "%f", &im);
					printf(" %.3f \n", im);
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
		
				z_stack[a] = make_z(real, im, 0);
		
				++i;
		
				if(i > SIZE-1)
					i = SIZE - 1;

			/********************
			 * 
			 * print stack after raise
			 *
			 * **************************/
		
				show_stack(z_stack);
		
			}
		}	
		
		polar_flag = 0;

		switch (opcode)
		{
			case '+':
				printf("Adding \n");
				result = add_z(z_stack[1], z_stack[0]);
				drop_flag = 1;
				break;
			case '-':
				printf("Subtracting \n");
				result = subtract_z(z_stack[1], z_stack[0]);
				drop_flag = 1;
				break;
			case '*':
				printf("Multilying \n");
				result = multiply_z(z_stack[1], z_stack[0]);
				drop_flag = 1;
				break;
			case '/':
				printf("Dividing \n");
				result = divide2_z(z_stack[1], z_stack[0]);
				drop_flag = 1;
				break;
			case 'i':
			case 'I':
				printf("Inverse \n");
				result = invert_z(z_stack[0]);
				drop_flag = 0;
				break;
			case 'c':
				printf("Complex Conjugate \n");
				result = conjugate_z(z_stack[0]);
				drop_flag = 0;
				break;
			case 'p':
				printf(" -> Polar \n");
				if(!z_stack[0]->polar)
					result = rect_to_polar(z_stack[0]);
				else
					result=z_stack[0];
				polar_flag = 1;
				drop_flag = 0;
				break;
			case 'r':
				printf(" -> Rect \n");
				if(z_stack[0]->polar)
					result = polar_to_rect(z_stack[0]);
				else
					result=z_stack[0];
				polar_flag = 0;
				drop_flag = 0;
				break;
			case 'q':
			case 'Q':
				return(0);
			default:
				printf("Not understood... \n");
				drop_flag = 0;

		}

		/*************************************
		 *
		 *  DROP STACK
		 *
		 * **********************************/
		printf("Drop flag %d \n", drop_flag);
		

		/* make new stack-value from result */
		if(polar_flag)
		{
				z_stack[0]->sign_zre[0] = result->sign_zre[0];
				z_stack[0]->sign_zim[0] = '@';	
				z_stack[0]->abs_zre = result->abs_zre;
				z_stack[0]->abs_zim = result->abs_zim;
				z_stack[0]->polar = 1;
				printf("made a polar = %d\n", z_stack[0]->polar);
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
				printf("after a drop : polar = %d\n", z_stack[0]->polar);
		
		}
		else
		{
			if(!polar_flag)
			{
				z_stack[0]->sign_zre[0] = result->sign_zre[0];
				z_stack[0]->sign_zim[0] = result->sign_zim[0];	
				z_stack[0]->abs_zre = result->abs_zre;
				z_stack[0]->abs_zim = result->abs_zim;
				z_stack[0]->polar = 0;
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
	int x;
	printf("\nPrinting from show_stack()\n");
	for (x=SIZE-1;x>=0;--x)
	{
    	printf("z_stack[%d]\t%c%.3f %c%.3f j  (p=%d) \n", 
			x,
			p[x]->sign_zre[0], p[x]->abs_zre,
			p[x]->sign_zim[0], p[x]->abs_zim,
			p[x]->polar);
	}
}


