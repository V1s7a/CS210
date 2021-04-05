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
#include <stdbool.h>
#include <assert.h>
#include "lab10functs.h"

int main(void) {
	assert(isFirstHalfAlpha('a'));
	assert(isFirstHalfAlpha('b'));

	assert(typeOfChar('a') == 0);
	assert(typeOfChar('b') == 1);
	assert(typeOfChar('1') == -1);

	assert(isMagicChar('@'));
	assert(isMagicChar('a') == false);

	char x;
	char y;
	char z;
	printf("Enter a single character to pass to isFirstHalfAlpha():\n");
	scanf("%c", &x);
	if (isFirstHalfAlpha(x)) {
		printf("A %c is in the first half of the alphabet.\n", x);
	}
	else {
		printf("A %c is NOT in the first half of the alphabet.\n", x);
	}
	printf("Enter a single character to pass to typeOfChar():\n");
	scanf(" %c", &y);
	if (typeOfChar(y) == 0) {
		printf("A %c is a vowel.\n", y);
	}
	else if (typeOfChar(y) == 1) {
		printf("A %c is a consonant.\n", y);
	}
	else {
		printf("A %c is neither a vowel nor a consonant.\n", y);
	}
	printf("Enter a single character to pass to isMagicChar():\n");
	scanf(" %c", &z);
	if (isMagicChar(z)) {
		printf("A %c is the magic character @.\n", z);
	}
	else {
		printf("A %c is NOT the magic character @.\n", z);
	}



	//system("pause");
}