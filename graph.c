#include "graph.h"
# define MAX_VTX 4096

struct _Graph {
Vertex *vertices[MAX_VTX]; /*!<Array with the graph
vertices */
Bool connections[MAX_VTX][MAX_VTX]; /*!<Adjacency matrix */
int num_vertices; /*!<Total number of vertices */
int num_edges; /*!<Total number of edges */
};

Graph * graph_init(){
	Graph *g=(Graph*)malloc(sizeof(Graph));
	if(g==NULL){
	return NULL;
	}
	return g;
}

void graph_free(Graph *g){
	free(g);
}

Status graph_newVertex(Graph *g, char *desc){
	if( g==NULL){
	return ERROR;
	}
	v*=vertex_initFromString(desc);
	if(v==NULL){
	return ERROR;
	}
	if(graph_contains(g, v->id)){
	free(v);
	return OK;
	else
	g->vertices=v;
	num_vertices=num_vertices+1;
	return OK;
}

Status graph_newEdge(Graph *g, long orig, long dest){
	
}

Bool graph_contains(const Graph *g, long id){
	
}

int graph_getNumberOfVertices(const Graph *g){
	if(g==NULL){
	return -1;
	}
	return g->num_vertices;
}

int graph_getNumberOfEdges(const Graph *g){
	if(g==NULL){
	return -1;
	}
	return g->num_edges;
}

Bool graph_connectionExists(const Graph *g, long orig, long dest){
	
}

int graph_getNumberOfConnectionsFromId(const Graph *g, long id){
	
}

long *graph_getConnectionsFromId(const Graph *g, long id){
	
}

int graph_getNumberOfConnectionsFromTag(const Graph *g, char *tag){
	
}

long *graph_getConnectionsFromTag(const Graph *g, char *tag){
	
}

int graph_print (FILE *pf, const Graph *g){
	
}

Status graph_readFromFile (FILE *fin, Graph *g){
	
}
