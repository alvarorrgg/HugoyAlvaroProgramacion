#include "stack_fDoble.h"
#include "file_utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* @brief: Merges two stacks
*
* @param sin1, first input stack
* @param sin2, second input stack
* @param sout, result stack
* @return The function returns OK or ERROR
**/
Status mergeStacks (Stack *sin1, Stack *sin2, Stack *sout);




int main (int argc, char *argv[]){
int num1,num2,i;
double *nota;
	if(argc!=3){
		printf("Error al introducir los argumentos. Introdúzcalos de la forma: ./argumento1 argumento2.txt argumento3.txt");
		return 0;
}
Stack *sin1=stack_init();
Stack *sin2=stack_init();
Stack *sout=stack_init();
FILE *f=fopen(argv[1],"r");
if(!f) return 0;
FILE *g=fopen(argv[2],"r");
if(!g) return 0;
fscanf(f,"%i",&num1);
nota=(double*) malloc(sizeof(double)*num1);
for(i=0;i<num1;i++){
	fscanf(f,"%lf",&nota[i]);
	stack_push(sin1,nota[i]);
	}

stack_print(stdout,sin1,float_print);


fclose(f);
fclose(g);
stack_free(sin1);
stack_free(sin2);
stack_free(sout);
return 0;
}

Status mergeStacks (Stack *sin1, Stack *sin2, Stack *sout){
	float *e;
	Stack *ps=stack_init();
	if(sin1==NULL || sin2==NULL || sout==NULL || stack_isEmpty(sin1)==TRUE ||stack_isEmpty(sin2)==TRUE) return ERROR;
	while(stack_isEmpty(sin1)==FALSE && stack_isEmpty(sin2)==FALSE){
		if(stack_top(sin1)>stack_top(sin2)){
			e = stack_pop(sin1);
		}
		else{
			e = stack_pop(sin2);
		}
		stack_push( sout, e);
	}
	if(stack_isEmpty(sin1)==TRUE){
		ps=sin2;
	}
	else{
		ps=sin1;
	}
	while(stack_isEmpty(ps)==FALSE){
		e = stack_pop(ps);
		stack_push(sout, e);
	}
	stack_free(ps);
	return OK;
}




