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
		z_stack[i] = make_z(0,0);
	}
	
	show_stack(z_stack);
	
	i = 0;

	while(1)
	{	
		while(1)
		{
			printf("Enter Real : ");
			fgets(line, sizeof(line), stdin);
			line[strlen(line)-1] = '\0';
			if (line[0] == 35) /* # to enter opcode */
			{
				opcode = line[1];
				printf(" %c \n",opcode);
				break;
			}

			else
			{
				if (line[0] > 44 && line[0] < 58)
				{
					sscanf(line, "%f", &real);
					printf(" %.3f \n", real);
				}
		
				printf("Enter Imag : ");
				fgets(line, sizeof(line), stdin);
				line[strlen(line)-1] = '\0';
		
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
		
				z_stack[a] = make_z(real, im);
		
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
				result = rect_to_polar(z_stack[0]);
				polar_flag = 1;
				drop_flag = 0;
				break;
			case 'q':
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
				z_stack[x]->sign_zre[0] = result->sign_zre[0];
				z_stack[x]->sign_zim[0] = '@';	
				z_stack[x]->abs_zre = result->abs_zre;
				z_stack[x]->abs_zim = result->abs_zim;

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
		
		}
		else
		{
			if(!polar_flag)
			{
				z_stack[0]->sign_zre[0] = result->sign_zre[0];
				z_stack[0]->sign_zim[0] = result->sign_zim[0];	
				z_stack[0]->abs_zre = result->abs_zre;
				z_stack[0]->abs_zim = result->abs_zim;
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
    	printf("z_stack[%d]\t%c%.3f %c%.3f j \n", 
			x,
			p[x]->sign_zre[0], p[x]->abs_zre,
			p[x]->sign_zim[0], p[x]->abs_zim);
	}
}


