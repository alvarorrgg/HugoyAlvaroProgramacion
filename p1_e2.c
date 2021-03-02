#include "vertex.h"
#include "types.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
Graph *g;
long *conexiones;
g=graph_init();
printf("Inserting Madrid, 111, WHITE, result...: %i \n",graph_newVertex(g, "id:111 tag:Madrid state:0"));
printf("Inserting Toledo, 222, WHITE, result...: %i \n",graph_newVertex(g, "id:222 tag:Toledo state:0"));
printf("Inserting edge 222-->111\n");
graph_newEdge(g,222, 111);
printf("111-->222?");
if (graph_connectionExists(g,111,222)){
	printf("Yes\n");
	}
else{
	printf("No\n");
	}
printf("222-->111?");
if (graph_connectionExists(g,222,111)){
	printf("Yes\n");
	}
else{
	printf("No\n");
	}
printf("Number of connections from 111: %i\n",graph_getNumberOfConnectionsFromId(g,111));
printf("Number of connections from Toledo: %i\n",graph_getNumberOfConnectionsFromTag(g, "Toledo"));
conexiones=(long*) malloc(graph_getNumberOfConnectionsFromTag(g,"Toledo")*sizeof(long));
conexiones=graph_getConnectionsFromTag(g,"Toledo");
for(int i=0;i<graph_getNumberOfConnectionsFromTag(g,"Toledo");i++){
	printf("Connections from Toledo: %li",conexiones[i]);
	}
graph_print (stdout,g);
graph_free(g);



return 0;
}
