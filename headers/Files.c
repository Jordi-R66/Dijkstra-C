#include "Files.h"

const char READONLY_MODE = 'r';
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

	return n_entries;
}

void LoadVerticesFromTSV(string filename, List* Vertices) {

}

void LoadLinkFromTSV(string filename, List* Links) {

}