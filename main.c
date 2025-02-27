#include "headers/commons.h"
#include "headers/DijkstraTypes.h"
#include "headers/list.h"
#include "headers/Files.h"

int main(void) {
	string filename = "France_s.csv";

	List Vertices;
	Vertices.initialized = false;

	printf("Loading vertices in %lX\n", (uint64_t)&Vertices);
	LoadVerticesFromTSV(filename, &Vertices);

	printf("Vertices loaded in %lX\n", (uint64_t)&Vertices);
	freeSommetList(&Vertices);

	return EXIT_SUCCESS;
}