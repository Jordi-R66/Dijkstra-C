#include "list.h"

#include <string.h>

void initializeList(List* list, size_t initSize, size_t elementSize) {
	list->capacity = initSize;
	list->n_elements = 0;
	list->elementSize = elementSize;
	list->fragmented = false;

	void* ptr = (void*)calloc(initSize, elementSize);

	if (ptr != NULL) {
		list->elements = ptr;
	} else {
		free(ptr);
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

void resizeList(List* list, size_t newSize) {
	if (newSize < list->n_elements) {
		newSize = list->n_elements;
	}

	void* ptr = (void*)realloc(list->elements, newSize);

	if (ptr != NULL) {
		list->elements = ptr;
	} else {
		free(ptr);
		fprintf(stderr, "Reallocation failure in `resizeList(%p, index)`\n", (void*)list);
		exit(EXIT_FAILURE);
	}
}

void addElement(List* list, void* newElement) {
	if ((list->n_elements + 1) >= list->capacity) {
		resizeList(list, list->n_elements + 2);
	}

	size_t nBytes = list->n_elements * list->elementSize;
	memset((int8_t*)list->elements + nBytes, newElement, list->elementSize);

	list->n_elements++;
}

void removeElement(List* list, size_t index, bool shiftElements) {
	if (index >= list->n_elements) {
		fprintf(stderr, "Can't remove an element that is not in a list\n");
		exit(EXIT_FAILURE);
	}

	if (shiftElements == NULL) {
		shiftElements = true;
	}

	size_t nBytes = index * list->elementSize;

	memset((int8_t*)list->elements + nBytes, 0, list->elementSize);

	if (shiftElements) {
		size_t i = index;
		size_t j = index + 1;

		size_t nBytesI = i * list->elementSize;
		size_t nBytesJ = j * list->elementSize;

		size_t bytesToCopy = (list->n_elements - j) * list->elementSize;

		memmove((int8_t*)list->elements + nBytesI, (int8_t*)list->elements + nBytesJ, bytesToCopy);

		list->n_elements--;
	} else {
		list->fragmented |= true;
	}
}

void replaceElement(List* list, size_t index, void* newElement) {
	if (index >= list->capacity) {
		fprintf(stderr, "Can't replace an element outside of a list\n");
		exit(EXIT_FAILURE);
	}

	size_t nBytes = index * list->elementSize;

	removeElement(list, index, false);
	memcpy((int8_t*)list->elements + nBytes, newElement, list->elementSize);

	list->fragmented = false;
}

size_t shrinkToFit(List* list) {
	if (list->fragmented) {
		fprintf(stderr, "Can't shrink a list if it is fragmented\n");
		exit(EXIT_FAILURE);
	}

	resizeList(list, list->n_elements);

	return list->capacity;
}

void copyList(List* listDest, List* listSrc) {
	memset(listDest, listSrc, sizeof(listSrc));

	void* ptr = calloc(listDest->capacity, listDest->elementSize);

	if (ptr != NULL) {
		listDest->elements = ptr;
	} else {
		free(ptr);
		exit(EXIT_FAILURE);
	}

	memset(listDest->elements, listSrc->elements, listSrc->capacity * listSrc->elementSize);
}