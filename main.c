#include "defs.h"


int main()
{

	struct complex_number *z1;
	struct complex_number *z2;

	struct complex_number *result;	


	/* get user input of 2 complex numbers */
	
	
	/* printing results requires passing a "function ID digit" to 
	 * select appropriate print format
	 *
	 * printing is done from the input_output.c module
	 *
	 * the IDs are:
	 * 	*0 = addition
	 * 	*1 = subtraction
	 *  *2 = multiplication
	 *  *3 = division
	 *  4 = invert
	 *  5 = rect-polar convert
	 *  6 = polar-rect convert
	 *
	 * *0,2,3,4 are redundant - the same print routine is used for
	 * all of these. 
	 *
	 *  4,5,6 are used in an if() statement to select appropriate printf format
	 *
	 * 	A switch might be a better choice than a chain of if...else if....else
	 *
	 */
	 
	
	
	/* Give the menu */
	int choice='\0';

	while( choice != 'Q' )
	{
		choice=menu();		/* menu() is in input_output.c */
		switch (choice)
		{
			case 'A':
				z1 = get_z1();
				z2 = get_z2();
				print_dual_operands(z1,z2);
				result = add_z(z1,z2);
				print_result(0,result);
				free(z1);
				free(z2);
				free(result);
				break;
			case 'S':
				z1 = get_z1();
				z2 = get_z2();
				print_dual_operands(z1,z2);
				result = subtract_z(z1,z2);
				print_result(1,result);
				free(z1);
				free(z2);
				free(result);
				break;
			case 'M':
				z1 = get_z1();
				z2 = get_z2();
				print_dual_operands(z1,z2);
				result = multiply_z(z1,z2);
				print_result(2,result);
				free(z1);
				free(z2);
				free(result);
				break;
			case 'D':
				z1 = get_z1();
				z2 = get_z2();
				print_dual_operands(z1,z2);
				result = divide2_z(z1,z2); /* using the simplified divide funtion */
				printf("\nUsing divide2_z()\n");
				print_result(3,result);
				free(z1);
				free(z2);
				free(result);
				break;
			case 'I':
				z1 = get_z1();
				result = invert_z(z1);
				print_single_operand(z1);
				print_result(4,result);
				free(z1);
				free(result);
				break;
			case 'P':
				z1 = get_z1();
				result = rect_to_polar(z1);
				print_single_operand(z1);
				print_result(5,result);
				free(z1);
				free(result);
				break;
			case 'R':
				z1 = get_z1_polar();
				result = polar_to_rect(z1);
				print_polar_operand(z1);
				print_result(6,result);
				free(z1);
				free(result);
				break;
			case 'C': /* complex conjugate */
				z1 = get_z1();
				result = conjugate_z(z1);
				print_single_operand(z1);
				print_result(7,result);
				free(z1);
				free(result);
				break;
			case '.': 
				z1 = get_z1();
				z2 = get_z2();
				print_dual_operands(z1,z2);
				result = dot_product(z1,z2);
				print_result(8,result);
				free(z1);
				free(z2);
				free(result);
				break;
			case 'X': 
				z1 = get_z1();
				z2 = get_z2();
				print_dual_operands(z1,z2);
				result = cross_product(z1,z2);
				print_result(9,result);
				free(z1);
				free(z2);
				free(result);
				break;
			case 'U': 
				z1 = get_z1();
				result = uvec_z(z1);
				print_single_operand(z1);
				print_result(10,result);
				free(z1);
				free(result);
				break;
			}
	}

	return(0);
}



