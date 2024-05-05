#include <stdio.h>
#include <string.h>
#include "stats.h"

uint32_t encode(char c) {
	switch (c) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			  fprintf(stderr, "Cannot encode '%d'. Exiting", c);
			  exit(1);
	}
}


void process1(int counts[4], char * line) {
	while(*line) {
		counts[encode(*line)]++;
		line++;
	}
}

size_t max_minus_min(char * lines[128]) {
	int counts[4];
	int max = 0;
	int min = 0;
	for(int i = 0; i < 128; i++) {
		memset(counts, 0, sizeof(counts));
		process1(counts, lines[i]);
		for(int j = 0; j < 4; j++) {
			if(counts[j] > max) max = counts[j];
			if(counts[j] < min || min == 0) min = counts[j];
		}
	}
	return max - min;
}

void process2(int counts[256], char * line) {
	uint32_t hash = encode(*line++) << 4;
	hash |= encode(*line++) << 2;
	hash |= encode(*line++) << 0;
	while(*line) {
		hash = (hash << 2 | encode(*line++)) & 0xFF;
		counts[hash]++;
	}
}

size_t count_max_4(char * lines[128]) {
	int counts[256];
	memset(counts, 0, sizeof(counts));
	for(int i = 0; i < 128; i++) {
		process2(counts, lines[i]);
	}
	int max = 0;
	for(int i = 0; i < 128; i++) {
		if(counts[i] > max) max = counts[i];
	}
	return max;
}
