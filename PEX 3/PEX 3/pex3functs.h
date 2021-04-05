/** pex3functs.h
* ===========================================================
* Name: C3C Colton Willits
* Section: M3-4
* Project: PEX3
* Purpose: Compare dna sequences
* ===========================================================
*/
#ifndef PEX3FUNCTS_H
#define PEX3FUNCTS_H
#define MAX_CHAR 500

typedef struct DNA_struct {
	char species[50];
	char dna[500];
}DNA;

int readFile(char fileName[], DNA sequences[]);
void printSequences(DNA sequences[], int numSeq);
int hammingDistance(char str1[], char str2[]);
float similarityScore(char seq1[], char seq2[]);
int countMatches(char genome[], char seq[], float minScore);
float findBestMatch(char genome[], char seq[]);
int findBestGenome(DNA sequences[], int numSeq, char unknownSeq[]);
#endif // !PEX3FUNCTS_H
