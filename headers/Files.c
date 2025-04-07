#include "Files.h"
#include "DijkstraTypes.h"

#define NB_COLS 5
#define COL_SEP ','

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

	memset(buffer, 0, 128);

	size_t n_entries = CountLinesInFile(filename);

	if (n_entries == 0) {
		return;
	}

	FILE* fp = fopen(filename, READONLY_MODE);

	initializeSommetList(Vertices, n_entries);

	Sommet* Sommets = (Sommet*)Vertices->elements;

	uint8_t colNumber = 0;
	s_id_t currentEntry = 0;

	s_id_t id;

	char c = 0;
	uint8_t currentField = 0;
	uint8_t fieldLength = 0;

	const char field_sep = ',';
	bool canLoad = false;

	while (c != EOF) {
		c = fgetc(fp);

		if (c == EOF) {
			break;
		}

		if ((c != ',') && (c != '\n')) {
			buffer[fieldLength++] = c;
		} else {

			switch (currentField) {
				case SOMMET_ID:
					id = strtoll(buffer, &endptr, 10);

					Sommets[currentEntry] = makeSommet(id, "", 0.0, 0.0, 0.0);
					canLoad = false;
					break;

				case SOMMET_NAME:
					strcpy(Sommets[currentEntry].name, buffer);
					break;

				case SOMMET_X:
					Sommets[currentEntry].x = strtod(buffer, &endptr);
					break;

				case SOMMET_Y:
					Sommets[currentEntry].y = strtod(buffer, &endptr);
					break;

				case SOMMET_Z:
					Sommets[currentEntry].z = strtod(buffer, &endptr);
					canLoad = true;
					break;

				default:
					break;
			}

			if (canLoad) {
				Vertices->n_elements++;
			}

			memset(buffer, 0, 128);
			fieldLength = 0;

			if (c == '\n') {
				currentField = 0;
				currentEntry++;
			} else {
				currentField++;
			}
		}
	}

	fclose(fp);

	shrinkToFit(Vertices);

	size_t capacity, capacity_bytes, size, size_bytes, diff, diff_bytes;

	/*
	capacity = Vertices->capacity;
	capacity_bytes = capacity * (Vertices->elementSize + SOMMET_NAME_LENGTH);

	size = Vertices->n_elements;
	size_bytes = size * (Vertices->elementSize + SOMMET_NAME_LENGTH);

	diff = capacity - size;
	diff_bytes = capacity_bytes - size_bytes;

	printf("Been through %ld entries\n\nVertices capacity : %zu (%zu bytes)\nVertices size : %zu (%zu bytes)\nDifference : %zu (%zu bytes)\n", currentEntry, capacity, capacity_bytes, size, size_bytes, diff, diff_bytes);
	*/
}

void LoadLinkFromTSV(string filename, List* Links) {
	char* endptr;

	size_t n_entries = CountLinesInFile(filename);

	char buffer[128];
	memset(buffer, 0, 128);

	if (n_entries == 0) {
		return;
	}

	FILE* fp = fopen(filename, READONLY_MODE);

	initializeLienList(Links, n_entries);
	Lien* Liens = (Lien*)Links->elements;

	char c = 0;

	uint8_t currentEntry = 0;
	uint8_t currentField = 0;
	uint8_t fieldLength = 0;

	bool canLoad = false;

	while (c != EOF) {
		c = fgetc(fp);

		if (c == EOF) {
			break;
		}

		if ((c != ',') && (c != '\n')) {
			buffer[fieldLength++] = c;
		} else {
			switch (currentField) {
				case A_ID:
					memset(&Liens[currentEntry], 0, Links->elementSize);

					Liens[currentEntry].idA = strtoll(buffer, &endptr, 10);
					canLoad = false;
					break;

				case B_ID:
					Liens[currentEntry].idB = strtoll(buffer, &endptr, 10);
					break;

				case TYPE:
					Liens[currentEntry].type = strtol(buffer, &endptr, 10);
					canLoad = true;
					break;

				default:
					break;
			}

			if (canLoad) {
				Links->n_elements++;
			}

			memset(buffer, 0, 128);
			fieldLength = 0;

			if (c == '\n') {
				currentField = 0;
				currentEntry++;
			} else {
				currentField++;
			}
		}
	}

	fclose(fp);

	shrinkToFit(Links);
}
