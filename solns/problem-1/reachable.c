#include "reachable.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

 uint64_t reachable(uint64_t graph[64], size_t start_node) {
	 uint64_t to_visit = (1ull << start_node);
	 uint64_t visited = 0;

	 while(to_visit) {
		// find the smallest set bit in to_visit
		 int i;
		 for(i = 0; i < 64; i++) {
			 //gauranteed because to_visit != 0
			 if (to_visit & (1ull << i)) break;
		 }
		 printf("visting %d\n", i);
		 visited |= (1ull << i);
		 to_visit |= graph[i];
		 to_visit &= ~visited;
	 }
	 return visited;
 }

