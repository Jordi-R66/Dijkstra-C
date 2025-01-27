#pragma once

#include "commons.h"

struct List {
	size_t capacity;
	size_t n_elements;
	size_t elementSize;

	void* elements;
};

typedef struct List List;

void initializeList(List* list, size_t initSize, size_t elementSize);
void freeList(List* list);

void resizeList(List* list, size_t newSize);

