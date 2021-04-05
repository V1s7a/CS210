#define _CRT_SECURE_NO_WARNINGS
/** PEX1.c
* ==============================================================
* Name: Colton Willits, 8/20/2020
* Section: M3A-M4A
* Project: PEX1 - ASCII Art and Triangles
* Purpose: Understand how to use C standard library functions,
*          and user-defined functions.
* Documentation Statement:
* ==============================================================
* Instructions:
 * Complete and submit PEX1 as outlined in the writeup.
*/
#include <stdio.h>
#include <math.h>

void drawFlower();
void drawDog();
void drawArrow();
double triangleArea(double base, double height, double hypotenuse);

int main() {
    int userNum;
    printf("Please select a drawing:\n 1. Flower\n 2. Dog\n 3.Arrow\n");
    scanf("%d", &userNum);
    if (userNum == 1) {
        drawFlower();
    }
    if (userNum == 2) {
        drawDog();
    }
    if (userNum == 3) {
        drawArrow();
    }

    double base;
    double height;
    double hypotenuse;
    double area;
    printf("Please enter the base of the triangle: \n");
    scanf("%d", &base);
    printf("Please enter the height of the triangle: \n");
    scanf("%d", &height);
    printf("Please enter the hypotenuse of the triangle: \n");
    scanf("%d", &hypotenuse);
    area = triangleArea(base, height, hypotenuse);
    
    if (area == -1.0) {
        printf("Your inputs do not describe a right triangle!\n");
    }
    else {
        printf("The area of a right triangle with a base side of %d inches, a height of %d inches, and a hypotenuse of %d inches is %.2f square inches.\n",(int) base, (int) height, (int) hypotenuse, area);
    }

    return 0;
}

void drawFlower()
{
    printf("    _ _\n");
    printf("   (_\\_)\n");
    printf("  (__<_{}\n");
    printf("   (_/_)\n");
    printf("  |\\ |\n");
    printf("   \\\\| /|\n");
    printf("    \\|//\n");
    printf("     |/\n");
    printf(",.,.,|.,.,.\n");
    printf("^`^`^`^`^`^ \n");
    return;
}

void drawDog()
{
    printf("^..^      /\n");
    printf("/_/\\_____/\n");
    printf("   /\\   /\\\n");
    printf("  /  \\ /  \\\n");
    return;
}

void drawArrow()
{
    printf("**\n");
    printf("**\n");
    printf("**\n");
    printf("**\n");
    printf("**\n");
    printf("****\n");
    printf("***\n");
    printf("**\n");
    printf("*\n");
    return;
}

double triangleArea(double base, double height, double hypotenuse)
{
    double area = 0.0;
    if ((pow(base, 2) + pow(height, 2)) == pow(hypotenuse, 2)) {
        area = base * height * 1 / 2;
    }
    else {
        area = -1.0;
    }
    return area;
}
