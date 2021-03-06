#!/bin/bash

echo "Compilando..." #Se muestra por pantalla el mensaje "compilando"*/
gcc -Wall -pedantic -g -c p1_e1.c #Compila el archivo p1_e1.c formando p1_e1.o y mediante -Wall se muestran errores.
gcc -Wall -pedantic -g -c vertex.c #Compila el archivo vertex.c formando vertex.o y mediante -Wall se muestran errores.
gcc -Wall -pedantic -g -c graph.c #Compila el archivo graph.c formando graph.o y mediante -Wall se muestran errores.
gcc -Wall -pedantic -g -c p1_e2.c #Compila el archivo p1_e2.c formando p1_e2.o y mediante -Wall se muestran errores.
gcc -Wall -pedantic -g -c p1_e3.c #Compila el archivo p1_e3.c formando p1_e3.o y mediante -Wall se muestran errores.
gcc -o p1_e1 -ggdb3 vertex.o p1_e1.o #Enlaza los .o formados en las dos lineas anteriores y crea el ejecutable p1_e1.
gcc -o p1_e2 -ggdb3 vertex.o p1_e2.o graph.o #Enlaza los .o p1_e2.o vertex.o y graph.o creando el ejecutable p1_e2.
gcc -o p1_e3 -ggdb3 vertex.o p1_e3.o graph.o #Enlaza los .o p1_e3.o vertex.o y graph.o creando el ejecutable p1_e3.

