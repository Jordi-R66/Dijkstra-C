#include "list.h"

#include <string.h>

void initializeList(List* list, size_t initSize, size_t elementSize) {
	list->capacity = initSize;
	list->n_elements = 0;
	list->elementSize = elementSize;

	void* ptr = (void*)calloc(initSize, elementSize);

	if (ptr != NULL) {
		list->elements = ptr;
	} else {
		exit(EXIT_FAILURE);
	}
}

void freeList(List* list) {
	memset(list->elements, 0, list->capacity * list->elementSize);

	free(list->elements);

	list->capacity = 0;
	list->elementSize = 0;
	list->n_elements = 0;
}

