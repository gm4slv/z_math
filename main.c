#include "defs.h"


int main()
{
	
	float z1_re; /*  these are the signed real & imaginary parts    */
	float z1_im; /*  made by reference to the z->sign... char       */
	float z2_re; /*  multiplying the z->abs_xxx by -1 when the      */
	float z2_im; /*  sign member character  is '-'                  */

	float result_re;  /* these are the signed real and */
	float result_im;  /* imaginary parts of the result which will be */
					  /* passed to make_z() to create a result struct */
	
	/* create pointers to the structs for the operands */
	z1 = make_z(-3,-4);
	z2 = make_z(3,4);

	/* send the two pointers-to-structs to the add_z() function */

	result = add_z(z1,z2);	


	/* print the struct->members */

	printf("Z1 = %c%.2f %cj%.2f\n", z1->sign_zre[0], z1->abs_zre, z1->sign_zim[0], z1->abs_zim); 
	printf("Z2 = %c%.2f %cj%.2f\n", z2->sign_zre[0], z2->abs_zre, z2->sign_zim[0], z2->abs_zim); 
	printf("Z1 + Z2 = %c%.2f %cj%.2f\n", result->sign_zre[0], result->abs_zre, result->sign_zim[0], result->abs_zim); 
	return(0);
}


struct complex_number *make_z(float in_re, float in_im)
{

	struct complex_number *z_ptr;

	char sign_re[1];
	char sign_im[1];

	printf("in make_z()\n");

	z_ptr=(struct complex_number *)malloc(sizeof(struct complex_number) * 1);
	
	if ( z_ptr == NULL)
	{
		puts("Malloc() error");
		exit(1);
	}

	if (in_re < 0)
	{
		sign_re[0] = '-';
		in_re = in_re * -1;
	}
	else
	{
		sign_re[0] = '+';
		
	}

	if (in_im < 0)
	{
		sign_im[0] = '-';
		in_im = in_im * -1;
	}
	else
	{
		sign_im[0] = '+';
	
	}
	
	z_ptr->sign_zre[0] = sign_re[0];
	z_ptr->sign_zim[0] = sign_im[0];
	z_ptr->abs_zre = in_re;
	z_ptr->abs_zim = in_im;

	return (z_ptr);
}


struct complex_number *add_z(struct complex_number *z1, struct complex_number *z2)
{
	float result_re;
	float result_im;
	float z1_re; /*  these are the signed real & imaginary parts    */
	float z1_im; /*  made by reference to the z->sign... char       */
	float z2_re; /*  multiplying the z->abs_xxx by -1 when the      */
	float z2_im; /*  sign member character  is '-'                  */
	
   printf("IN ADD_Z()\n");	
	
	/*  make the signed version of real & imaginary parts
         *  of z1 and z1 to allow the calculation to be made */

        /* real parts */
        if( z1->sign_zre[0] == '-')
        {
                z1_re = z1->abs_zre * -1;
        }
        else
        {
                z1_re = z1->abs_zre;
        }

        if( z2->sign_zre[0] == '-')
        {
                z2_re = z2->abs_zre * -1;
        }
        else
        {
                z2_re = z2->abs_zre;
        }

        /* Imaginary parts */

        if( z1->sign_zim[0] == '-')
        {
                z1_im = z1->abs_zim * -1;
        }
        else
        {
                z1_im = z1->abs_zim;
        }
        if( z2->sign_zim[0] == '-')
        {
                z2_im = z2->abs_zim * -1;
        }
        else
        {
                z2_im = z2->abs_zim;
        }

 /* calculate the real and imaginary result */
        result_re = z1_re + z2_re;
        result_im = z1_im + z2_im;

        /* send the real and imaginary results to 
         * make_z() and assign the returned pointer
         * to the result struct */

        result = make_z(result_re, result_im);

	return(result);
}

