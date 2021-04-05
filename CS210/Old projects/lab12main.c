// *** file header example *** //
/** labXX.c
* ===========================================================
* Name: Name, Date
* Section:
* Project:
* Purpose:
* ===========================================================
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "lab12functs.h"

int main(void) {
	//Check if Armstrong Number
	int arm;
	printf("Please input an armstrong number:\n");
	scanf("%d", &arm);
	int result = isArmstrong(arm);
	if (result == 1) {
		printf("%d is an Armstrong number.\n", arm);
	}
	else {
		printf("%d is not an Armstrong number.\n", arm);
	}

	//Find Greatest Common Denominator
	int v1, v2;
	printf("Please input two numbers:\n");
	scanf("%d %d", &v1, &v2);
	int gcd = findGCD(v1, v2);
	printf("GCD = %d\n", gcd);

	//Print a Range of Values
	int n1, n2;
	printf("Please input a range:\n");
	scanf("%d %d", &n1, &n2);
	printRange(n1, n2);


}