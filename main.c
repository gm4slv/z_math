#include "defs.h"


int main()
{

	struct complex_number *z1;
	struct complex_number *z2;

	struct complex_number *result;	

	/* get user input of 2 complex numbers */

	/* Give the menu */
	int choice='\0';

	while(choice!='q')
	{
		choice=menu();
		switch (choice)
		{
			case 'A':
			case 'a':
				z1 = get_z1();
				z2 = get_z2();
				print_operands(z1,z2);
				result=add_z(z1,z2);
				print_result(0,result);
				break;
			case 'S':
			case 's':
				z1 = get_z1();
				z2 = get_z2();
				print_operands(z1,z2);
				result=subtract_z(z1,z2);
				print_result(1,result);
				break;

			}
	}
	/* free the malloc'd storage */
	free(z1);
	free(z2);
	free(result);

	return(0);
}


struct complex_number *get_z1(void)
{
	char line[20];
	float z1_in_re;
	float z1_in_im;
	struct complex_number *z1in;

	printf("\nEnter Z1 : real imag : ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f %f", &z1_in_re, &z1_in_im);
	z1in = make_z(z1_in_re,z1_in_im);
	return(z1in);
}

struct complex_number *get_z2(void)
{
	char line[20];

	float z2_in_re;
	float z2_in_im;
	struct complex_number *z2in;

	printf("\nEnter Z2 : real imag : ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f %f", &z2_in_re, &z2_in_im);

	z2in = make_z(z2_in_re,z2_in_im);
	return(z2in);
}


	/* send the two pointers-to-structs to the add_z() function */
	/* and recieve pointer to the result struct */

	/* result = add_z(z1,z2); */	


	/* print the struct->members */

void print_operands(struct complex_number *z1, struct complex_number *z2)
{

	printf("\nZ1 = %c%.2f %cj%.2f\n",
		   	z1->sign_zre[0], z1->abs_zre, z1->sign_zim[0], z1->abs_zim); 
	printf("Z2 = %c%.2f %cj%.2f\n",
		   	z2->sign_zre[0], z2->abs_zre, z2->sign_zim[0], z2->abs_zim); 
}
void print_result(int r, struct complex_number *result)
{
	char function[] = {'+', '-'}; 

	printf("\nZ1 %c Z2 = %c%.2f %cj%.2f\n\n", function[r],
			result->sign_zre[0], result->abs_zre, result->sign_zim[0], result->abs_zim); 
}


int menu(void)
{
	int ch;

	printf("A)dd, S)ubtract, I)nverse, Q)uit: ");

	ch=getchar();
	while(getchar()!='\n')
		;
	return(ch);
}

