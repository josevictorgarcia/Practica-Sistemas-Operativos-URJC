#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int head(int N){
    int i;
    char **cadena = (char**)malloc((N+1)*sizeof(char*));
    for(i=0; i<N; i++){
        cadena[i] = (char*)malloc(sizeof(char)*1024);
        fgets(cadena[i], 1024, stdin);
    }
    cadena[i] = (char*)malloc(sizeof(char));
    while(fgets(cadena[N], 1024, stdin) != NULL){
        free(cadena[N]);
        cadena[N] = (char*)malloc(sizeof(char)*1024);
    }      
    free(cadena[i]);
    for(i=0; i<N; i++){
        printf("%s", cadena[i]);
    }

    return 0;
}

int tail(int N){
    int i;

    char **cadena;
    cadena = (char**)malloc((N+1)*sizeof(char*));
    for(i=0; i<N; i++){
        cadena[i] = (char*)malloc(sizeof(char)*1024);
        fgets(cadena[i], 1024, stdin);
    }
    cadena[N] = (char*)malloc(sizeof(char)*1024);
    while(fgets(cadena[N], 1024, stdin)!=NULL){
        for (i=0; i<N; i++){
            cadena[i]=cadena[i+1];
        }
        cadena[N] = (char*)malloc(sizeof(char)*1024);
    }
    for (i=0; i<N; i++){
        printf("%s", cadena[i]);
    }

    return 0;
}

int ordenar(char **cadena, int tope, int max){
    int j;
    for(j=0;j<max;j++){
        if(strlen(cadena[j])<strlen(cadena[max])){
            char *aux;
            aux = (char*)malloc(1024*sizeof(char));
            strcpy(aux, cadena[max]);
            strcpy(cadena[max], cadena[j]);
            strcpy(cadena[j], aux);
        }
    }

    return 0;
}

int longlines(int N){
    int i;
    char **cadena;

    cadena = (char**)malloc((N+1)*sizeof(char*));

    for(i=0; i<(N+1); i++){
        cadena[i] = (char*)malloc(1024*sizeof(char));
    }

    i=0;
    fgets(cadena[i], 1024, stdin);
    while(fgets(cadena[N], 1024, stdin)!=NULL){
        ordenar(cadena, i, N);
        if(i!=(N-1)){
            i++;
        }
        cadena[N]=(char*)malloc(1024*sizeof(char));
    }

    for (i=0; i<N; i++){
        if (cadena[i]!=NULL){
            printf("%s", cadena[i]);
        }
    }
    return 0;
}