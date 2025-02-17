#include "Files.h"
#include "DijkstraTypes.h"

const char* READONLY_MODE = "r";
const char sep = '\t';

size_t CountLinesInFile(string filename) {
	FILE* fp = fopen(filename, READONLY_MODE);
	size_t n_entries = 0;

	char c = 0;

	while (c != EOF) {
		c = fgetc(fp);

		if (c == sep) {
			n_entries++;
		}
	}

	fclose(fp);

	return n_entries;
}

void LoadVerticesFromTSV(string filename, List* Vertices) {
	char* endptr;

	size_t n_entries = CountLinesInFile(filename);

	if (n_entries == 0) {
		return;
	}

	FILE* fp = fopen(filename, READONLY_MODE);

	initializeSommetList(Vertices, n_entries);

	// Filling the list

	for (size_t i = 0; i < n_entries; i++) {
		Sommet newSommet = makeSommet(0, "", .0, .0, .0);

		addElement(Vertices, (void*)&newSommet);
	}

	uint8_t colNumber = 0;
	s_id_t currentEntry = 0;

	s_id_t id;
	double x, y, z;

	string current_id = (string)calloc(25, sizeof(char));
	string current_name = (string)calloc(SOMMET_NAME_LENGTH, sizeof(char));

	string current_x = (string)calloc(40, sizeof(char));
	string current_y = (string)calloc(40, sizeof(char));
	string current_z = (string)calloc(40, sizeof(char));

	char c;

	bool fileClosed = false;

	while (c != EOF) {
		c = getc(fp);

		if (c == EOF) {
			fclose(fp);

			free(current_id);
			free(current_name);
			free(current_x);
			free(current_y);
			free(current_z);

			fileClosed = true;

			break;
		}

		/*
		if (c != sep) {
			switch (currentEntry) {
				case 0:
					current_id[iCol] = c;
					break;

				case 1:
					current_id[iCol] = c;
					break;

				case 2:
					current_id[iCol] = c;
					break;

				case 3:
					current_id[iCol] = c;
					break;

				case 4:
					current_id[iCol] = c;
					break;
			}
		}
		*/

		if (c == sep) {
			colNumber++;
		} else if (c == '\n') {
			colNumber = 0;

			id = strtol(current_id, &endptr, 10);

			x = strtod(current_x, &endptr);
			y = strtod(current_y, &endptr);
			z = strtod(current_z, &endptr);
		}
	}

	if (!fileClosed) {
		fclose(fp);

		free(current_id);
		free(current_name);
		free(current_x);
		free(current_y);
		free(current_z);
	}
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

	Lien work = {0, 0, 0};

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

		if (c == sep) {
			colNumber++;
			colNumber %= 3;
		} else if (c == '\n') {
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
