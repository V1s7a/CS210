#define _CRT_SECURE_NO_WARNINGS
#include "lab20functs.h"
#include <string.h>


double fToC(double degF) {
	return ((double)5 / 9) * (degF - 32);
}

double cToK(double degC) {
	return degC + 273.15;
}

void printTable(double degFlow, double degFhigh, double degFstep) {
	printf("\n|-----------------------------|\n"
		"|                             |\n"
		"|   Temperature Conversions   |\n"
		"|                             |\n"
		"|-----------------------------|\n"
		"|Farenheit| Celsius | Kelvin  |\n"
		"|-----------------------------|\n");
	while (degFlow <= degFhigh) {
		printf("|%9.2lf", degFlow);
		printf("|%9.2lf", fToC(degFlow));
		printf("|%9.2lf|\n", cToK(fToC(degFlow)));

		degFlow += degFstep;
	}

	printf("|-----------------------------|\n");
}


	double getInput(char title[], double min, double max) {
		double in = 0.0;
		int i = 0;
		fprintf(stdout, "%s\n", title);
		if (strcmp(title, "What step size:") == 0) {
			fscanf(stdin, "%lf", &in);
			return in;
		}
		else {
			while (i == 0)
			{
				fscanf(stdin, "%lf", &in);
				if ((in <= min) || (in >= max)) {
					fprintf(stdout, "Your input is outside of the range %.2lf %.2lf.\nPlease re-enter.", min, max);
					fprintf(stdout, "%s\n", title);
				}
				else {
					i = 1;
				}
			}
		}
		return in;
	}

	bool again() {
		printf("Would you like to do this again?\n");
		char r;
		fflush(stdin);
		fscanf(stdin,"%c", &r);
		if (r == 'y' || r == 'Y') {
			return true;
		}
		else {
			return false;
		}
	}