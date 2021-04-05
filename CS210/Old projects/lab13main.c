/** lab13.c
* ===========================================================
* Name: Name, Date
* Section:
* Project:
* Purpose:
* ===========================================================
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "lab13functs.h"
int main(void) {
	int classYear;
	int favNum;

	printf("Please enter your class year:\n");
	scanf("%d", &classYear);
	printf("Please enter your favorite number:\n");
	scanf("%d", &favNum);
	swapPassByValue(&classYear, &favNum);
	printf("aNum = %d, bNum = %d\n", classYear, favNum);

	swapPassByReference(&classYear, &favNum);
	printf("aNum = %d, bNum = %d\n", classYear, favNum);

	int a, b;
	printf("Please enter two numbers seperated by a space:\n");
	scanf("%d %d", &a, &b);
	int value = pointerSum(&a, &b);
	printf("The sum of %d and %d = %d\n", a, b, value);

	int x;
	long int y;
	printf("Please enter and integer:\n");
	scanf("%d", &x);
	findFactorial(x, &y);
	printf("The factorial of %d is %ld", x, y);
}