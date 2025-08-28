#include "defs.h"




struct complex_number *get_z1(void)
{
	char line[20];
	float z1_in_re;
	float z1_in_im;
	struct complex_number *z1in;

	printf("\nEnter Z1 real\t\t: ");
	fgets(line, sizeof(line), stdin);

	if(line[0] == '\n')
	{
		z1_in_re = 0;
	}
	else
	{
		sscanf(line, "%f ", &z1_in_re);
	}
	
	printf("\nEnter Z1 imaginary \t: ");
	fgets(line, sizeof(line), stdin);

	if(line[0] == '\n')
	{
		z1_in_im = 0;
	}
	else
	{
		sscanf(line, "%f ", &z1_in_im);
	}

	z1in = make_z(z1_in_re,z1_in_im);
	return(z1in);
}

struct complex_number *get_z1_polar(void)
{
	char line[20];
	float z1_in_re;
	float z1_in_im;
	struct complex_number *z1in;

	printf("\nEnter Z1 Magnitude \t: ");
	fgets(line, sizeof(line), stdin);

	if(line[0] == '\n')
	{
		z1_in_re = 0;
	}
	else
	{
		sscanf(line, "%f ", &z1_in_re);
	}
	
	printf("\nEnter Z1 Angle \t: ");
	fgets(line, sizeof(line), stdin);

	if(line[0] == '\n')
	{
		z1_in_im = 0;
	}
	else
	{
		sscanf(line, "%f ", &z1_in_im);
	}

	z1in = make_z(z1_in_re,z1_in_im);
	return(z1in);
}

struct complex_number *get_z2(void)
{
	char line[20];

	float z2_in_re;
	float z2_in_im;
	struct complex_number *z2in;
	
	printf("\nEnter Z2 real\t\t: ");
	fgets(line, sizeof(line), stdin);
	
	if(line[0] == '\n')
	{
		z2_in_re = 0;
	}
	else
	{
		sscanf(line, "%f ", &z2_in_re);
	}
	

	printf("\nEnter Z2 imaginary \t: ");
	fgets(line, sizeof(line), stdin);
	
	if(line[0] == '\n')
	{
		z2_in_im = 0;
	}
	else
	{
		sscanf(line, "%f ", &z2_in_im);
	}

	z2in = make_z(z2_in_re,z2_in_im);
	return(z2in);
}


	/* send the two pointers-to-structs to the add_z() function */
	/* and recieve pointer to the result struct */

	/* result = add_z(z1,z2); */	


	/* print the struct->members */

void print_dual_operands(struct complex_number *z1, struct complex_number *z2)
{

	printf("\nZ1 = %c%.2f %c j%.2f\n",
		   	z1->sign_zre[0], z1->abs_zre, z1->sign_zim[0], z1->abs_zim); 
	printf("Z2 = %c%.2f %c j%.2f\n",
		   	z2->sign_zre[0], z2->abs_zre, z2->sign_zim[0], z2->abs_zim); 
}
	/* print the struct->members */

void print_single_operand(struct complex_number *z1)
{

	printf("\nZ1 = %c%.2f %c j%.2f\n",
		   	z1->sign_zre[0], z1->abs_zre, z1->sign_zim[0], z1->abs_zim); 
}

void print_polar_operand(struct complex_number *z1)
{

	printf("\nZ1 = %.2f < %.2f degrees\n",
		   	 z1->abs_zre, z1->abs_zim); 
}


/***************************************************************
 *
 *	this prints the results and is dependant on what
 *	function was preformed to decide how to format the
 *	print.
 *
 *	IT MIGHT BE A CANDIDATE FOR A SWITCH function?
 *	
 ***************************************************************/

void print_result(int r, struct complex_number *result)
{
	char function[] = {'+', '-', '*', '/'}; 
	if(r == 4)
	{
		printf("\n 1 / Z1 =%c%.3f %c j%.3f\n\n", 
				result->sign_zre[0], result->abs_zre, 
				result->sign_zim[0],result->abs_zim);
	}
	else if (r == 5)
	{
		printf("Converted to polar\n");
		printf("\n Mag < angle = %.3f < %.3f degrees\n\n", 
				result->abs_zre,result->abs_zim);
	}
	else if( r == 6)
	{
		printf("Converted to rectangular\n");
		printf("\n Z1 = %c%.3f %c j%.3f\n\n", 
				result->sign_zre[0], result->abs_zre, 
				result->sign_zim[0], result->abs_zim);
	}

	else 
	{	
		printf("\nZ1 %c Z2 = %c%.3f %c j%.3f\n\n", 
				function[r], result->sign_zre[0], result->abs_zre, 
				result->sign_zim[0], result->abs_zim); 
	}
}


int menu(void)
{
	int ch;

	printf("A)dd, S)ubtract, M)ultiply, D)ivide, I)nverse, r->P)olar, p->R)ect, Q)uit: ");

	ch=getchar();
	while(getchar()!='\n')
		;
	return(toupper(ch));
}

