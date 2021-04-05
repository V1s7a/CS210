#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "lab19functs.h"
#include <string.h>

int main(void) {
	
	char str[MAX_STR_LEN], a, b;
	printf("Function - 1\n");
	printf("Enter a string (<= 80 chars): ");
	fgets(str, MAX_STR_LEN, stdin);
	printf("Enter a search character followed by replace character: ");
	scanf("%c %c", &a, &b);
	replStr(str, a, b);
	printf("New string (between arrows): -->%s<--\n", str);

	//char ch = '\0'; while ((ch = getchar()) != '\n' && ch != EOF);
	
	char strTwo[MAX_STR_LEN], searchString[MAX_STR_LEN], x;
	printf("Function - 2\n");
	printf("Enter a string (<= 80 chars): ");
	fgets(strTwo, MAX_STR_LEN, stdin);
	printf("Enter a search string (<= 80 chars): ");
	fgets(searchString, MAX_STR_LEN, stdin);
	printf("Enter a replacement character: ");
	scanf("%c", &x);
	replMultiChar(strTwo, searchString, x);
	printf("New string (between arrows): -->%s<--\n", strTwo);

	char strThree[MAX_STR_LEN], c;
	int locations[MAX_STR_LEN];
	printf("Function - 3\n");
	printf("Enter a string (<= 80 chars): ");
	fgets(strThree, MAX_STR_LEN, stdin);
	printf("Enter a character whose locations you wish to find: ");
	scanf("%c", &c);
	int l = findLocations(strThree, locations, c), i;
	printf("There are %d occurences of %c.\n", l, c);
	for (i = 0; i < l; i++) {
		printf("%c found at location %c\n", c, locations[i]);
	}

	//system("pause");
	return 0;
}
