#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
/** lab04.c
* ===========================================================
* Name: Colton Willits, 8/20/2020
* Section:
* Project: Lab 4 - User-defined Functions
* Purpose: Learn function prototypes, user-defined functions,
*          return values, and parameters.
* ===========================================================
* Instructions:
 * Complete the tasks outlined in the lab writeup.
*/
// TODO 1.0 - Exercise 1 - Find Largest
#include <stdio.h>
// TODO 3.0 - Exercise 3 - Degress to Radians
#include <math.h>
// TODO 4.0 - Exercise 4 - Boolean
#include <stdbool.h>

// TODO 1.1 - Exercise 1 - Find Largest
int findLargest();
// TODO 2.1 - Exercise 2 - Temperature Conversion
double fahrenheitToCelsius();
// TODO 3.1 - Exercise 3 - Degress to Radians
double degreesToRadians();
// TODO 4.1 - Exercise 4 - Boolean
bool magicNumber();

int main() {
	// TODO 1.3 - Exercise 1 - Find Largest
	int x;
	int y;
	int z;
	int largest;
	printf("Please enter three integers: \n");
	scanf("%d %d %d", &x, &y, &z);
	largest = findLargest(x, y, z);
	printf("%d\n", largest);

	// TODO 2.3 - Exercise 2 - Temperature Conversion
	int temperature;
	double celsius;
	printf("Please enter the temperature in fahrenheit: \n");
	scanf("%d", &temperature);
	celsius = fahrenheitToCelsius(temperature);
	printf("%lf\n", celsius);

	// TODO 3.3 - Exercise 3 - Degress to Radians
	int degrees;
	double radians;
	printf("Please enter the degrees: \n");
	scanf("%d", &degrees);
	radians = degreesToRadians(degrees);
	printf("%lf\n", radians);

	// TODO 4.3 - Exercise 4 - Boolean
	int num;
	bool value;
	printf("Please enter the magic number: \n");
	scanf("%d", &num);
	value = magicNumber(num);
	printf("%d\n", value);

	return 0;
}

// TODO 1.2 - Exercise 1 - Find Largest
int findLargest(int x, int y, int z) {
	int largest = -1; //initialized with -1
	if (x >= y) {
		if (x >= z)
			largest = x;
		else
			largest = z;
	}
	else {
		if (y >= z)
			largest = y;
		else
			largest = z;
	}
	return largest;
}
// TODO 2.2 - Exercise 2 - Temperature Conversion
double fahrenheitToCelsius(double f) {
	double celsius;
	celsius = (5.0 / 9.0) * (f - 32);
	return celsius;
}
// TODO 3.2 - Exercise 3 - Degress to Radians
double degreesToRadians(int degrees) {
	double radians;
	radians = degrees * M_PI / 180.0;
	return radians;
}
// TODO 4.2 - Exercise 4 - Boolean
bool magicNumber(int x) {
	int magicNum = 12;
	if (x == magicNum) {
		return true;
	}
	else {
		return false;
	}
}
