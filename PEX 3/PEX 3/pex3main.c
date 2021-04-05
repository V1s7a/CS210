/** pex3main.c
* ===========================================================
* Name: C3C Colton Willits
* Section: M3-4
* Project: PEX3
* Purpose: Compare dna sequences
* Documentation: C3C Josiah Sterns helped me with file IO not working
* ===========================================================
*/
#define _CRT_SECURE_NO_WARNINGS

#include "pex3functs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    
    DNA knownSequences[200];
    int numSequences = readFile("pex3Data1.txt", knownSequences);
    printSequences(knownSequences, numSequences);
}