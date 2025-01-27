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

void addElement(List* list, size_t index, void* newElement);
void removeElement(List* list, size_t index, bool shiftElements);
void replaceElement(List* list, size_t index, void* newElement);

void copyList(List* listDest, List* listSrc);