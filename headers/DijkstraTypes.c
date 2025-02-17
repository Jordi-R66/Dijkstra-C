#include "DijkstraTypes.h"

bool sommetcmp(Sommet* sA, Sommet* sB) {
	return (sA->id) == (sB->id);
}

// List functions

void initializeSommetList(List* list, size_t nElements) {
	initializeList(list, nElements, sizeof(Sommet));
}

void initializeLienList(List* list, size_t nElements) {
	initializeList(list, nElements, sizeof(Lien));
}

void freeSommetList(List* list) {
	for (size_t i = 0; i < list->n_elements; i++) {
		Sommet* s = getSommet(list, i);
		free(s->name);
	}

	freeList(list);
}

void freeLienList(List* list) {
	freeList(list);
}

Sommet* getSommet(List* list, size_t id) {
	return (Sommet*)getElement(list, id);
}

Lien* getLien(List* list, size_t id) {
	return (Lien*)getElement(list, id);
}