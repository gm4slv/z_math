#include "defs.h"

/*****************************************************
 *
 * input_output module to handle
 * 1) display the menu
 * 2) ask for user input of operands after a choice of
 *    calculation has been made
 * 3) display operand(s) entered by the user
 * 4) display result in a format specific to the
 * 	  calculation being performed
 *
 ******************************************************/


/* ask for real & imaginary parts and return a pointer to 
 * the complex_number struct thus created */
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

/* for converting from Polar to Rect
 * ask for magnitude and angle instead of
 * real and imaginary.
 * They are still stored as "zre" and "zim" in the
 * complex_number struct thus created */
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

/* for two operand calculations:
 * ask for second re & imag parts and return a pointer to 
 * the complex_number struct thus created */
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


/* when a calculation has TWO complex operands we print them using this */
void print_dual_operands(struct complex_number *z1, struct complex_number *z2)
{

	printf("\nZ1 = %c%.2f %c j%.2f\n",
		   	z1->sign_zre[0], z1->abs_zre, z1->sign_zim[0], z1->abs_zim); 
	printf("Z2 = %c%.2f %c j%.2f\n\n",
		   	z2->sign_zre[0], z2->abs_zre, z2->sign_zim[0], z2->abs_zim); 
}

/* when the calculation has only ONE complex number we print it using this */
void print_single_operand(struct complex_number *z1)
{

	printf("\nZ1 = %c%.2f %c j%.2f\n\n",
		   	z1->sign_zre[0], z1->abs_zre, z1->sign_zim[0], z1->abs_zim); 
}

/* if the operation is polar > Rect  we print the operands using this */
void print_polar_operand(struct complex_number *z1)
{

	printf("\nZ1 = %.2f < %c%.2f degrees\n\n",
		   	 z1->abs_zre, z1->sign_zim[0],z1->abs_zim); 
}


/* a big switch-case selection to display the result  each different type of
 * calculation in a specific format */
void print_result(char r, struct complex_number *result)
{
	char sign[1];  /* this is for the Polar angle sign 
					  to suppress a + in positive angles */

	printf("==================================================\n\n");
	
	
	switch(r)
	{
		case 'G': /* arGument */
			printf("\n\tArg (angle) <Z1 = %c%.3f degrees \n\n", 
				result->sign_zim[0],result->abs_zim);
			break;

		case 'B': /* aBs */
			printf("\n\tAbs (mag)  |Z1| = %.3f \n\n", 
				result->abs_zre);
			break;

		case 'U': /*Uvec */
			printf("\n\tUvec = %c%.3f %c j%.3f \n\n", 
				result->sign_zre[0], result->abs_zre, 
				result->sign_zim[0], result->abs_zim);
			break;

		case 'O':  /* crOss product */
			printf("\n\tZ1 x Z2 = %c%.3f \n\n", 
				result->sign_zre[0], result->abs_zre);
			break;

		case 'T': /* doT product */
			printf("\n\tZ1 . Z2 = %c%.3f \n\n", 
				result->sign_zre[0], result->abs_zre);
			break;

		case 'C': /* complex Conjugate */
			printf("\n\tZ1* = %c%.3f %c j%.3f\n\n", 
				result->sign_zre[0], result->abs_zre, 
				result->sign_zim[0],result->abs_zim);
			break;

		case 'I': /* Inverse */
			printf("\n\t1 / Z1 = %c%.3f %c j%.3f\n\n", 
				result->sign_zre[0], result->abs_zre, 
				result->sign_zim[0],result->abs_zim);
			break;

		case 'P': /* rect > Polar */
			printf("Converted to polar\n");
			if (result->sign_zim[0] == '-')
				sign[0] = result->sign_zim[0];
			else
				sign[0] = ' ';
			printf("\n\tMag < angle = %.3f < %c%.3f degrees\n\n", 
				result->abs_zre,sign[0],result->abs_zim);
			break;

		case  'R': /* polar > Rect */
			printf("Converted to rectangular\n");
			printf("\n\tZ1 = %c%.3f %c j%.3f\n\n", 
				result->sign_zre[0], result->abs_zre, 
				result->sign_zim[0], result->abs_zim);
			break;

		case 'D': /* Divide */
			printf("\n\tZ1 / Z2 = %c%.3f %c j%.3f\n\n", 
				result->sign_zre[0], result->abs_zre, 
				result->sign_zim[0], result->abs_zim);
		   	break;

		case 'M': /* Multiply */
			printf("\n\tZ1 * Z2 = %c%.3f %c j%.3f\n\n", 
				result->sign_zre[0], result->abs_zre, 
				result->sign_zim[0], result->abs_zim);
		   	break;

		case 'S': /* Subtract */
			printf("\n\tZ1 - Z2 = %c%.3f %c j%.3f\n\n", 
				result->sign_zre[0], result->abs_zre, 
				result->sign_zim[0], result->abs_zim); 
			break;

		case 'A': /* Add */
			printf("\n\tZ1 + Z2 = %c%.3f %c j%.3f\n\n", 
				result->sign_zre[0], result->abs_zre, 
				result->sign_zim[0], result->abs_zim);
			break;

		default:  /* this shouldn't appear */
			printf("No Results\n");

	}
	printf("\n==================================================\n\n");

}


int menu(void)
{
	int ch;

	printf("\nA)dd\t\tS)ubtract\tM)ultiply\tD)ivide\n\n");
	printf("I)nverse\tC)onjugate\n\n");
	printf("doT)\t\tcrO)ss\t\tU)vec\n\n");
	printf("Rect > P)olar\tPolar > R)ect\taB)s\t\tarG)\n\n");
	printf("Q)uit\n\nEnter Choice : ");

	ch=getchar();
	while(getchar()!='\n')
		;
	return(toupper(ch));
}

