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
#include "lab09functs.h"

int main(void){
    double height;
    double radius;
    printf("Enter cylinder radius followed by height:\n");
    scanf("%lf %lf", &height, &radius);
    printf("the volume is %f.\n", volumeCylinder(radius, height));

    double d;
    double w;
    double h;
    printf("Enter the depth, width, and height of a box:\n");
    scanf("%lf %lf %lf", &d, &w, &h);
    printf("The volume is: %lf.\n", volumeBox(d,w,h));

    int deg;
    printf("Enter degrees:\n");
    scanf("%d", &deg);
    printf("%d degrees is %lf radians.\n", deg, degToRad(deg));


    //system("pause");
}