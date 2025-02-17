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