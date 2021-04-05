/** lab09main.c
* ===========================================================
* Name: Name, Date
* Section:
* Project:
* Purpose:
* ===========================================================
*/
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "lab09functs.h"

int main(void) {
	printf("Testing started\n");
	assert(volumeCylinder(1, 1));
	assert(volumeBox(5, 5, 5) == pow(5, 3));
	assert(degToRad(90));
	printf("Testing complete");
	//system("pause");
}
