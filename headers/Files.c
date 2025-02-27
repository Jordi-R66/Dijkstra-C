#include "Files.h"
#include "DijkstraTypes.h"

#define NB_COLS 5
#define SEP '\t'

const char* READONLY_MODE = "r";

size_t CountLinesInFile(string filename) {
	FILE* fp = fopen(filename, READONLY_MODE);
	size_t n_entries = 0;

	char c = 0;

	while (c != EOF) {
		c = fgetc(fp);

		if (c == '\n') {
			n_entries++;
		}
	}

	fclose(fp);

	return n_entries;
}

void LoadVerticesFromTSV(string filename, List* Vertices) {
	char* endptr;

	char buffer[128];

	size_t n_entries = CountLinesInFile(filename);

	printf("%llu Sommets\n", n_entries);

	if (n_entries == 0) {
		return;
	}

	FILE* fp = fopen(filename, READONLY_MODE);

	initializeSommetList(Vertices, n_entries);

	uint8_t colNumber = 0;
	s_id_t currentEntry = 0;

	s_id_t id;
	coord_t x, y, z;

	char current_id[25];
	char current_name[SOMMET_NAME_LENGTH];

	char current_x[40];
	char current_y[40];
	char current_z[40];

	memset(current_id, 0, 25);
	memset(current_name, 0, SOMMET_NAME_LENGTH);
	memset(current_x, 0, 40);
	memset(current_y, 0, 40);
	memset(current_z, 0, 40);

	bool fileClosed = false;

	char c = '\0';

	uint8_t nBornes;

	while (c != EOF) {
		c = getc(fp);

		if (c == EOF) {
			break;
		}

		if (c == SEP) {
			//printf(", ");
			nBornes++;
			colNumber = 0;
		} else if (c == '\n') {
			//printf("%c", c);
			id = strtol(current_id, &endptr, 10);

			x = strtod(current_x, &endptr);
			y = strtod(current_y, &endptr);
			z = strtod(current_z, &endptr);

			Sommet s = makeSommet(id, current_name, x, y, z);
			printSommet(s);

			addSommet(Vertices, &s);

			memset(current_id, 0, 25);
			memset(current_name, 0, SOMMET_NAME_LENGTH);
			memset(current_x, 0, 40);
			memset(current_y, 0, 40);
			memset(current_z, 0, 40);

			nBornes = 0;
			colNumber = 0;
		} else {
			//printf("%c", c);
			switch (nBornes) {
				case 0:
					current_id[colNumber] = c;
					break;

				case 1:
					current_name[colNumber] = c;
					break;

				case 2:
					current_x[colNumber] = c;
					break;

				case 3:
					current_y[colNumber] = c;
					break;

				case 4:
					current_z[colNumber] = c;
					break;

				default:
					break;
			}
		}
	}

	printf("Sortie de la while\n");

	//fclose(fp);

	//shrinkToFit(Vertices);

	size_t capacity, capacity_bytes, size, size_bytes, diff, diff_bytes;

	capacity = Vertices->capacity;
	capacity_bytes = capacity * (Vertices->elementSize + SOMMET_NAME_LENGTH);

	size = Vertices->n_elements;
	size_bytes = size * (Vertices->elementSize + SOMMET_NAME_LENGTH);

	diff = capacity - size;
	diff_bytes = capacity_bytes - size_bytes;

	printf("Been through %llu entries\n\nVertices capacity : %llu (%llu bytes)\nVertices size : %llu (%llu bytes)\nDifference : %llu (%llu bytes)\n", currentEntry, capacity, capacity_bytes, size, size_bytes, diff, diff_bytes);
}

void LoadLinkFromTSV(string filename, List* Links) {
	char* endptr;

	size_t n_entries = CountLinesInFile(filename);

	if (n_entries == 0) {
		return;
	}

	FILE* fp = fopen(filename, READONLY_MODE);

	initializeLienList(Links, n_entries);

	uint8_t colNumber = 0;
	s_id_t currentEntry = 0;

	Lien work = { 0, 0, 0 };

	s_id_t idA, idB;
	TypeLien typeLien;

	string current_idA = (string)calloc(25, sizeof(char));
	string current_idB = (string)calloc(25, sizeof(char));
	string current_TypeLien = (string)calloc(2, sizeof(char));

	char c;

	bool fileClosed = false;

	while (c != EOF) {
		c = getc(fp);

		if (c == EOF) {
			fclose(fp);

			free(current_idA);
			free(current_idB);
			free(current_TypeLien);

			fileClosed = true;

			break;
		}

		if (c == SEP) {
			colNumber++;
			colNumber %= 3;
		}
		else if (c == '\n') {
			colNumber = 0;
			idA = strtoull(current_idA, &endptr, 10);
			idB = strtoull(current_idB, &endptr, 10);
			typeLien = strtol(current_TypeLien, &endptr, 10);
		}
	}

	if (!fileClosed) {
		fclose(fp);
	}
}
