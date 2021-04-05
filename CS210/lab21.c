#define _CRT_SECURE_NO_WARNINGS

/** example21a.c
* ===========================================================
* Name: CS210
* Section: n/a
* Project: Lesson 21 examples
* Purpose: Demonstrate File I/O in C
* ===========================================================
*/
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define NUM_RECORDS 50


int main(void) {
	char firstName[NUM_RECORDS][20];
	char lastName[NUM_RECORDS][20];
	int feet[NUM_RECORDS];
	int inches[NUM_RECORDS];
	double weight[NUM_RECORDS];

	FILE* filePtr = fopen("football.txt", "r");
	FILE* filePtr2 = fopen("fbConvert.txt", "w");

	int i = 0;
	fscanf(filePtr, "%s %s %d %d %.2lf", firstName[i], lastName[i], &feet[i], &inches[i], &weight[i]);
	while (!feof(filePtr)) {
		printf("%s %s %d %d %.2lf\n", firstName[i], lastName[i], feet[i], inches[i], weight[i]);
		/*fwrite(&firstName[i], sizeof(firstName[i]), 1, filePtr2);
		fwrite(&lastName[i], sizeof(lastName[i]), 1, filePtr2);
		fwrite(&feet[i], sizeof(feet[i]), 1, filePtr2);
		fwrite(&inches[i], sizeof(inches[i]), 1, filePtr2);
		double kilograms = weight[i] / 2.204;
		fwrite(&weight[i], sizeof(weight[i]), 1, filePtr2);*/
		fprintf(filePtr2, "%s %s %d %d %.2lf\n", firstName[i], lastName[i], (int)feet[i], (int)inches[i], (double)(weight[i] / 2.204));
		i++;
		fscanf(filePtr, "%s %s %d %d %.2lf", firstName[i], lastName[i], &feet[i], &inches[i], &weight[i]);
	}
	fclose(filePtr);
	fclose(filePtr2);





}


