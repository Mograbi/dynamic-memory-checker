/*
 * test_unit.c
 *
 *  Created on: May 20, 2016
 *      Author: Moawiya
 */

#include "MemoryChecker.h"

int main(void) {
	//initMemory();

	int* i = allocate(sizeof(int));
	deallocate(i,sizeof(int));

	finishMemory();
	return 0;
}
