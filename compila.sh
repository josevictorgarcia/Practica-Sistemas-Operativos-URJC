#!/bin/bash

gcc -c libreria.c -o libreria.o;
ar -rv liblibreria.a libreria.o;
gcc -o test test.c -L./ -llibreria;