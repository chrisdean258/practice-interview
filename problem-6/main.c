#include "race.h"
#include <stdio.h>

struct test {
	uint64_t time;
	uint64_t distance;
	uint64_t soln;
};

struct test tests[] = {
	{7, 9, 4},
	{15, 40, 8},
	{30, 200, 9},
	{71530, 940200, 71503 },
	{53897698, 313109012141201, 40651271 },
};


int main(int argc, char ** argv)
{
	for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
		uint64_t ways = race(tests[i].time, tests[i].distance);
		printf("Test %d -- Expected:  %llu   Got: %llu\n", i, tests[i].soln, ways);
	}
}
