#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"libreria.h"

int main(int argc, char *argv[]){

    switch(argc){
        case 2:
            if(strcmp(argv[1], "-head")==0){head(10);}
            else if (strcmp(argv[1], "-tail")==0){tail(10);}
            else if (strcmp(argv[1], "-longlines")==0){longlines(10);}
            else{printf("No se reconoce %s como argumento\n", argv[1]);}
        break;
        case 3:
                if(strcmp(argv[1], "-head")==0){head(atoi(argv[2]));}
                else if (strcmp(argv[1], "-tail")==0){tail(atoi(argv[2]));}
                else if (strcmp(argv[1], "-longlines")==0){longlines(atoi(argv[2]));}
                else{printf("No se reconoce %s como argumento\n", argv[1]);}
        break;
        default: 
            printf("El numero de argumentos (%d) debe ser 1 o 2\n", argc-1);
        break;
    }

    return 0;
}