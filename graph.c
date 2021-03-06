#include "graph.h"
#include "vertex.h"
#
# define MAX_VTX 4096
#define TAG_LENGTH 64

struct _Graph {
Vertex *vertices[MAX_VTX]; /*!<Array with the graph
vertices */
Bool connections[MAX_VTX][MAX_VTX]; /*!<Adjacency matrix */
int num_vertices; /*!<Total number of vertices */
int num_edges; /*!<Total number of edges */
};
/*Funciones privadas*/
Status  graph_connections_update(Graph *g);
/*Definición de funciones*/
Graph * graph_init(){
	Graph *g=(Graph*)malloc(sizeof(Graph));
	if(g==NULL){
		return NULL;
	}
	g->num_vertices=0;
	g->num_edges=0;
	
	return g;
}

void graph_free(Graph *g){
	int i=0;
	for(i=0;i<g->num_vertices;i++){
		vertex_free(g->vertices[i]);
		}
	free(g);
}

Status graph_newVertex(Graph *g, char *desc){
	if( g==NULL){
		return ERROR;
	}
	Vertex *v=vertex_initFromString(desc);
	if(v==NULL){
		return ERROR;
	}
	
	if(graph_contains(g, vertex_getId (v))){
		free(v);
		return OK;
	}
	else{	
		free(v);
		g->vertices[g->num_vertices]=vertex_initFromString(desc);
		g->num_vertices++;
		if(graph_connections_update(g)==ERROR){
			g->vertices[g->num_vertices]=NULL;
			g->num_vertices--;
			printf("Error al actualizar las conexiones");
			return ERROR;
			}
	    }

	return OK;
	
}

Status graph_newEdge(Graph *g, long orig, long dest){
	if(g==NULL || !graph_contains(g,orig) || !graph_contains(g,dest)){
	return ERROR;
	}
	g->connections[orig][dest]=TRUE;
	g->num_edges=g->num_edges+1;
	return OK;
}

Bool graph_contains(const Graph *g, long id){
	for(int i=0; i<g->num_vertices ; i++){
		if(vertex_getId(g->vertices[i])==id){
			return TRUE;
		}
   	}
   	return FALSE;
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
	if(g==NULL){
		return FALSE;
	}
	if (g->connections[orig][dest]==TRUE){
		return TRUE;
		}
	return FALSE;	
}

int graph_getNumberOfConnectionsFromId(const Graph *g, long id){
	int i,contador=0;
	for(i=0;i<g->num_vertices;i++){
		if(graph_connectionExists(g,id,vertex_getId (g->vertices[i]))){
			contador++;
			}
		}
	return contador;
	
}

long *graph_getConnectionsFromId(const Graph *g, long id){
	if(g==NULL) return NULL;
	int contador=0;
	long *conexiones=(long*) malloc(graph_getNumberOfConnectionsFromId(g,id)*sizeof(long));
	for(int i=0;i<g->num_vertices;i++){
		if(graph_connectionExists(g,id,vertex_getId (g->vertices[i]))){
			conexiones[contador]=vertex_getId (g->vertices[i]);
			contador++;
			}
		}
		return conexiones;
}

int graph_getNumberOfConnectionsFromTag(const Graph *g, char *tag){
	int seleccion=0;
	if(g==NULL || strlen(tag)<=0){
		return -1;
	}
	for(int i =0;i<g->num_vertices;i++){
		if(strcmp(tag,vertex_getTag (g->vertices[i]))==0){
			seleccion=i;
	}	
}
return graph_getNumberOfConnectionsFromId(g,vertex_getId (g->vertices[seleccion]));
}

long *graph_getConnectionsFromTag(const Graph *g, char *tag){
	int contador=0,seleccion=0;
	if(g==NULL || strlen(tag)<=0){
		return NULL;
	}
	long *conexiones=(long*) malloc(graph_getNumberOfConnectionsFromTag(g,tag)*sizeof(long));
	
	for(int i =0;i<g->num_vertices;i++){
		if(strcmp(tag,vertex_getTag (g->vertices[i]))==0){
			seleccion=i;
		}
	}
	for(int i=0;i<g->num_vertices;i++){
		if(graph_connectionExists(g,vertex_getId (g->vertices[seleccion]),vertex_getId (g->vertices[i]))){
			conexiones[contador]=vertex_getId (g->vertices[i]);
			contador++;
			}
		}
		return conexiones;
	
}

int graph_print (FILE *pf, const Graph *g){
	if(g==NULL) return -1;
	fprintf(stdout,"\nGraph:");
	for(int i =0;i<g->num_vertices;i++){
		fprintf(stdout,"\n");
		vertex_print (pf, g->vertices[i]);
		fprintf(stdout,": ");
		for(int j=0; j<g->num_vertices;j++){
			if(graph_connectionExists(g,vertex_getId (g->vertices[i]),vertex_getId (g->vertices[j]))){
			vertex_print (pf, g->vertices[j]);
			}
		}
	}
	printf("\n");
	return 1;
}
Status graph_connections_update(Graph *g){
	int NV=g->num_vertices;
	int i=0;
	if(g==NULL) return ERROR;
	for(i=0;i<NV;i++){
		g->connections[vertex_getId (g->vertices[i])][vertex_getId (g->vertices[g->num_vertices-1])]=FALSE;
	}
	return OK;
}

Status graph_readFromFile (FILE *fin, Graph *g){
	int cont;
	if(fin==NULL || g==NULL){
		return ERROR;
		}
	int l1, l2;
	char desc[50];	
	if(fscanf(fin, "%d\n", &cont)==-1) return ERROR;

	for (g->num_vertices=0;g->num_vertices<cont;){
		if(fgets(desc , 100, fin)==NULL) return ERROR;
		if(graph_newVertex(g,desc)==ERROR)return ERROR;

	}
	while(fscanf(fin, "%d %d", &l1, &l2) == 2){
		graph_newEdge(g, l1, l2);
	}
	return OK;
}



