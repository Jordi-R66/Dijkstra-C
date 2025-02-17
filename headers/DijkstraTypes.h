#pragma once

#include "commons.h"
#include "list.h"

enum TypeLien {
	LIEN_UNI = 1,
	LIEN_BI = 2,
	ERR = 3
};

typedef enum TypeLien TypeLien;

struct Sommet {
	s_id_t id;
	string name;

	double x, y, z;

	s_id_t* neighbours_id;
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

// List functions

void initializeSommetList(List* list, size_t nElements);
void initializeLienList(List* list, size_t nElements);
