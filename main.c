#include "defs.h"


int main()
{

	struct complex_number *z1;
	struct complex_number *z2;

	struct complex_number *result;	

	/* get user input of 2 complex numbers */

	/* Give the menu */
	int choice='\0';

	while( choice != 'Q' )
	{
		choice=menu();
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
			}
	}
/* free the malloc'd storage 
	free(z1);
	free(z2);
	free(result);
*/

	return(0);
}



