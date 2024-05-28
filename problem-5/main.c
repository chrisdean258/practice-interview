#include "freq.h"
#include <stdio.h>

struct test {
	char * test;
	int soln;
};

struct test tests[] = {
	{ "abcc", 1 },
	{ "aabb", 0 },
	{ "aabbc", 1},
	{ "abccc", 0},
};


int main(int argc, char ** argv)
{
	for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
		int good = freq(tests[i].test);
		printf("Test %d -- Expected:  %d   Got: %d\n", i, tests[i].soln, good);
	}
}
