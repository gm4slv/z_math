#include <stdio.h>
#include <math.h>

int main()
{

   	const float PI = 3.14159265359;

	float angle1 = 30;
	float angle2 = 120;
	float angle3 = 210;
	float angle4 = 300;

	float sin1,sin2,sin3,sin4;
	float arg;

	float real1 = 3;
	float imag1 = 4;
	float real2 = -3;
	float imag2 = 4;
	float real3 = -3;
	float imag3 = -4;
	float real4 = 3;
	float imag4 = -4;
	
	float arg1,arg2,arg3, arg4;

	sin1 = sin(2*PI * angle1 / 360);
	sin2 = sin(2*PI * angle2 / 360);
	sin3 = sin(2*PI * angle3 / 360);
	sin4 = sin(2*PI * angle4 / 360);
	
	printf("angle 1 = %.3f  sin(angle1) = %.4f\n", angle1, sin1);
	printf("angle 2 = %.3f  sin(angle2) = %.4f\n", angle2, sin2);
	printf("angle 3 = %.3f  sin(angle3) = %.4f\n", angle3, sin3);
	printf("angle 4 = %.3f  sin(angle4) = %.4f\n", angle4, sin4);
	
	
	arg1 = 180 * atan(imag1 / real1) / PI;
	arg2 = 180 * atan(imag2 / real2) / PI;
	arg3 = 180 * atan(imag3 / real3) / PI;
	arg4 = 180 * atan(imag4 / real4) / PI;

	printf("Real %.3f, Imag %.3f  arg %.3f\n", real1, imag1, arg1);
	printf("Real %.3f, Imag %.3f  arg %.3f\n", real2, imag2, arg2);
	printf("Real %.3f, Imag %.3f  arg %.3f\n", real3, imag3, arg3);
	printf("Real %.3f, Imag %.3f  arg %.3f\n", real4, imag4, arg4);

	return(0);
}
