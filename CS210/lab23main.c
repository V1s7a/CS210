#define _CRT_SECURE_NO_WARNINGS
#include "lab23functs.h"
#include <stdio.h>
int main() {
    char dataFile[] = "lab23Data.txt";

    printf("Reading number of records in the data file.\n");
    int numRecs = getNumRecs(dataFile);
    printf("%d records in the data file.\n", numRecs);

    CadetInfoStructType* cadetInfo = (CadetInfoStructType*)malloc(sizeof(CadetInfoStructType) * numRecs);

    getDataText(cadetInfo, numRecs, dataFile);

    printf("The first cadet is:\n");
    printCadetInfo(cadetInfo[0]);
    printf("The last cadet is:\n");
    printCadetInfo((cadetInfo[numRecs - 1]));

    free(cadetInfo);
    return 0;
}