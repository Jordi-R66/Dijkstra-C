#pragma once

#include "commons.h"
#include "list.h"

typedef enum {
	CSV = 0,
	TSV = 1
} FileType;

typedef enum {
	SOMMET_ID = 0,
	SOMMET_NAME = 1,
	SOMMET_X = 2,
	SOMMET_Y = 3,
	SOMMET_Z = 4
} Sommet_Fields;

typedef enum {
	A_ID = 0,
	B_ID = 1,
	TYPE = 2
} Liens_Fields;

void LoadVerticesFromTSV(string filename, List* Vertices, FileType fileType);
void LoadLinkFromTSV(string filename, List* Links, FileType fileType);