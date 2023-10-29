#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFERSIZE 1024

int head(int N){
    int i;
    char **cadena = (char**)malloc((N+1)*sizeof(char*));
    for(i=0; i<N; i++){                                         //Cargamos las N primeras lineas que se introducen por stdin
        cadena[i] = (char*)malloc(sizeof(char)*BUFFERSIZE);
        fgets(cadena[i], BUFFERSIZE, stdin);
    }
    cadena[i] = (char*)malloc(sizeof(char));                    //Reservamos espacio para leer la linea N+1 (nueva linea).(Se podria haber puesto cadena[N] en lugar de cadena[i])
    while(fgets(cadena[N], BUFFERSIZE, stdin) != NULL){         //Guardamos la nueva linea en la posicion N+1 de el array de cadenas de caracteres
        free(cadena[N]);                                        //Liberamos la memoria ocupada por la linea que acabamos de leer
        cadena[N] = (char*)malloc(sizeof(char)*BUFFERSIZE);     //Volvemos a usar malloc para asignar una nueva linea en la siguiente iteracion del bucle
    }      
    free(cadena[i]);                                            //Al terminar de leer lineas, liberamos por ultima vez la memoria ocupada por la linea que acabamos de leer
    for(i=0; i<N; i++){
        printf("%s", cadena[i]);
    }

    return 0;
}

int tail(int N){
    int i;

    char **cadena;
    cadena = (char**)malloc((N+1)*sizeof(char*));
    for(i=0; i<N; i++){                                         //Reservamos espacio y cargamos las N primeras que se introducen por stdin
        cadena[i] = (char*)malloc(sizeof(char)*BUFFERSIZE);
        fgets(cadena[i], BUFFERSIZE, stdin);
    }
    cadena[N] = (char*)malloc(sizeof(char)*BUFFERSIZE);         //Reservamos espacio para leer la linea N+1
    while(fgets(cadena[N], BUFFERSIZE, stdin)!=NULL){           //Cargamos en la posicion N+1 del array de cadenas de caracteres las nuevas frases que se van leyendo por stdin
        free(cadena[0]);                                        //Como la cadena en la primera posicion del array de cadenas se va a perder en el bucle for, debemos hacer un free antes de modificar el puntero
        for (i=0; i<N; i++){
            cadena[i]=cadena[i+1];                              //Cada puntero apunta a la posicion siguiente, donde se encuentra una linea con menor antigüedad
        }
        cadena[N] = (char*)malloc(sizeof(char)*BUFFERSIZE);
    }
    for (i=0; i<N; i++){
        printf("%s", cadena[i]);
    }

    return 0;
}

int ordenar(char **cadena, int max){                  //Funcion auxiliar que sirve para ordenar N lineas. Se van intercambiando las lineas de una en una, quedando en la posicion N+1 la de menor longitud que posteriormente sera eliminada
    int j;
    for(j=0;j<max;j++){
        if(strlen(cadena[j])<strlen(cadena[max])){              //Si la longitud de una linea es menor a la longitud de la ultima, se cambian de sitio
            char *aux;
            aux = (char*)malloc(BUFFERSIZE*sizeof(char));       //Reservamos espacio para una linea auxiliar que nos ayudara a ordenar por el algoritmo de la burbuja
            strcpy(aux, cadena[max]);
            strcpy(cadena[max], cadena[j]);                     //Se guarda en la posicion N+1 del array de cadenas la cadena de menor longitud
            strcpy(cadena[j], aux);                             //En la posicion j del array de cadenas de caracteres en la que estamos se guarda la nueva linea que se ha leido, o en su defecto, otra linea que es de mayor longitud
            free(aux);                                          //Liberamos el espacio de la variable auxiliar
        }
    }

    return 0;
}

int longlines(int N){
    int i;
    char **cadena;

    cadena = (char**)malloc((N+1)*sizeof(char*));

    for(i=0; i<(N+1); i++){                                             //Reserva de memoria para las N+1 posiciones del array de cadenas de caracteres
        cadena[i] = (char*)malloc(BUFFERSIZE*sizeof(char));
    }

    i=0;
    fgets(cadena[i], BUFFERSIZE, stdin);                                //Se lee la primera linea de todas
    while(fgets(cadena[N], BUFFERSIZE, stdin)!=NULL){                   //Se leen la segunda y demas lineas que se introducen por stdin
        ordenar(cadena, N);                                             //Ordenamos las N lineas de mayor a menor longitud
        if(i!=(N-1)){
            i++;
        }
        free(cadena[N]);                                                //Liberamos el espacio ocupado por la ultima posicion del array de caracteres, ya que su numero de caracteres no es suficiente para ser impreso por pantalla
        cadena[N]=(char*)malloc(BUFFERSIZE*sizeof(char));
    }

    for (i=0; i<N; i++){
        if (cadena[i]!=NULL){
            printf("%s", cadena[i]);
        }
    }
    return 0;
}