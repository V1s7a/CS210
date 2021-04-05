/** lab28.h
* ===========================================================
* Name: COLTON WILLITS, 10/29/20
* Section: M3-4
* Project: Programming Assessment 3 Practice
* Documentation: DOC STATEMENT
* ===========================================================  */

#ifndef MYEXE_LAB28_H
#define MYEXE_LAB28_H

#define MAX_LENGTH 20
#define FILENAME "Employee_Recs.txt"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct EmployeeBD_struct {
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    char birthMonth[MAX_LENGTH];
    int birthDate;
} EmployeeBD;

int numVowels(char* in);

char* sortString(char* in);

int readFile(char fileName[], EmployeeBD* empStruct, int numLines);

int IDEmpBDMonth(EmployeeBD* empStruct, int records, int month);

EmployeeBD readEmployeeArchive(int index);

#endif //MYEXE_LAB28_H
