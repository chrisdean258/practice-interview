#include "twosum.h"
#include <stdio.h>

uint8_t tests[4][500] = {
	{2,7,11,15},
	{3,2,4},
	{3,3},
	{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 22, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99 }
};

int targets[] = { 9, 6, 6, 57 };
size_t lens[] = { 4, 3, 2, 50 };
int expected[4][4] = {
	{ 0, 1 },
	{ 1, 2 },
	{ 0, 1 },
	{ 10, 17 },
};


int main(int argc, char ** argv)
{
	size_t rv[2];
	for (int i = 0; i < 4; i++) {
		twosum(tests[i], lens[i], targets[i], rv);
		printf("Test %d -- Expected: { %d, %d }   Got: { %ld, %ld }", i,
			expected[i][0], expected[i][1],
			rv[0], rv[1]);
	}
}
