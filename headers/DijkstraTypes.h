#pragma once

#include "commons.h"
#include "list.h"

#define SOMMET_NAME_LENGTH 31 // TOTAL ARRAY LENGTH (INCLUDING `'/0'`)

enum TypeLien {
	LIEN_UNI = 1,
	LIEN_BI = 2,
	ERR = 3
};

typedef enum TypeLien TypeLien;

struct Sommet {
	s_id_t id;
	char name[SOMMET_NAME_LENGTH];

	coord_t x, y, z;
	bool freed : 1;
};

typedef struct Sommet Sommet;

struct Lien {
	s_id_t idA;
	s_id_t idB;

	TypeLien type;
};

typedef struct Lien Lien;

struct Graph {
	Sommet* sommets;
	Lien* liens; 
};

typedef struct Graph Graph;

// ---------------------------------------

bool sommetcmp(Sommet* sA, Sommet* sB);

// Sommets

Sommet makeSommet(s_id_t id, string name, coord_t x, coord_t y, coord_t z);
void printSommet(Sommet sommet);

// List functions

void initializeSommetList(List* list, size_t nElements);
void initializeLienList(List* list, size_t nElements);

void addSommet(List* list, Sommet* sommet);
void freeSommet(Sommet* sommet);

void freeSommetList(List* list);
void freeLienList(List* list);

Sommet* getSommetPtr(List* list, size_t id);
Lien* getLienPtr(List* list, size_t id);

Sommet getSommet(List* list, size_t id);
Lien getLien(List* list, size_t id);

void removeSommet(List* list, size_t index, bool shiftElements);