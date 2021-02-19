#p1_e1

p1_e1: vertex.o p1_e1.o
	gcc -o p1_e1 vertex.o p1_e1.o

p1_e1.o: p1_e1.c vertex.h types.h
	gcc -Wall -c p1_e1.c
	
vertex.c: vertex.h types.h
	gcc -Wall -c vertex.c

clean:
	@echo Limpiando
	rm -rf *.o p1_e1
