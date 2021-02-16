#include "vertex.h"
#include <string.h>
#define TAG_LENGTH 64

/*----------------------------------------------------------------------------------------*/
/*
Private function:
*/

struct _Vertex {
long id;
char tag[TAG_LENGTH];
Label state;
};


Status vertex_setField (Vertex *v, char *key, char *value);

Status vertex_setField (Vertex *v, char *key, char *value) {
  if (!key || !value) return ERROR;

  if (strcmp(key, "id") == 0) {
    return vertex_setId(v, atol(value));
  } else if (strcmp(key, "tag") == 0) {
    return vertex_setTag(v, value);
  } else if (strcmp(key, "state") == 0) {
    return vertex_setState(v, (Label)atoi(value));
  }

  return ERROR;
}

Vertex * vertex_init (){
	v=malloc(sizeof(Vertex));
	v->id=0;
	v->tag="";
	v->state=WHITE;
}

void vertex_free (void * v){
	free(v);
	}
long vertex_getId (const Vertex * v){
	if(v==NULL){
	return -1;}
	return v->id;
	}
const char* vertex_getTag (const Vertex * v){
	if(v==NULL){
	return NULL;}
	return v->tag;
	}
Label vertex_getState (const Vertex * v){
	if(v==NULL){
	return ERROR_VERTEX;}
	return v->state;
	}
Status vertex_setId (Vertex * v, const long id){
	if(v==NULL || id<0){
	return ERROR;}
	v->id=id;
	return OK;
	}
Status vertex_setTag (Vertex * v, const char * tag){
	if(v==NULL || strlen(tag)>64){
	return ERROR;}
	v->tag=tag;
	return OK;
	}
Status vertex_setState (Vertex * v, const Label state){
	if(v==NULL){
	return ERROR;}
	v->state=state;
	return OK;
	}
int vertex_cmp (const void * v1, const void * v2){
	
	}
void * vertex_copy (const void * src){
	
	}
int vertex_print (FILE * pf, const void * v){
	
	}

Vertex *vertex_initFromString(char *descr){
  char buffer[1024];
  char *token;
  char *key;
  char *value;
  char *p;
  Vertex *v;

  /* Check args: */
  if (!descr) return NULL;

  /* Allocate memory for vertex: */
  v = vertex_init();
  if (!v) return NULL;

  /* Read and tokenize description: */
  sprintf(buffer, "%s", descr);
  token = strtok(buffer, " \t\n");
  while (token) {
    p = strchr(token, ':');
    if (!p) continue;

    *p = '\0';
    key = token;
    value = p+1;

    vertex_setField(v, key, value);

    token = strtok(NULL, " \t\n");
  }

  return v;
}

/**  rest of the functions in vertex.h **/
