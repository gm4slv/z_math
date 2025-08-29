#include <stdio.h>
#include <math.h>

int main()
{

   	const float PI = 3.14159265359;

	float zre;
	float zim;
	float angle;


	zre = 1;
	zim = 1;
	printf("1st quadrant zre=%.3f zim=%.3f\n", zre, zim);

	angle = 180 * atan(zim/zre) / PI;
	
	printf("angle = %.3f\n", angle);



	zre = -1;
	zim = 1;
	printf("2nd quadrant zre=%.3f zim=%.3f\n", zre, zim);

	angle = 180 * atan(zim/zre) / PI;
	
	printf("angle = %.3f\n", angle);



	zre = -1;
	zim = -1;
	printf("3rd quadrant zre=%.3f zim=%.3f\n", zre, zim);

	angle = 180 * atan(zim/zre) / PI;
	
	printf("angle = %.3f\n", angle);



	zre = 1;
	zim = -1;
	printf("4th quadrant zre=%.3f zim=%.3f\n", zre, zim);

	angle = 180 * atan(zim/zre) / PI;
	
	printf("angle = %.3f\n", angle);


	return(0);
}
