#define _CRT_SECURE_NO_WARNINGS
/** lab03.c
* ===========================================================
* Name: Colton Willits / 8/20/2020
* Section: M3A-M4A
* Project: Lab 3 - Variables, Data Types, and Strings
* Purpose: Learn C basics
* ===========================================================
* Instructions:
 * Complete the tasks outlined in the lab writeup.
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
int main() {


    // TODO 1.1 - Exercise 1 - Distance Formula
    int valueAx;
    int valueAy;
    int valueBx;
    int valueBy;
    double distance;
    printf("Please enter the first coordinate: \n");
    scanf("%d", &valueAx);
    scanf("%d", &valueAy);
    printf("Please enter the second coordinate: \n");
    scanf("%d", &valueBx);
    scanf("%d", &valueBy);

    distance = sqrt(pow(valueBx - valueAx, 2) + pow(valueBy - valueAy, 2));
    printf("%lf\n", distance);


    // TODO 2.1 - Exercise 2 - Data Types
    float valueC;
    float valueD;
    printf("Please enter two values: \n");
    scanf("%f", &valueC);
    scanf("%f", &valueD);
    printf("%.2f\n", ((double)(valueC / valueD)* 100));
    printf("%.4f\n", ((double)(valueD / valueC)* 100));


        // TODO 3.1 - Exercise 3 - sizeof()
    int x;
    printf("Please input a integer: \n");
    scanf("%d", &x);
    printf("%ld", sizeof(x));
    printf("%f %ld \n", (double)x, sizeof(x));

    //    // TODO 3.2 - Exercise 3 - sizeof()
    char character;
    printf("Please input a character: \n");
    scanf("%c", &character);
    printf("%c %ld \n", character, sizeof(character));

        // TODO 4.1 - Exercise 4 - Strings
    char char_array[50] = "";
    char s1[10] = "";
    printf("Please input a string no longer than 50 characters: \n");
    scanf("%s", &char_array);
    strcpy(s1, char_array, 10);
    printf("%s\n", s1);
    int value = strcmp(char_array, s1);
    printf("%d\n", value);
    int value2 = strcmp(s1, s1);
    printf("%d", value2);
    printf("%d\n", (int) strlen(char_array));


    

    return 0;
}

