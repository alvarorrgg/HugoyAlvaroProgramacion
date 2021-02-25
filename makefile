
p1_e2: p1_e2.o graph.o vertex.o 
	gcc -o p1_e2 p1_e2.o vertex.o graph.o

p1_e2.o: p1_e2.c vertex.h types.h graph.h
	gcc -c p1_e2.c

graph.o: graph.c graph.h vertex.h
	gcc -c graph.c

vertex.o: vertex.c vertex.h
	gcc -c vertex.c

clean: 
	@echo cleaning...
	rm *.o p1_e2
