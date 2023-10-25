#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n;
    n=4;
    int i;

    char **cadena;
    cadena = (char**)malloc((n+1)*sizeof(char*));
    for(i=0; i<n; i++){
        cadena[i] = (char*)malloc(sizeof(char)*1024);
        fgets(cadena[i], 1024, stdin);
    }
    cadena[n] = (char*)malloc(sizeof(char)*1024);
    while(fgets(cadena[n], 1024, stdin)!=NULL){
        for (i=0; i<n; i++){
            //printf("%s --> %s", cadena[i], cadena[i+1]);
            cadena[i]=cadena[i+1];
        }
        //free(cadena[n]);                                      //Si pongo el free(cadena) el funcionamiento es muy raro.
        cadena[n] = (char*)malloc(sizeof(char)*1024);
    }
    for (i=0; i<n; i++){
        printf("%s", cadena[i]);
    }


    return 0;
}