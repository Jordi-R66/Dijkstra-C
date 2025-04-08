#include "headers/commons.h"
#include "headers/DijkstraTypes.h"
#include "headers/list.h"
#include "headers/Files.h"

int main(void) {
	string sommetsFilename = "France_s.csv";
	string liensFilename = "France_l.csv";

	List Vertices;
	List Edges;
	FileType VerticesType = CSV;
	FileType EdgesType = CSV;

	Vertices.initialized = false;
	Edges.initialized = false;

	//printf("Loading vertices in %lX\n", (uint64_t)&Vertices);
	LoadVerticesFromTSV(sommetsFilename, &Vertices, VerticesType);

	//printf("Loading edges in %lX\n", (uint64_t)&Edges);
	LoadLinkFromTSV(liensFilename, &Edges, EdgesType);

	freeLienList(&Edges);
	freeSommetList(&Vertices);

	return EXIT_SUCCESS;
}