#include "DijkstraTypes.h"

bool sommetcmp(Sommet* sA, Sommet* sB) {
	return (sA->id) == (sB->id);
}

Sommet makeSommet(s_id_t id, string name, double x, double y, double z) {
	Sommet output;

	strcpy(output.name, name);

	output.id = id;

	output.x = x;
	output.y = y;
	output.z = z;

	return output;
}

void printSommet(Sommet sommet) {
	printf("Sommet %ld\nName : %s\nx : %lf\ny : %lf\nz : %lf\n---------------------------------------------\n", sommet.id, sommet.name, sommet.x, sommet.y, sommet.z);
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
	removeElement(list, index, shiftElements);
}