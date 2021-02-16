#makefile Ejercicio1

p1_e1: vertex.o p1_e1.o
	gcc -o p1_e1 vertex.o p1_e1.o

p1_e1.o: p1_e1.c vertex.h
	gcc -Wall -pedantic -g p1_e1.c

vertex.o: vertex.c vertex.h
	gcc -Wall -pedantic -g vertex.c

clean:
	@echo "Limpiando"
	rm -rf *.o p1_e1
