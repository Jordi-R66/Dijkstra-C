#include "DijkstraTypes.h"

bool sommetcmp(Sommet* sA, Sommet* sB) {
	return (sA->id) == (sB->id);
}

Sommet makeSommet(s_id_t id, string name, double x, double y, double z) {
	size_t lenStr = strlen(name);

	Sommet output;
	output.name = (string)calloc(SOMMET_NAME_LENGTH, sizeof(char));

	if (output.name == (string)NULL) {
		exit(EXIT_FAILURE);
	}

	output.id = id;
	strcpy(output.name, name);

	output.x = x;
	output.y = y;
	output.z = z;

	return output;
}

// List functions

void initializeSommetList(List* list, size_t nElements) {
	initializeList(list, nElements, sizeof(Sommet));
}

void initializeLienList(List* list, size_t nElements) {
	initializeList(list, nElements, sizeof(Lien));
}

void freeSommetList(List* list) {
	printf("Entree du for\n");
	for (size_t i = 0; i < list->n_elements; i++) {
		printf("\tAvant de get %llu\n", i);
		Sommet* s = getSommetPtr(list, i);
		printf("\tAvant de free (%llX)\n", (uint64_t)s);
		free(s->name);
		printf("\tApres avoir free\n\n");
	}

	printf("Sortie du for\n");

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
	Sommet* s = getSommetPtr(list, index);
	free(s->name);

	removeElement(list, index, shiftElements);
}