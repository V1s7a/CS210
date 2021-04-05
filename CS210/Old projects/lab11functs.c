#include "lab11functs.h"
#include <stdio.h>

// *** function header example *** //
/**   ----------------------------------------------------------
* @fn
* @brief <high level description of purpose of the function>
* @param <explanation of each of the function parameters>
* @return <explanation of what the function returns>
*/

int numFactorial(int x)
{
	int i;
	int y = 1;

	for (i = 1; i <= x; ++i) {
		y = i * y;
	}
	return y;
}

int isPrime(int x)
{
	// check if number is lessthan or equal to 1
	// 1 is prime 0 is not prime
	int prime = 1;
	int i;
	if (x <= 1) {
		return 0;
	}
	else {
		for (i = 2; i <= x / 2; ++i ) {
			if ((x % i) == 0) {
				prime = 0;
				break;
			}
		}
		return prime;
	}

}

void floydsTriangle(int x)
{
	int i, a, b, c;
	for (i = 1; i <= x; ++i) {
		if (i % 2 == 0) {
			a = 0;
			b = 1;
		}
		else {
			a = 1;
			b = 0;
		}
			for (c = 1; c <= i; ++c) 
		if (c % 2 == 0)
			printf("%d", b);
		else
			printf("%d", a);
		printf("\n");
		
	}



	return;
}
