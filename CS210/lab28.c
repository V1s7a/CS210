/** lab28.c
* ===========================================================
* Name: FIRST LAST, DATE
* Section: SECTION
* Project: Progamming Assessment 3 Practice
* Documentation: DOC STATEMENT
* ===========================================================  */

#define _CRT_SECURE_NO_WARNINGS
#include "lab28.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




int getNumLines(char*);

int main(void)
{
    //    PROBLEM 1 - STRING MANIPULATION
    //          a.) Define a function called numVowels that takes in a character array and outputs
    //          an integer.  The function itself finds the number of vowels within the provided character
    //          array. The character array may contain spaces and punctuation.

        //      b.) Define a function called sortString that expects an array of characters and
        //      and returns a pointer to an array of characters.  The function sorts the characters
        //      in the string in alphabetic order, stores them in this order, and returns a pointer to
        //      this sorted array of characters.
        //      The character array may contain spaces and punctuation. When sorting, spaces and punctuation
        //      should be ignored and all alphabetic characters should be changed to lowercase for
        //      sorting and output.  The spaces and special characters will not appear in the sorted array.
        //      NOTE: In order to return a pointer to an array of characters that has scope outside a
        //          function call, the memory used to store the sorted array must by dynamically
        //          allocated.

        // PROBLEM 2 - Manipulate Employee Data
        //      You are tasked to create a program that will pull employee records from a simple
        //      text file that contains name and birthdate.  The ultimate goal is to allow a user
        //      to input a month that will result in output to the screen displaying all of the
        //      employees with birthdays for the specified month.  This will assist the squadron
        //      commander with ensuring that all employee birthdays are recognized at the
        //      monthly staff meeting.

        //      a.) Define a structure type, named EmployeeBD, with appropriate members
        //      to store data from the Employee_Recs.txt file. Use the fields names:
        //      firstName, lastName, birthMonth, and birthDate.

        //      b.) Use the getNumLines function provided to capture the number of records to be read from
        //      from the Employee_Recs.txt file, then dynamically allocate memory to store the employee data
        //      from the text file.

        //      c.) Create a user-defined function called readFile, which requires the filename,
        //      memory passed by reference, and the number of records to be passed as parameters
        //      (in that order).  This function returns the integer value corresponding to the number
        //      of records successfully read.

        //      d.) Create a user-defined function called IDEmpBDMonth to print the employee records
        //      for all employees born in a specified month.  This function accepts three parameters
        //      being the stored records passed by reference, the number of records, and the specified
        //      month for record printing (in that order).  It returns the number of records with the
        //      specified month.
        //      NOTE:  In main, ask the user to provide an integer from 1 - 12 that corresponds with the
        //          birth month they would like to query.
        //      Format the output to the screen as follows:
        //          Example if the user enters 10:
        //              Requested Birthdays are:
        //              Lastname	Firstname	Birthday
        //              *********************************************
        //              Smith		Brian		October 13

        //      e.) Create a user-defined function called readEmployeeArchive, which requires an index,
        //      an int, which identifies a specific Employee entry in the binary archive. 
        //      This function returns the EmployeeBD structre found at the provided index in the archive.
        //      The filename of the binary file is "EmployeeBDData.archive", provided by the lab.

        //      f.) Your final task is to update the current EmployeeBD record in memory and print out the
        //      new list of upcoming birthdays in November. There is a note on from the previous exec that
        //      the first two members of the record (Brian Smith & Angie Thomas) have left the unit but the
        //      15th & 17th entries in the archive still remain in the unit.
        //      NOTE: You must call IDEmpBDMonth(____, ___, 11) after your update to print new November results
    EmployeeBD* employeeData[20];
    char fileName = "Employee_Recs.txt";
    int x = readFile(fileName, employeeData, 16);
    employeeData[0] == NULL;
    employeeData[1] == NULL;
    IDEmpBDMonth(&employeeData, 14, 11);

    return 0;
}

int getNumLines(char filename[])
{
    char c;
    int count = 0;
    // Open the file
    FILE* fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;

    // Close the file
    fclose(fp);
    //printf("The file %s has %d lines\n ", filename, count);

    return count;
}

int numVowels(char array[])
{
    int v = 0;
    for (int i = 0; i < strlen(array); i++)
    {
        if (isalpha(array[i]) != 0)
        {
            switch (array[i])
            {
            case 'a':
                v++;
                break;
            case 'A':
                v++;
                break;
            case 'e':
                v++;
                break;
            case 'E':
                v++;
                break;
            case 'i':
                v++;
                break;
            case 'I':
                v++;
                break;
            case 'o':
                v++;
                break;
            case 'O':
                v++;
                break;
            case 'u':
                v++;
                break;
            case 'U':
                v++;
                break;
            default:
                break;
            }
        }
    }

    return v;
}

char* sortString(char* in) { //this function hella jank
    int n = strlen(in);

    char* sortedIn = (char*)malloc(sizeof(char) * n); //allocates heap for a string with length in

    char* address = sortedIn;
    int numspace = 0;
    while (*in != '\0') {
        *sortedIn = tolower(*in);

        if (*in == ' ') {
            numspace++;
        }

        sortedIn++;
        in++;
    }

    sortedIn = address;

    char temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sortedIn[i] > sortedIn[j]) {
                temp = sortedIn[i];
                sortedIn[i] = sortedIn[j];
                sortedIn[j] = temp;
            }
        }
    }

    //printf("%d\n", numspace);
    sortedIn += numspace;

    sortedIn[n - numspace] = '\0'; //because initial string copy doesn't copy the '\0'

    //if (sortedIn[n] == '\0') {
    //    printf("I don't understand this lab.\n");
    //}

    return sortedIn;
}

int readFile(char fileName[], EmployeeBD* empStruct, int numLines) {
    int retVal = 0;

    FILE* fp = fopen(fileName, "r");

    for (int i = 0; i < numLines; i++) {
        fscanf(fp, "%s", empStruct[i].firstName);
        fscanf(fp, "%s", empStruct[i].lastName);
        fscanf(fp, "%s", empStruct[i].birthMonth);
        fscanf(fp, "%d", &empStruct[i].birthDate);
        retVal++;
    }
    fclose(fp);
    return retVal;
}

int IDEmpBDMonth(EmployeeBD* empStruct, int records, int month)
{
    int employees = 0;
    // print header
    printf("Requested Birthdays are:\n");
    printf("Lastname\tFirstname\tBirthday\n");
    printf("*********************************************\n");
    
    for (int i = 0; i < records; i++)
    {
        switch (month)
        {
        case 1:
            if (strcmp(empStruct[i].birthMonth, "January") == 0) {
                printf("%-9s\t%-9s\t%s %d\n", empStruct[i].lastName, empStruct[i].firstName, empStruct[i].birthMonth,
                    empStruct[i].birthDate);
                employees++;
            }
            break;
        case 2:
            if (strcmp(empStruct[i].birthMonth, "February") == 0) {
                printf("%-9s\t%-9s\t%s %d\n", empStruct[i].lastName, empStruct[i].firstName, empStruct[i].birthMonth,
                    empStruct[i].birthDate);
                employees++;
            }
            break;
        case 3:
            if (strcmp(empStruct[i].birthMonth, "March") == 0) {
                printf("%-9s\t%-9s\t%s %d\n", empStruct[i].lastName, empStruct[i].firstName, empStruct[i].birthMonth,
                    empStruct[i].birthDate);
                employees++;
            }
            break;
        case 4:
            if (strcmp(empStruct[i].birthMonth, "April") == 0) {
                printf("%-9s\t%-9s\t%s %d\n", empStruct[i].lastName, empStruct[i].firstName, empStruct[i].birthMonth,
                    empStruct[i].birthDate);
                employees++;
            }
            break;
        case 5:
            if (strcmp(empStruct[i].birthMonth, "May") == 0) {
                printf("%-9s\t%-9s\t%s %d\n", empStruct[i].lastName, empStruct[i].firstName, empStruct[i].birthMonth,
                    empStruct[i].birthDate);
                employees++;
            }
            break;
        case 6:
            if (strcmp(empStruct[i].birthMonth, "June") == 0) {
                printf("%-9s\t%-9s\t%s %d\n", empStruct[i].lastName, empStruct[i].firstName, empStruct[i].birthMonth,
                    empStruct[i].birthDate);
                employees++;
            }
            break;
        case 7:
            if (strcmp(empStruct[i].birthMonth, "July") == 0) {
                printf("%-9s\t%-9s\t%s %d\n", empStruct[i].lastName, empStruct[i].firstName, empStruct[i].birthMonth,
                    empStruct[i].birthDate);
                employees++;
            }
            break;
        case 8:
            if (strcmp(empStruct[i].birthMonth, "August") == 0) {
                printf("%-9s\t%-9s\t%s %d\n", empStruct[i].lastName, empStruct[i].firstName, empStruct[i].birthMonth,
                    empStruct[i].birthDate);
                employees++;
            }
            break;
        case 9:
            if (strcmp(empStruct[i].birthMonth, "September") == 0) {
                printf("%-9s\t%-9s\t%s %d\n", empStruct[i].lastName, empStruct[i].firstName, empStruct[i].birthMonth,
                    empStruct[i].birthDate);
                employees++;
            }
            break;
        case 10:
            if (strcmp(empStruct[i].birthMonth, "October") == 0) {
                printf("%-9s\t%-9s\t%s %d\n", empStruct[i].lastName, empStruct[i].firstName, empStruct[i].birthMonth,
                    empStruct[i].birthDate);
                employees++;
            }
            break;
        case 11:
            if (strcmp(empStruct[i].birthMonth, "November") == 0) {
                printf("%-9s\t%-9s\t%s %d\n", empStruct[i].lastName, empStruct[i].firstName, empStruct[i].birthMonth,
                    empStruct[i].birthDate);
                employees++;
            }
            break;
        case 12:
            if (strcmp(empStruct[i].birthMonth, "December") == 0) {
                printf("%-9s\t%-9s\t%s %d\n", empStruct[i].lastName, empStruct[i].firstName, empStruct[i].birthMonth,
                    empStruct[i].birthDate);
                employees++;
            }
            break;
        default:
            break;
        }
    }

    return employees;
}

EmployeeBD readEmployeeArchive(int index)
{
    EmployeeBD tempEmployee;
    FILE* fp = fopen("EmployeeBDData.archive", "rb");

    if (fp == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    fseek(fp, sizeof(EmployeeBD)*index, SEEK_CUR);
    fread(&tempEmployee, sizeof(EmployeeBD), 1, fp);
    fclose(fp);
    return tempEmployee;
}

