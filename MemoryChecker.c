/*
 * Memory.c
 *
 *  Created on: May 20, 2016
 *      Author: Moawiya
 */

#include "MemoryChecker.h"

static Memory m;
static bool init;

struct _memoryCheck_t {
	int size;
	unsigned int allocsNum;
	unsigned int freesNum;
	unsigned int totalAllocated;
	bool* initialized;
};

void initMemory() {
	m.size = 0;
	m.allocsNum = 0;
	m.freesNum = 0;
	m.totalAllocated = 0;
	m.initialized = &init;
}

void* allocate(size_t size) {
	if (m.initialized != &init) {
		printf("Memory is not initialized !!!\n");
		exit(1);
	}
	void* pntr = malloc(size);
	if (pntr == NULL) {
		return NULL;
	}
	m.size += size;
	m.totalAllocated += size;
	m.allocsNum++;
	return pntr;
}

void deallocate(void* pntr, size_t size) {
	if (m.initialized != &init) {
		printf("Memory is not initialized !!!\n");
		exit(1);
	}
	if (pntr == NULL) {
		return;
	}
	m.size -= size;
	m.freesNum++;
	free(pntr);
}

void finishMemory() {
	char *line = "===========================================================";
	printf("HEAP SUMMARY:\n%s\n", line);
	if (m.size == 0) {
		printf("All heap blocks were freed -- no leaks are possible\n");
	} else {
		printf("%d bytes leaked !!!\n", m.size);
	}
	printf("total heap usage: %u allocs, %u frees, %u bytes allocated\n",
			m.allocsNum, m.freesNum, m.totalAllocated);
	printf("%s\n", line);
	m.initialized = NULL;
}
