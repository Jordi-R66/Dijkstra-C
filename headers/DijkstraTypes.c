#include "DijkstraTypes.h"

bool sommetcmp(Sommet* sA, Sommet* sB) {
	return (sA->id) == (sB->id);
}

Sommet makeSommet(s_id_t id, string name, double x, double y, double z) {
	size_t lenStr = strlen(name);

	Sommet output;
	output.name = (string)calloc(SOMMET_NAME_LENGTH, sizeof(char));

	if (output.name == (string)NULL) {

	}

	output.id = id;
	strcpy(output.name, name);


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
	void* element_ptr = getElement(list, id);
	return (Sommet*)element_ptr;
}

Lien* getLien(List* list, size_t id) {
	return (Lien*)getElement(list, id);
}

void removeSommet(List* list, size_t index, bool shiftElements) {
	Sommet* s = getSommet(list, index);
	free(s->name);

	removeElement(list, index, shiftElements);
}