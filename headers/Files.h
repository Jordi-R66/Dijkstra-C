#pragma once

#include "commons.h"
#include "list.h"

typedef enum {
	SOMMET_ID = 0,
	SOMMET_NAME = 1,
	SOMMET_X = 2,
	SOMMET_Y = 3,
	SOMMET_Z = 4
} Sommet_Fields;

void LoadVerticesFromTSV(string filename, List* Vertices);
void LoadLinkFromTSV(string filename, List* Links);