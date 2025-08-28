#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* a struct that holds a complex number in 
 * a form that separates the sign of each part from 
 * the absolute value. This makes display 
 * easier, but means some if/else decisions are needed
 * to perform calculations.*/
struct complex_number {
	char sign_zre[1];
	char sign_zim[1];
	float abs_zre;
	float abs_zim;
};

/* declare complex number struct pointers to hold the operands z1 and z1
 * and to hold the result of z1[+|-|*|/]z2 */
/* struct complex_number *z1; */
/* struct complex_number *z2; */
/*struct complex_number *result;*/

/*********************************************
 * function prototypes                       *
 *
 * *******************************************/

int menu(void);
struct complex_number *get_z1(void);
struct complex_number *get_z2(void);
void print_2operands(struct complex_number *z1, struct complex_number *z2);
void print_1operand(struct complex_number *z1);
void print_result(int,  struct complex_number *result);

/* a function to create the struct (pointer) when given the 
 * real and imaginary parts of a complex number */
struct complex_number *make_z(float zre, float zim);

/* a funtion to add two complex numbers and put the result into 
 * result struct */
struct complex_number *add_z(struct complex_number *z1, struct complex_number *z2);
/* function to subtract two complex numbers */
struct complex_number *subtract_z(struct complex_number *z1, struct complex_number *z2);
/* function to calculate the inverse of a complex number */
struct complex_number *invert_z(struct complex_number *z1);
/* function to multiply 2 complex numbers */
struct complex_number *multiply_z(struct complex_number *z1, struct complex_number *z2);
/* function to multiply 2 complex numbers */
struct complex_number *divide_z(struct complex_number *z1, struct complex_number *z2);
struct complex_number *divide2_z(struct complex_number *z1, struct complex_number *z2);


