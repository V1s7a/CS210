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
#include "lab11functs.h"



int main(void) {
	int userInt;
	printf("Please enter an integer:\n");
	scanf("%d", &userInt);
	printf("The factorial of %d is %d.\n", userInt, numFactorial(userInt));


	int userPrime;
	int prime;
	printf("Please enter a possible prime number:\n");
	scanf("%d", &userPrime);
	prime = isPrime(userPrime);
	if (prime == 1) {
		printf("%d is a prime number.\n", userPrime);
	}
	else {
		printf("%d is not a prime number.\n", userPrime);
	}

	int tri;
	printf("Please enter a number for a triangle:\n");
	scanf("%d", &tri);
	floydsTriangle(tri);

	//system("pause");
}