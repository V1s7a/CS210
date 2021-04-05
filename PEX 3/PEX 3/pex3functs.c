/** pex3functs.c
* ===========================================================
* Name: C3C Colton Willits
* Section: M3-4
* Project: PEX3
* Purpose: Compare dna sequences
* ===========================================================
*/
#define _CRT_SECURE_NO_WARNINGS
#include "pex3functs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** ----------------------------------------------------------
* readFile reads file and scans DNA from the file
* @filename[] contains the file path for the DNA sequences
* @sequence is the datastructure in which we need to scan our sequences into
*/
int readFile(char fileName[], DNA sequences[])
{
	
	FILE* doc = fopen(fileName, "r"); // open & read the file
	if (doc == NULL) {
		printf("Error opening file.\n");
		exit(1);
	}
	char spec[50], dna[500];

	int i = 0;
	while (fscanf(doc, "%s %s", spec, dna) != EOF) //read the data from file into DNA data structure
	{

		strcpy(sequences[i].species, spec);
		strcpy(sequences[i].dna, dna);
		i++;
	}
	fclose(doc); //close the file

	return i; //return number of DNA sequences read from file
}

/** ----------------------------------------------------------
* printSequences prints the genome of the DNA and the DNA squence
* @sequences[] is the datastructure from which we pull the information
* @numSeq is the number of sequences in the data structure being printed.
*/
void printSequences(DNA sequences[], int numSeq)
{
	for (int i = 0; i < numSeq; i++)
	{
		printf("DNA Type-> %s\n", sequences[i].species);
		printf("Sequence-> %s\n\n", sequences[i].dna);
	}
	return;
}

/** ----------------------------------------------------------
* hammingDistance returns the distance between two similar amino acids
* @str1[] is the first DNA sequence to compare
* @str2[] is the second DNA sequence to compare
*/
int hammingDistance(char str1[], char str2[])
{
	int distance = 0;
	if (strlen(str1) != strlen(str2))
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < strlen(str1); i++)
		{
			if (str1[i] != str2[i])
			{
				distance++;
			}
		}
		return distance;
	}
	
}

/** ----------------------------------------------------------
* similarityScore compares the similarity between two DNA sequences and returns the similarity
* @seq1[] is the first DNA sequence
* @seq2[] is the second DNA sequence
*/
float similarityScore(char seq1[], char seq2[])
{
	if (strlen(seq1) != strlen(seq2))
	{
		return -1;
	}
	float score = (float)(strlen(seq1) - hammingDistance(seq1, seq2)) / (float)strlen(seq1);
	return score;
}

/** ----------------------------------------------------------
* countMatches counts the number of possible matches within a genome
* @genome is the genome to be searched
* @seq is a sequence of characters to be searched for within a genome
* @minScore is the minimum similarity score
*/
int countMatches(char genome[], char seq[], float minScore)
{
	int matches = 0, length = (int)strlen(seq);
	char sequence[20], * dna = genome;
	while (strlen(dna) >= length)
	{
		strncpy(sequence, dna, length);
		sequence[length] = '\0';
		if (similarityScore(sequence, seq) >= minScore)
		{
			matches++;
		}
		dna++;
	}
	return matches;
}

/** ----------------------------------------------------------
* findBestMatch finds the genome with the best match
* @genome[] is the genome to be searched
* @seq is a sequence of characters to be searched
*/
float findBestMatch(char genome[], char seq[])
{
	int length = (int)strlen(seq);
	char sequence[20], * dna = genome;
	float maxScore = 0;
	while (strlen(dna) >= length)
	{
		strncpy(sequence, dna, length);
		sequence[length] = '\0';
		if (similarityScore(sequence, seq) > maxScore)
		{
			maxScore = similarityScore(sequence, seq);
		}
		dna++;
	}
	return maxScore;
}

/** ----------------------------------------------------------
* findBestGenome compares the best similarity score between a specified unknown sequence and a datastructure of genomes DNA
* @sequences[] is the data structure in which we pull sequences from
* @numSeq is the number of sequences in our data structure
* @unknownSeq[] is the unknown DNA sequences to be compared
*/
int findBestGenome(DNA sequences[], int numSeq, char unknownSeq[])
{
	int position = 0;
	float largest = findBestMatch(sequences[0].dna, unknownSeq);
	for (int i = 0; i < numSeq; i++)
	{
		if (findBestMatch(sequences[i].dna, unknownSeq) > largest) {
			largest = findBestMatch(sequences[i].dna, unknownSeq);
			position = i;
		}
	}
	return position;
}
