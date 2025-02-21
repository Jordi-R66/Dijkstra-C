#include "DijkstraTypes.h"

bool sommetcmp(Sommet* sA, Sommet* sB) {
	return (sA->id) == (sB->id);
}

Sommet makeSommet(s_id_t id, string name, double x, double y, double z) {
	size_t lenStr = strlen(name);

	Sommet output;
	output.name_ptr = (string*)calloc(1, sizeof(string));

	if (output.name_ptr == (string*)NULL) {
		exit(EXIT_FAILURE);
	}

	output.id = id;
	strcpy(*(output.name_ptr), name);

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

void addSommet(List* list, Sommet* sommet) {
	if ((list->n_elements + 1) >= list->capacity) {
		if (list->capacity <= 10) {
			resizeList(list, list->n_elements + 5);
		} else {
			resizeList(list, (size_t)(list->n_elements * 1.5f));
		}
	}

	size_t nBytes = list->n_elements * list->elementSize;
	Sommet* dest = (Sommet*)((size_t*)list->elements + nBytes);
	memcpy(dest, sommet, list->elementSize);

	list->n_elements++;
}

void freeSommet(Sommet* sommet) {
	if (sommet->name_ptr != (string*)NULL) {
		if (*(sommet->name_ptr) != (string)NULL) {
			free(*(sommet->name_ptr));
		}

		free(sommet->name_ptr);
	}
}

void freeSommetList(List* list) {
	printf("Entree du for\n");

	for (size_t i = 0; i < list->n_elements; i++) {

		printf("\tAvant de get %llu\n", i);
		Sommet* s = getSommetPtr(list, i);

		printf("\tAvant de free (%llX)\n", (uint64_t)s);

		freeSommet(s);

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
	free(s->name_ptr);

	removeElement(list, index, shiftElements);
}