// C Program to implement
// structure pointer arrays
#define SIZE 10
#include "defs.h"


void show_stack(struct z_number **p);

int main(void)
{

	int a;
	int i;    
	int p;
	
	struct z_number *z_stack[SIZE];
	
	struct z_number *result;
	
	float real;
	float im;
	
	char opcode;
	int drop_flag;

	char line[20];

    /* Initializing the stack */

	printf("Clearing stack....\n");
	for(i=0;i<SIZE;++i)
	{
		z_stack[i] = make_z(0,0);
	}
	
	show_stack(z_stack);
	
	/*
	printf("\nPrinting from main()\n");
	for(i=0;i<SIZE;++i)
	{
		printf("%c%.3f %c%.3f \n", 
			z_stack[i]->sign_zre[0], z_stack[i]->abs_zre,
			z_stack[i]->sign_zim[0], z_stack[i]->abs_zim);
	}
	*/
	
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
			printf("Entered #.... what do you want to do? \n");
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
		/*
			for (p=SIZE-1;p>=0;--p)
			{
				printf("z_stack[%02d]\t%c%.3f %c j%.3f\n",p,
					z_stack[p]->sign_zre[0], z_stack[p]->abs_zre,
					z_stack[p]->sign_zim[0], z_stack[p]->abs_zim);
			}
		*/
		}
	}	

	switch (opcode)
	{
		case '+':
			printf("Adding \n");
			result = add_z(z_stack[0], z_stack[1]);
			drop_flag = 1;
			break;
		case '-':
			printf("Subtracting \n");
			drop_flag = 1;
			break;
		case '*':
			printf("Multilying \n");
			drop_flag = 1;
			break;
		case '/':
			printf("Dividing \n");
			drop_flag = 1;
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
	
	printf("result %c%f %c%f \n", 
			result->sign_zre[0],result->abs_zre,
			result->sign_zim[0],result->abs_zim);
	real = result->abs_zre;
	im = result->abs_zim;

	free(result);

	if (result-> sign_zre[0] == '-')
		real = -1 * real;
	if (result->sign_zim[0] == '-')
		im = -1 * im;



	if(drop_flag)
	{
		a = 0;
		
		while(a<i)
				{
					z_stack[a] = z_stack[a+1];
					++a;
				}
				z_stack[0] = make_z(real, im);
	
	}
	
	/*
	for (p=SIZE-1;p>=0;--p)
		{
			printf("z_stack[%02d]\t%c%.3f %c j%.3f\n",p,
				z_stack[p]->sign_zre[0], z_stack[p]->abs_zre,
				z_stack[p]->sign_zim[0], z_stack[p]->abs_zim);
		}
	*/			
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
    	printf("z_stack[%d]\t%c% 9.3f %c% 9.3f j \n", 
			x,
			p[x]->sign_zre[0], p[x]->abs_zre,
			p[x]->sign_zim[0], p[x]->abs_zim);
	}
}


