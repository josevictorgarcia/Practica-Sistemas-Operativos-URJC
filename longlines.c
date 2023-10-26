#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int ordenar(char **cadena, int tope, int max){          //max=4, tope=i
    //printf("Cadena actual: %s", cadena[max]);
    //printf("Cadena con menos caracteres: %s", cadena[tope]);
    //printf("Cadena con más caracteres: %s", cadena[0]);
    
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

int main(){
    int n;
    n=4;
    int i;
    char **cadena;

    cadena = (char**)malloc((n+1)*sizeof(char*));
    //cadena[n] = (char*)malloc(1024*sizeof(char));

    for(i=0; i<(n+1); i++){
        cadena[i] = (char*)malloc(1024*sizeof(char));
    }

    i=0;
    fgets(cadena[i], 1024, stdin);                  //Caso mas basico: Como la cadena esta vacia, basta con hacer que cadena[0]=nuevalinea
    while(fgets(cadena[n], 1024, stdin)!=NULL){
        ordenar(cadena, i, n);
        if(i!=(n-1)){
            i++;
        }
        cadena[n]=(char*)malloc(1024*sizeof(char));
    }

    for (i=0; i<n; i++){
        if (cadena[i]!=NULL){
            printf("%s", cadena[i]);
        }
    }
    return 0;
}