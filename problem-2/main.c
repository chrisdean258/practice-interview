#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stats.h"

const int NUM_LINES = 128;

int main(int argc, char ** argv)
{

	char * lines[NUM_LINES] = { 0 };
	if (argc != 2) {
		fprintf(stderr, "Usage: %s [inputfile]", argv[0]);
		exit(1);
	}

	FILE * f = fopen(argv[1], "r");
	if(f == NULL) {
		perror(argv[1]);
		exit(1);
	}

	for(int i = 0; i < NUM_LINES; i++) {
		char * line = NULL;
		size_t n = 0;
		if(getline(&line, &n, f) > 0) {
			line[strlen(line) - 1] = '\0';
			lines[i] = line;
		} else {
			fprintf(stderr, "Got fewer than 128 lines in %s. This is an error", argv[1]);
			exit(1);
		}
	}

	size_t mmm = max_minus_min(lines);
	size_t cm4 = count_max_4(lines);

	printf("Got %ld for the `max - min` problem\n", mmm);
	printf("Got %ld for the `count max 4 characters` problem\n", cm4);

}
