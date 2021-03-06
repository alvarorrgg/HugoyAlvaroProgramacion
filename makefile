
p1_e3: p1_e3.o graph.o vertex.o 
	gcc -o p1_e3 p1_e3.o vertex.o graph.o

p1_e3.o: p1_e3.c vertex.h types.h graph.h
	gcc -c -g p1_e3.c

graph.o: graph.c graph.h vertex.h
	gcc -c -g graph.c

vertex.o: vertex.c vertex.h
	gcc -c -g vertex.c

clean: 
	@echo cleaning...
	rm *.o p1_e3
