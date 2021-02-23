#!/bin/bash

echo "Compilando..." #Se muestra por pantalla el mensaje "compilando"*/
gcc -Wall -pedantic -c p1_e1.c #Compila el archivo p1_e1.c formando p1_e1.o y mediante -Wall se muestran errores.
gcc -Wall -pedantic -c vertex.c #Compila el archivo vertex.c formando vertex.o y mediante -Wall se muestran errores.
gcc -o p1_e1 vertex.o p1_e1.o #Enlaza los .o formados en las dos lineas anteriores y crea el ejecutable p1_e1.

