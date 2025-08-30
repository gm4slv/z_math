#include "defs.h"

/*************************************************
 *
 * the main() function for zcalc
 *
 * this simply handles the choice of calculation type
 * from the user and uses a switch-case to call the 
 * necessary functions to perform the calculation and 
 * then display the results.
 *
 * complex numbers are stored in structs of type
 *
 * struct  complex_number {};
 *
 * pointers are used to access the structs.
 *
 * a struct has 4 members and is of the format:
 *
 * struct complex_number {
 *	char sign_zre[1];
 *	char sign_zim[1];
 *	float abs_zre;
 *	float abs_zim;
 *	};
 *
 *  a pointer is obtained on creation of each complex number
 *  and this can be passed to various functions to perform
 *  calculations. 
 *
 *  The functions also return a complex_number
 *  pointer to the result struct, and this is passed to 
 *  the print function for display.
 *
 *  To allow different format of result display the print_result()
 *  function also takes a char defining the type of caclulation
 *  (e.g (A)dd, (S)ubtract etc)
 *	
 *	the complex_number structs must be cleared up with free()
 *	once they've been printed. 
 *
 **/

int main()
{

	struct complex_number *z1; /* pointer to struct holding operand 1 */
	struct complex_number *z2; /* poitner to struct holding operand 2 */

	struct complex_number *result;	/* pointer to struct holding result */


	/* get user input of a calculation type and up to 2 complex numbers */

	/* printing results requires passing the function ID to 
	 * select appropriate print format
	 *
	 * all printing is done from the input_output.c module
	 *
	 * the IDs is passed using the same choice character
	 * the is chosed by the user
	 *
	 */
	 
	
	int choice='\0'; /* holds the char selected by the user to 
						request a specific calculation. 
						A character is used (at present)
						but we use an int to hold it. Set it
						to "null character" to start */

	while( choice != 'Q' )
	{
		choice=menu();						/* menu() is in input_output.c */
		switch (choice)
		{
			case 'A':
				z1 = get_z1();				/* get_z funtions are in input_output.c */
				z2 = get_z2();				/* get_z() itself calls make_z() which is in*/
											/* z_math.c */

				print_dual_operands(z1,z2);	/* print functions are in input_output.c */

				result = add_z(z1,z2);		/* math functions are in z_math.c */
				
				print_result(choice,result);
				
				free(z1);					/* complex_number structs created here */
				free(z2);					/* must be cleaned up using free() */
				free(result);				/* from here.*/
				break;

			case 'S':
				z1 = get_z1();
				z2 = get_z2();
				print_dual_operands(z1,z2);
				result = subtract_z(z1,z2);
				print_result(choice,result);
				free(z1);
				free(z2);
				free(result);
				break;

			case 'M':
				z1 = get_z1();
				z2 = get_z2();
				print_dual_operands(z1,z2);
				result = multiply_z(z1,z2);
				print_result(choice,result);
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
				print_result(choice,result);
				free(z1);
				free(z2);
				free(result);
				break;

			case 'I':
				z1 = get_z1();
				result = invert_z(z1);
				print_single_operand(z1);
				print_result(choice,result);
				free(z1);
				free(result);
				break;

			case 'P':
				z1 = get_z1();
				result = rect_to_polar(z1);
				print_single_operand(z1);
				print_result(choice,result);
				free(z1);
				free(result);
				break;

			case 'R':
				z1 = get_z1_polar();
				result = polar_to_rect(z1);
				print_polar_operand(z1);
				print_result(choice,result);
				free(z1);
				free(result);
				break;

			case 'C': /* complex conjugate */
				z1 = get_z1();
				result = conjugate_z(z1);
				print_single_operand(z1);
				print_result(choice,result);
				free(z1);
				free(result);
				break;

			case 'T': 
				z1 = get_z1();
				z2 = get_z2();
				print_dual_operands(z1,z2);
				result = dot_product(z1,z2);
				print_result(choice,result);
				free(z1);
				free(z2);
				free(result);
				break;

			case 'O': 
				z1 = get_z1();
				z2 = get_z2();
				print_dual_operands(z1,z2);
				result = cross_product(z1,z2);
				print_result(choice,result);
				free(z1);
				free(z2);
				free(result);
				break;

			case 'U': 
				z1 = get_z1();
				result = uvec_z(z1);
				print_single_operand(z1);
				print_result(choice,result);
				free(z1);
				free(result);
				break;

			case 'B': 
				z1 = get_z1();
				result = rect_to_polar(z1);
				print_single_operand(z1);
				print_result(choice,result);
				free(z1);
				free(result);
				break;

			case 'G': 
				z1 = get_z1();
				result = rect_to_polar(z1);
				print_single_operand(z1);
				print_result(choice,result);
				free(z1);
				free(result);
				break;

			}
	}

	return(0);
}



