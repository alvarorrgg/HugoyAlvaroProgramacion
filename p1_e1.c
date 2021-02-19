#include "vertex.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	Vertex *v1,*v2;
	v1=vertex_init();
	v2=vertex_init();
	vertex_setId (v1, 10);
	vertex_setTag (v1, "one");
	vertex_setState (v1, WHITE);
	vertex_setId (v2, 20);
	vertex_setTag (v2, "two");
	vertex_setState (v2, BLACK);
	vertex_print(stdout,v1);
	vertex_print(stdout,v2);
	printf("\n");
	if(vertex_cmp(v1,v2) == 0){
		printf("Equals? Yes\n");
		}
	else{
		printf("Equals? No\n");
	}
	printf("Vertex 2 tag: %s\n",vertex_getTag(v2));
	Vertex* aux_v1 = vertex_copy(v1);
	printf("Vertex 3 id: %li\n",vertex_getId(aux_v1));
	vertex_print(stdout,v1);
	vertex_print(stdout,aux_v1);
	printf("\n");
	if(vertex_cmp(v1,aux_v1) == 0){
		printf("Equals? Yes\n");
		}
	else{
		printf("Equals? No\n");
	}
	vertex_free(v1);
	vertex_free(v2);
	return 0;
}

