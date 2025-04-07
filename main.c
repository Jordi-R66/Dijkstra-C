#include "headers/commons.h"
#include "headers/DijkstraTypes.h"
#include "headers/list.h"
#include "headers/Files.h"

int main(void) {
	string sommetsFilename = "France_s.csv";
	string liensFilename = "France_l.csv";

	List Vertices;
	List Edges;

	Vertices.initialized = false;
	Edges.initialized = false;

	//printf("Loading vertices in %lX\n", (uint64_t)&Vertices);
	//LoadVerticesFromTSV(sommetsFilename, &Vertices);

	printf("Loading edges in %lX\n", (uint64_t)&Edges);
	LoadLinkFromTSV(liensFilename, &Edges);

	printf("Vertices loaded in %lX\n", (uint64_t)&Vertices);
	freeSommetList(&Vertices);

	return EXIT_SUCCESS;
}