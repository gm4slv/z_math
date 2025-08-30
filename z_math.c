#include "defs.h"


const float PI = 3.14159265359;

struct complex_number *make_z(float in_re, float in_im)
{


	struct complex_number *z_ptr;

	char sign_re[1];
	char sign_im[1];

	z_ptr=(struct complex_number *)malloc(sizeof(struct complex_number) * 1);
	
	if ( z_ptr == NULL)
	{
		puts("Malloc() error");
		exit(1);
	}

	/* we store the absolute value of real & imaginary along with the 
	 * char representing the sign. */
	if (in_re < 0)
	{
		sign_re[0] = '-';
		in_re = in_re * -1;
	}
	else
	{
		sign_re[0] = ' ';
		
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
	
	/* we are p assing the struct members using pointer notation
	 * with the values and char (for sign) before returning the
	 * pointer for the location of the filled-in-with-data struct */

	z_ptr->sign_zre[0] = sign_re[0];
	z_ptr->sign_zim[0] = sign_im[0];
	z_ptr->abs_zre = in_re;
	z_ptr->abs_zim = in_im;

	return (z_ptr);
}


struct complex_number *add_z(struct complex_number *z1, struct complex_number *z2)
{
	struct complex_number *result_ptr;
	float result_re;
	float result_im;
	float z1_re; /*  these are the signed real & imaginary parts    */
	float z1_im; /*  made by reference to the z->sign... char       */
	float z2_re; /*  multiplying the z->abs_xxx by -1 when the      */
	float z2_im; /*  sign member character  is '-'                  */
	
	
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

        result_ptr = make_z(result_re, result_im);

	return(result_ptr);
}

struct complex_number *subtract_z(struct complex_number *z1, struct complex_number *z2)
{
	struct complex_number *result_ptr;
	float result_re;
	float result_im;
	float z1_re; /*  these are the signed real & imaginary parts    */
	float z1_im; /*  made by reference to the z->sign... char       */
	float z2_re; /*  multiplying the z->abs_xxx by -1 when the      */
	float z2_im; /*  sign member character  is '-'                  */
	
	
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
        result_re = z1_re - z2_re;
        result_im = z1_im - z2_im;

        /* send the real and imaginary results to 
         * make_z() and assign the returned pointer
         * to the result struct */

        result_ptr = make_z(result_re, result_im);

	return(result_ptr);
}

struct complex_number *multiply_z(struct complex_number *z1, struct complex_number *z2)
{
	struct complex_number *result_ptr;
	float result_re;
	float result_im;
	float z1_re; /*  these are the signed real & imaginary parts    */
	float z1_im; /*  made by reference to the z->sign... char       */
	float z2_re; /*  multiplying the z->abs_xxx by -1 when the      */
	float z2_im; /*  sign member character  is '-'                  */
	
	
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
        
		result_re = ((z1_re * z2_re) - (z1_im * z2_im));


        result_im = ((z1_re * z2_im) + (z1_im * z2_re));

        /* send the real and imaginary results to 
         * make_z() and assign the returned pointer
         * to the result struct */

        result_ptr = make_z(result_re, result_im);

	return(result_ptr);
}


/* this caclulates the division using the input numbers 
 * and using their real & imaginary  parts
 *
 * there is a simpler funtion divide2_z() which uses existing
 * invert_z and multiply_z instead
 *
 *  which is better? */
struct complex_number *divide_z(struct complex_number *z1, struct complex_number *z2)
{
	struct complex_number *result_ptr;
	float result_re;
	float result_im;
	float z1_re; /*  these are the signed real & imaginary parts    */
	float z1_im; /*  made by reference to the z->sign... char       */
	float z2_re; /*  multiplying the z->abs_xxx by -1 when the      */
	float z2_im; /*  sign member character  is '-'                  */

	
	
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
        
		result_re = ((z1_re * z2_re)/(z2_re*z2_re + z2_im*z2_im) 
				+ (z1_im * z2_im)/(z2_re*z2_re + z2_im*z2_im));

		result_im = ((z1_im * z2_re)/(z2_re*z2_re + z2_im*z2_im) 
				- (z1_re * z2_im)/(z2_re*z2_re + z2_im*z2_im));


        /* send the real and imaginary results to 
         * make_z() and assign the returned pointer
         * to the result struct */

        result_ptr = make_z(result_re, result_im);

	return(result_ptr);
}



/* this is a simplified divide funtion that uses the existing
 * invert_z and multiply_z functions 
 *
 * this might become the default divide_z() function  */

struct complex_number *divide2_z(struct complex_number *z1, struct complex_number *z2)
{
	struct complex_number *result_ptr;
	struct complex_number *z3;

	z3 = invert_z(z2);
	

	result_ptr = multiply_z(z1,z3);
	
        /* send the real and imaginary results to 
         * make_z() and assign the returned pointer
         * to the result struct */

      /*  result_ptr = make_z(result_re, result_im); */
	free(z3);

	return(result_ptr);
}



struct complex_number *invert_z(struct complex_number *z1)
{
	struct complex_number *result_ptr;
	float result_re;
	float result_im;
	float z1_re; /*  these are the signed real & imaginary parts    */
	float z1_im; /*  made by reference to the z->sign... char       */
	
	
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


        /* Imaginary parts */

        if( z1->sign_zim[0] == '-')
        {
                z1_im = z1->abs_zim;
        }
        else
        {
                z1_im = z1->abs_zim * -1;
        }

 /* calculate the real and imaginary result */
        result_re = (z1_re / (z1_re * z1_re + z1_im * z1_im) ) ;
        result_im = ( z1_im /( z1_re * z1_re + z1_im * z1_im)) ;

        /* send the real and imaginary results to 
         * make_z() and assign the returned pointer
         * to the result struct */
        result_ptr = make_z(result_re, result_im);

	return(result_ptr);
}

struct complex_number *rect_to_polar(struct complex_number *z1)
{
	struct complex_number *result_ptr;
	float result_re;
	float result_im;
	float z1_re; /*  these are the signed real & imaginary parts    */
	float z1_im; /*  made by reference to the z->sign... char       */
	
	
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


        /* Imaginary parts */

        if( z1->sign_zim[0] == '-')
        {
                z1_im = z1->abs_zim * -1;
        }
        else
        {
                z1_im = z1->abs_zim;
        }

 		/* THIS IS NOT FULLY CORRECT---- NEED TO ACCOUNT FOR
		 * OTHER QUADRANTS WHERE parts are negative
		 * THE SQRT function can't handle these properly
		 *
		 */

        result_re = sqrt((z1_re * z1_re ) + (z1_im * z1_im)) ;
        result_im = 180 * atan(z1_im / z1_re) / PI;
		
		/* work out the quadrant */

		if ( z1_re >= 0 && z1_im < 0 )
		{
			result_im = result_im ;
		}
		else if  ( z1_re < 0 && z1_im < 0 ) /* 3rd quadrant */
		{
			result_im = result_im - 180;
		}
		else if( z1_re < 0 && z1_im >= 0) /* 2nd quadrant */
		{
			result_im = result_im + 180;
		}
		else
		{
		;
		}


        /* send the real and imaginary results to 
         * make_z() and assign the returned pointer
         * to the result struct */
        result_ptr = make_z(result_re, result_im);

	return(result_ptr);
}


struct complex_number *polar_to_rect(struct complex_number *z1)
{
	struct complex_number *result_ptr;
	float angle_rad;
	float result_re;
	float result_im;
	float z1_re; /*  these are the signed real & imaginary parts    */
	float z1_im; /*  made by reference to the z->sign... char       */
	
	
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


        /* Imaginary parts */

        if( z1->sign_zim[0] == '-')
        {
                z1_im = z1->abs_zim * -1;
        }
        else
        {
                z1_im = z1->abs_zim;
        }

        
		angle_rad = 2*PI * z1_im / 360;

		result_re = z1_re * cos(angle_rad);
        result_im = z1_re * sin(angle_rad);

        /* send the real and imaginary results to 
         * make_z() and assign the returned pointer
         * to the result struct */
        result_ptr = make_z(result_re, result_im);

	return(result_ptr);
}

struct complex_number *conjugate_z(struct complex_number *z1)
{
	struct complex_number *result_ptr;
	float result_re;
	float result_im;
	float z1_re; /*  these are the signed real & imaginary parts    */
	float z1_im; /*  made by reference to the z->sign... char       */
	
	
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


        /* Imaginary parts */

        if( z1->sign_zim[0] == '-')
        {
                z1_im = z1->abs_zim * -1;
        }
        else
        {
                z1_im = z1->abs_zim;
        }

 /* calculate the real and imaginary result */
        result_re = z1_re ;
        result_im = -1 * z1_im ;

        /* send the real and imaginary results to 
         * make_z() and assign the returned pointer
         * to the result struct */
        result_ptr = make_z(result_re, result_im);

	return(result_ptr);
}


struct complex_number *dot_product(struct complex_number *z1, struct complex_number *z2)
{
	struct complex_number *result_ptr;
	struct complex_number *z3;
	
	z3 = conjugate_z(z2);

	result_ptr= multiply_z(z1, z3);

	/* dot product is the Re part... so set Im to zero */

	result_ptr->abs_zim = 0;

	free(z3);

	return(result_ptr);
}

struct complex_number *cross_product(struct complex_number *z1, struct complex_number *z2)
{
	struct complex_number *result_ptr;
	struct complex_number *z3;
	struct complex_number *z4;
	struct complex_number *z5;
	struct complex_number *z6;
	struct complex_number *z7;
	struct complex_number *z8;
	
	z3 = conjugate_z(z1);
	z4 = conjugate_z(z2);
	z5 = make_z(0,2);
	
	z6 = multiply_z(z2,z3);
	z7 = multiply_z(z1,z4);
	z8 = subtract_z(z6, z7);
	
	result_ptr = divide_z(z8, z5);
	
	free(z3);	
	free(z4);
	free(z5);
	free(z6);
	free(z7);
	free(z8);

/*	result_ptr=divide_z(( subtract_z(multiply_z(z2,z3), multiply_z(z1, z4)) ), z5); */

	/* dot product is the Re part... so set Im to zero */

	result_ptr->abs_zim = 0;

	
	return(result_ptr);
}

struct complex_number *uvec_z(struct complex_number *z1)
{
	struct complex_number *result_ptr;
	struct complex_number *z3;
	float z1_re;
	float z1_im;
	float z3_re;
	
	z3 = rect_to_polar(z1);
	
	z3_re = z3->abs_zre;
	
    /* real parts */
    if( z1->sign_zre[0] == '-')
    {
		z1_re = z1->abs_zre * -1;
    }
    else
	{
		z1_re = z1->abs_zre;
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

	z1_re = z1_re / z3_re;
	z1_im = z1_im / z3_re;
	
	result_ptr = make_z(z1_re, z1_im);

	free(z3);

	return(result_ptr);
}




