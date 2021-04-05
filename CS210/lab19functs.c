#define _CRT_SECURE_NO_WARNINGS
#include "lab19functs.h"
#include <stdio.h>
#include <string.h>

void replStr(char str[], char aChar, char bChar)
{
	int i;
	for (i = 0; i < strlen(str); ++i) {
		if (str[i] == aChar) {
			str[i] = bChar;
		}
		else if (str[i] == bChar) {
			str[i] = aChar;
		}
	}
}

void replMultiChar(char str[], char searchChars[], char rChar)
{
	int i;
	int k;
	for (i = 0; i < strlen(str); ++i) {
		for (k = 0; k < strlen(searchChars); ++k) {
			if (str[i] == searchChars[k]) {
				str[i] = rChar;
			}
		}
	}
}

int findLocations(char str[], int locations[], char searchChar)
{
	int occurances = 0, i;
	for (i = 0; i < strlen(str); ++i) {
		if (str[i] == searchChar) {
			locations[occurances] = i;
			occurances++;
		}
	}

	return occurances;
}
//Challenge problem
int countSeqStr(char str[], char searchStr[])
{
	return 0;
}
