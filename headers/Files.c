#include "Files.h"
#include "DijkstraTypes.h"

const char* READONLY_MODE = "r";
const char sep = '\t';

size_t CountLinesInFile(FILE* fp) {
	size_t n_entries = 0;

	char c;

	do {
		c = fgetc(fp);

		if (c == '\n') {
			n_entries++;
		}
	} while (c != EOF);

	fseek(fp, 0, SEEK_SET);
	return n_entries;
}

void LoadVerticesFromTSV(string filename, List* Vertices) {
	char** endptr;

	FILE* fp = fopen(filename, READONLY_MODE);

	size_t n_entries = CountLinesInFile(fp);

	if (n_entries == 0) {
		return;
	}

	initializeList(Vertices, n_entries, sizeof(Sommet));

	uint8_t colNumber = 0;
	s_id_t currentEntry = 0;

	Sommet work = {0, "", 0, 0, 0, (s_id_t*)NULL};

	s_id_t id;
	double x, y, z;

	string current_id = (string)calloc(25, sizeof(char));

	string current_x = (string)calloc(40, sizeof(char));
	string current_y = (string)calloc(40, sizeof(char));
	string current_z = (string)calloc(40, sizeof(char));

	char c;

	while (c != EOF) {
		c = getc(fp);
		printf("%c", c);

		if (c == EOF) {
			printf("\nEOF !!\n");
			//fclose(fp);
			break;
		}

		if (c == sep) {
			colNumber++;
		} else if (c == '\n') {

			id = strtol(current_id, endptr, 10);

			x = strtod(current_x, endptr);
			y = strtod(current_y, endptr);
			z = strtod(current_z, endptr);
		}
	}

	fclose(fp);
}

void LoadLinkFromTSV(string filename, List* Links) {

}