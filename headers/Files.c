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

	initializeList(Vertices, n_entries, sizeof(Sommet));

	uint8_t colNumber = 0;
	s_id_t currentEntry = 0;



	if (n_entries > 0) {

	}
}

void LoadLinkFromTSV(string filename, List* Links) {

}