#!/bin/bash

gcc -c libreria.c -o libreria.o;
ar -rv libreria.a libreria.o;
gcc -o test test.c -L./ -lreria;