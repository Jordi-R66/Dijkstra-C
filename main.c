#include "headers/commons.h"
#include "headers/DijkstraTypes.h"
#include "headers/list.h"
#include "headers/Files.h"

List Vertices;
List Edges;

FileType VerticesType = CSV;
FileType EdgesType = CSV;

void preInit(string verticesFilename, string edgesFilename) {
	Vertices.initialized = false;
	Edges.initialized = false;

	LoadVerticesFromTSV(verticesFilename, &Vertices, VerticesType);
	LoadEdgesFromTSV(edgesFilename, &Edges, EdgesType);

	size_t TotalVertices = Vertices.n_elements;
	size_t TotalEdges = Edges.n_elements;

	
}

int main(void) {
	string sommetsFilename = "France_s.csv";
	string liensFilename = "France_l.csv";

	//printf("Loading vertices in %lX\n", (uint64_t)&Vertices);
	LoadVerticesFromTSV(sommetsFilename, &Vertices, VerticesType);

	//printf("Loading edges in %lX\n", (uint64_t)&Edges);
	LoadLinkFromTSV(liensFilename, &Edges, EdgesType);

	freeLienList(&Edges);
	freeSommetList(&Vertices);

	return EXIT_SUCCESS;
}