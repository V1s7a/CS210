/** lab22functs.h
 * ===========================================================
 * Name: First Last, DD MMM YY
 * Section: xxx
 * Project: Lab 22
 * ===========================================================
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "lab22functs.h"

/** ----------------------------------------------------------
 * writeDataBlk() is used to the entire cadet record array
 * to a binary file
 * @param cadetRecords is the array of cadet records
 * @param numCadets is the total number of cadets to write
 * @return number of records wrote
 * ----------------------------------------------------------
 */
int writeDataBlk(MyCadetInfo cadetRecords[], int numCadets) {

    // Open an output file for writing
    FILE *out = fopen("lab22Data.bin", "wb");
    if (out == NULL) {
        printf("Error creating data file: %s.\n", strerror(errno));
        exit(1);
    }

    size_t retVal = fwrite(cadetRecords,sizeof(MyCadetInfo), numCadets, out);
    fclose(out);
    return retVal;

}

/** ----------------------------------------------------------
 * writeCadetBlk() is used to write a single cadet records
 * to a binary file the previous contents of the file are
 * not changed
 * @param cadet is the address of the cadet structure to write
 * @param location is the offset from the from of the file to
 *                 write the record to
 * @return number of records wrote
 * ----------------------------------------------------------
 */
int writeCadetBlk(MyCadetInfo* cadet, int location) {

    // Open an output file for writing
    FILE *out = fopen("lab22Data.bin", "rb+");
    if (out == NULL) {
        printf("Error creating data file: %s.\n", strerror(errno));
        exit(1);
    }
    fseek(out, sizeof(MyCadetInfo) * (long) location, SEEK_SET);
    int retVal = fwrite(cadet,sizeof(MyCadetInfo), 1, out);
    fclose(out);
    return retVal;
}

/** ----------------------------------------------------------
 * getDataText() is used to read MyCadetInfo typed records
 * from a file
 * @param cadetRecords is the array of cadet records
 * @return number of records read
 * ----------------------------------------------------------
 */
int getDataText(MyCadetInfo cadetRecords[]) {

    // Open an input file for reading
    FILE *in = fopen("lab22Data.txt", "r");
    if (in == NULL) {
        printf("Error opening data file: %s.\n", strerror(errno));
        exit(1);
    }

    char firstName[30];
    char lastName[45];
    int numRead = 0;

    while (numRead < MAXSTUDENTS && !feof(in)) {
        fscanf(in, "%s %s %d %d", firstName, lastName, &cadetRecords[numRead].squad,
               &cadetRecords[numRead].classYear);
        strcat(firstName, " ");
        strcpy(cadetRecords[numRead].name, strcat(firstName, lastName));
        numRead++;
    }
    fclose(in);
    return numRead;
}

/** ----------------------------------------------------------
 * printCadetInfo() is used to print a MyCadetInfo typed variable
 * to the console
 * @param cadetRecord is the cadet info struct to be printed
 * @return n/a
 */
void printCadetInfo(MyCadetInfo cadetRecord) {
    printf("Cadet name = \t%s\n", cadetRecord.name);
    printf("Cadet squad = \t%d\n", cadetRecord.squad);
    printf("Cadet year = \t%d\n\n", cadetRecord.classYear);
}

/** ----------------------------------------------------------
 * printData() is used to print MyCadetInfo typed records
 * from a file
 * @param datums is the array of cadet records
 * @param numCadets is the number of cadets in datums
 * @return n/a
 */
void printData(MyCadetInfo* datums, int numCadets) {
    for (int i = 0; i < numCadets; i++) {
        printCadetInfo(datums[i]);
    }
}

MyCadetInfo readCadetBlk(int location) {
    FILE* ptrFile = fopen("lab22Data.bin", "rb");

    if (ptrFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int sizeVar = sizeof(MyCadetInfo);

    fseek(ptrFile, sizeVar * location, SEEK_SET);
    MyCadetInfo CadetVar;
    fread(&CadetVar, sizeVar, 1, ptrFile);
    fclose(ptrFile);

    return CadetVar;
}


int updateSqdBlk(char array[], int squad, MyCadetInfo cadetRecs[], int numCadets) {

    FILE* ptrFile = fopen("lab22Data.bin", "w");

    if (ptrFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    int found = 0;
    int location;
    for (int i = 0; i < numCadets; i++) {
        if (strcmp(cadetRecs[i].name, array) == 0) {
            found = 1;
            location = i;
            break;
        }
    }
    if (found != 1) {
        exit(-1);
    }

    int sizeVar = sizeof(MyCadetInfo);

    fseek(ptrFile, sizeVar * location, SEEK_SET);
    cadetRecs[location].squad = squad;

    int sum = fwrite(cadetRecs, sizeVar, 1, ptrFile);

    fclose(ptrFile);

    return sum;
}

int updateClassYearNameBlk(MyCadetInfo recs) {
    char temp2[5] = "C3C ";

    for (int i = 0; i < 1; i++) {
        if (recs.classYear == 2022) {
            strcpy(temp2, "C3C ");
            strcat(temp2, recs.name);
            strcpy(recs.name, temp2);
        }
        else if (recs.classYear == 2021) {
            strcpy(temp2, "C2C ");
            strcat(temp2, recs.name);
            strcpy(recs.name, temp2);
        }
        else if (recs.classYear == 2020) {
            strcpy(temp2, "C1C ");
            strcat(temp2, recs.name);
            strcpy(recs.name, temp2);
        }
        else {
            strcpy(temp2, "C4C ");
            strcat(temp2, recs.name);
            strcpy(recs.name, temp2);
        }
    }

    printf("%s\n", temp2);
    FILE* ptrFile = fopen("lab22Data.bin", "w");

    if (ptrFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    MyCadetInfo cadetData[] = { recs };
    fwrite(cadetData, sizeof(MyCadetInfo), 1, ptrFile);
    fclose(ptrFile);

    return 0;
}