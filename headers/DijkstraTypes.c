#include "DijkstraTypes.h"

bool sommetcmp(Sommet* sA, Sommet* sB) {
	return (sA->id) == (sB->id);
}

string copyAndCreateStr(string source) {
	string newStr = (string)calloc(SOMMET_NAME_LENGTH, sizeof(char));

	if (newStr != NULL) {
		strcpy(newStr, source);
	} else {
		fprintf(stderr, "Couldn't allocate space for the string\n");
		exit(EXIT_FAILURE);
	}

	return newStr;
}

Sommet makeSommet(s_id_t id, string name, double x, double y, double z) {
	Sommet output;

	if (output.name_ptr == (string)NULL) {
		fprintf(stderr, "Couldn't allocate space for the string's pointer\n");
		exit(EXIT_FAILURE);
	}

	output.name_ptr = copyAndCreateStr(name);

	output.id = id;

	output.x = x;
	output.y = y;
	output.z = z;

	output.freed = false;

	return output;
}

void printSommet(Sommet sommet) {
	printf("Sommet %llu\nName : %s\nx : %lf\ny : %lf\nz : %lf\n---------------------------------------------\n", sommet.id, sommet.name_ptr, sommet.x, sommet.y, sommet.z);
}

// List functions

void initializeSommetList(List* list, size_t nElements) {
	initializeList(list, nElements, sizeof(Sommet));
}

void initializeLienList(List* list, size_t nElements) {
	initializeList(list, nElements, sizeof(Lien));
}

void addSommet(List* list, Sommet* sommet) {
	if ((list->n_elements + 1) >= list->capacity) {
		resizeList(list, list->n_elements + 50);
	}

	size_t nBytes = list->n_elements * list->elementSize;
	Sommet* dest = (Sommet*)((size_t*)list->elements + nBytes);
	memcpy(dest, sommet, list->elementSize);

	list->n_elements++;
}

void freeSommet(Sommet* sommet) {
	if ((sommet->name_ptr != (string)NULL) && (sommet->freed == false)) {
		free(sommet->name_ptr);
		sommet->freed = true;
	}
}

void freeSommetList(List* list) {
	for (size_t i = 0; i < list->n_elements; i++) {
		removeSommet(list, i, false);
	}

	freeList(list);
}

void freeLienList(List* list) {
	freeList(list);
}

Sommet* getSommetPtr(List* list, size_t id) {
	void* element_ptr = getElement(list, id);
	return (Sommet*)element_ptr;
}

Lien* getLienPtr(List* list, size_t id) {
	return (Lien*)getElement(list, id);
}

void removeSommet(List* list, size_t index, bool shiftElements) {
	freeSommet(getSommetPtr(list, index));

	removeElement(list, index, shiftElements);
}