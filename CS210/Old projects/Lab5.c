#define _CRT_SECURE_NO_WARNINGS


/** lab05.c
* ===========================================================
* Name: Name, Date
* Section:
* Project: Lab 5 - Branches I
* Purpose:
* ===========================================================
* Instructions:
 * Complete the tasks outlined in the lab writeup.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

/***
 *  Function prototypes
 */
void guessGame();
int evenOdd(int value);
int passFail(int score);
int residenceHall(int squadron);
bool isLeapYear(int year);
int daysInYear(int year);
//int exemplar(int year);
int drinkSize(int size);
int quadrant(int x, int y);
bool isLeap(int year);
int daysInMonth(int month, int year);

int main() {

    // Exercise 0 - Guess Game
    guessGame();

    // TODO 1.2 - Exercise 1 - Even or Odd Numbers
    int userNum;
    int value;
    printf("Enter a value: \n");
    scanf("%d", &userNum);
    value = evenOdd(userNum);
    if (value == 0) {
        printf("%d is even.\n", userNum);
    }
    else {
        printf("%d is odd.\n", userNum);
    }
    // TODO 2.2 - Exercise 2 - Pass or Fail Grades
    int grade;
    int valueA;
    printf("Enter a score: \n");
    scanf("%d", &grade);
    valueA = passFail(grade);
    if (valueA == 1) {
        printf("%d is passing.\n", grade);
    }
    else {
        printf("%d is failing.\n", grade);
    }
    // TODO 3.2 - Exercise 3 - Squadron Residence Halls
    int valueB;
    int hall;
    printf("Enter a squadron: \n");
    scanf("%d", &valueB);
    hall = residenceHall(valueB);
    if (hall == 1) {
        printf("Squadron %d is located in Vandy.\n", valueB);
    }
    else {
        printf("Squadron %d is located in Sijan. \n", valueB);
    }
    // TODO 4.3 - Exercise 4 - Days in Year
    int year;
    int days;
    printf("Enter a year: \n");
    scanf("%d", &year);
    days = daysInYear(year);
    printf("The year %d has %d days.\n", year, days);
    // TODO 5.2 - Exercise 5 - Exemplar
    /*int Class;
    int exemp;
    printf("Enter a class year (two digits): \n");
    scanf("%d", &Class);
    exemp = exemplar(Class);
    if (exemp == 0) {
        printf("Class of 2021's exemplar is Risner.\n");
    }
    if (exemp == 1) {
        printf("The class of 2020's exemplar is Hoover.\n");
    }
    if (exemp == 2) {
        printf("The class of 2019's exemplar is Armstrong.\n");
    }*/

    // TODO 6.2 - Exercise 6 - Drink Size
    int ounces;
    int sz;
    printf("Enter a drink size: \n");
    scanf("%d", &ounces);
    sz = drinkSize(ounces);
    if (sz == 0) {
        printf("A drink size of %d is a small drink.\n", ounces);
    }
    if (sz == 1) {
        printf("A drink size of %d is a medium drink.\n", ounces);
    }
    if (sz == 2) {
        printf("A drink size of %d is a large drink.\n", ounces);
    }
    if (sz == 3) {
        printf("A drink size of %d is a ridiculous drink.\n", ounces);
    }
    // TODO 7.2 - Exercise 7 - Quadrant

    // TODO 8.2 - Exercise 8 - Days in Month
    return 0;
}

/**--------------------------------------------------------------------------------------------
 * A function that generates a random number between 0 and 100 and asks the user to guess it.
 * @param <explanation of each of the function parameters>
 * @return <explanation of what the function returns>
 */
void guessGame() {
    int answer, guess;

    // Setup and seed the random number generator
    struct timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    srandom((unsigned)(time.tv_nsec ^ time.tv_sec));

    // Generate a random number between 0 and 100
    answer = random() % 101;

    // Prompt user for a guess and check whether it is correct or not
    printf("I am thinking of a number between 0 and 100.\n");
    printf("Pssst...the secret answer is %d.\n", answer); // for debugging only
    printf("What is your guess: ");
    scanf("%d", &guess);
    if (guess == answer) {
        printf("You guessed right! The answer was %d.\n", answer);
    }
    else {
        printf("Sorry, you guessed %d, but the answer was %d.\n", guess, answer);
    }
}

// TODO 1.1 - Exercise 1 - Even or Odd Numbers
int evenOdd(int x) {
    int remainder;
    remainder = x % 2;
    return remainder;
}

// TODO 2.1 - Exercise 2 - Pass Fail Grades
int passFail(int x) {
    if (x >= 70) {
        return 1;
    }
    else {
        return 0;
    }
}

// TODO 3.1 - Exercise 3 - Residence Hall
int residenceHall(int x) {
    if (x <= 23) {
        return 1;
    }
    else {
        return 0;
    }
}

// TODO 4.1 - Exercise 4 - Is Leap Year
bool isLeapYear(int x) {
    if ((x % 4) == 0) {
        if ((x % 100) != 0) {
            if ((x % 400)) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
 /**------------------------------------------------------------------------------------
 *   <add a description>
 *   @param year - The number of years.
 *   @returns A boolean indicating whether the year is a leap year
 */



 // TODO 4.2 - Exercise 4 - Days In Year
int daysInYear(int x) {
    bool leap = isLeapYear(x);
    if (leap == true) {
        return 366;
    }
    else {
        return 365;
    }
}

 // TODO 5.1 - Exercise 5 - Exemplar
//int exemplar(int x) {
//    if (x == 19) {
//        return 2;
//    }
//    else if (x == 20) {
//        return 1;
//    }
//    else if (x == 21) {
//        return 1;
//    }
//}

 // TODO 6.1 - Exercise 6 - Drink Size
int drinkSize(int x) {
    if (x <= 12) {
        return 0;
    }
    else if (x <= 20) {
        return 1;
    }
    else if (x <= 32) {
        return 2;
    }
    else {
        return 3;
    }
}

 // TODO 7.1 - Exercise 7 - Quadrant


 // Exercise 8 - Days in Month

 /**------------------------------------------------------------------------------------
  *   A function that determines the number of days in a month in a given year.
  *   @param month The numeric value for the month.
  *   @param year The year in which the month occurs.
  *   @returns The number of days in the month.
  */
int daysInMonth(int month, int year) {
    // TODO 8.1: Implement the selection statement as described
    // TODO      using logical operators && (and) and || (or) Ask for help as this is a preview
    // TODO      of next lesson's material
    return 0;
}