#include "headers/commons.h"
#include "headers/DijkstraTypes.h"
#include "headers/list.h"
#include "headers/Files.h"

void main(void) {
	string filename = "France_s.tsv";

	List Vertices;
	Vertices.initialized = false;

	printf("Loading vertices\n");
	LoadVerticesFromTSV(filename, &Vertices);

	printf("Vertices loaded\n");
	freeList(&Vertices);

	return;
}