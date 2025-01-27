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

void resizeList(List* list, size_t newSize) {
	if (newSize < list->n_elements) {
		newSize = list->n_elements;
	}

	void* ptr = (void*)realloc(list->elements, newSize);

	if (ptr != NULL) {
		list->elements = ptr;
	} else {
		exit(EXIT_FAILURE);
	}
}

void addElement(List* list, size_t index, void* newElement) {
	if ((list->n_elements + 1) >= list->capacity) {
		resizeList(list, list->n_elements + 2);
	}

	size_t nBytes = list->n_elements * list->elementSize;
	memset((int8_t*)list->elements + nBytes, newElement, list->elementSize);

	list->n_elements++;
}

void removeElement(List* list, size_t index, bool shiftElements) {
	if (index >= list->n_elements) {
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

		size_t bytesToCopy = (list->n_elements - (i + 1)) * list->elementSize;

		memmove((int8_t*)list->elements + nBytesI, (int8_t*)list->elements + nBytesJ, bytesToCopy);
	}
}

void replaceElement(List* list, size_t index, void* newElement) {
	size_t nBytes = index * list->elementSize;
	removeElement(list, index, false);
	memset((int8_t*)list->elements + nBytes, newElement, list->elementSize);
}
