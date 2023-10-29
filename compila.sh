#!/bin/bash

gcc -c libreria.c -o libreria.o;    #Genera el archivo objeto compilando el archivo fuente
ar -rv libreria.a libreria.o;       #Genera la libreria e inserta el archivo objeto generado
gcc -o test test.c -L./ -lreria;    #Genera el archivo ejecutable enlazando la libreria generada