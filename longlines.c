#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int ordenar(char **cadena, int n){
    int indice;
    indice=0;
    char *nuevo;
    nuevo=cadena[n];
    if(cadena[indice]==NULL){                                //Caso mas basico: Si cadena esta vacio, basta con hacer que cadena[0]=nuevo
        cadena[indice]=(char*)malloc(1024*sizeof(char));
        cadena[indice]=nuevo;
    }
    else{
        while(strlen(cadena[indice])>strlen(nuevo) && indice<n){
            indice++;
        }
        if (indice<n){
            char *aux;
            aux = (char*)malloc(1024*sizeof(char));
            strcpy(aux, nuevo);
            int j;
            j=n-1;
            while(j!=indice){
                cadena[j]=cadena[j-1];
                j--;
            }
            cadena[indice]=aux;
        }
    }

    return 0;
}

int main(){
    int n;
    n=4;
    int i;
    char **cadena;

    cadena = (char**)malloc((n+1)*sizeof(char*));
    cadena[n] = (char*)malloc(1024*sizeof(char));

    while(fgets(cadena[n], 1024, stdin)!=NULL){
        ordenar(cadena, n);
    }

    for (i=0; i<n; i++){
        if (cadena[i]!=NULL){
            printf("%s", cadena[i]);
        }
    }
    return 0;
}