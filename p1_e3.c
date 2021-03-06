#include "vertex.h"
#include "types.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	if(argc != 2){
		printf("Error al introducir los argumentos. Introdúzcalos de la forma: ./argumento1 		argumento2.txt");
		return 0;
	}
	Graph *g = graph_init();
	FILE * f = fopen(argv[1], "r");	
	graph_readFromFile (f, g);
	graph_print(stdout, g);
	graph_free(g);
	fclose(f);
	return 0;

}
	
	
 

