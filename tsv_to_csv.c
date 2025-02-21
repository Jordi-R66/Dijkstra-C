#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if (argc != 3) {
		fprintf(stderr, "Must give a source name AND a dest name\n");
		exit(EXIT_FAILURE);
	}

	FILE *fp_in, *fp_out;

	fp_in = fopen(argv[1], "r");
	fp_out = fopen(argv[2], "w");

	char c = 0;

	do {
		c = getc(fp_in);

		c = c == '\t' ? ',' : c;

		fwrite(&c, 1, 1, fp_out);
	} while (c != EOF);

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}