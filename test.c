#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"libreria.h"

int main(int argc, char *argv[]){

    switch(argc){                                                                       //Comprobacion de argumentos
        case 2:                                                                         //Si se introduce solo un argumento (nombre de la funcion), el valor por defecto son 10 lineas
            if(strcmp(argv[1], "-head")==0){head(10);}
            else if (strcmp(argv[1], "-tail")==0){tail(10);}
            else if (strcmp(argv[1], "-longlines")==0){longlines(10);}
            else{printf("No se reconoce %s como argumento\n", argv[1]);}                //En caso de que el primer (y unico) argumento no sea valido
        break;
        case 3:                                                                         //Si se introducen dos argumentos, el segundo indica el numero de lineas que se devolveran
                if(strcmp(argv[1], "-head")==0){head(atoi(argv[2]));}
                else if (strcmp(argv[1], "-tail")==0){tail(atoi(argv[2]));}
                else if (strcmp(argv[1], "-longlines")==0){longlines(atoi(argv[2]));}
                else{printf("No se reconoce %s como argumento\n", argv[1]);}            //En caso de que el primer argumento no sea valido. El segundo argumento no da error ya que si se introduce cualquier cosa que no sea un numero, atoi() devolvera 0 y por tanto se devolveran 0 lineas
        break;
        default:                                                                        //En caso de que se introduzcan 0 o mas argumentos
            printf("El numero de argumentos (%d) debe ser 1 o 2\n", argc-1);
        break;
    }

    return 0;
}