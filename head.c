#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n;
    n=4;
    int i;
    char **cadena = (char**)malloc((n+1)*sizeof(char*));    //Reservamos espacio para el conjunto de strings que vamos a almacenar (numero de lineas)
    for(i=0; i<n; i++){
        cadena[i] = (char*)malloc(sizeof(char)*1024);            //Reservamos espacio para el conjunto de letras que vamos a almacenar (numero de letras/linea)
        fgets(cadena[i], 1024, stdin);
    }
    cadena[i] = (char*)malloc(sizeof(char));
    while(fgets(cadena[n], 1024, stdin) != NULL){           //Nos quedaremos en bucle hasta que se pulse Ctrl+D
        free(cadena[n]);                                    //Liberamos la memoria que acabamos de leer
        cadena[n] = (char*)malloc(sizeof(char)*1024);            //Volvemos a reservar memoria para leer otra vez
    }      
    free(cadena[i]);
    for(i=0; i<n; i++){
        printf("%s", cadena[i]);
    }
}

/*Dudas practica*/
/*
Cómo de restrictivos sois respecto a las funciones de libreria que utilicemos? Hay algún problema si usamos fgets o funciones de ficheros como fopen...? Se pueden usar otras utilidades que no encontremos en las transparencias?
Por que lo que pongo entre los parentesis del malloc no sirve para nada? (Da igual poner (sizeof(char)) que (sizeof(char)*1024))
Que tamaño debe tener cada linea que introduzcamos como máximo?
El enunciado nos pide que p.ej imprimamos las n ultimas lineas introducidas por entrada estandar. Que condicion ponemos para que el std. input deje de tomar datos de la entrada?
Todo el texto que queramos introducir se debe guardar a un fichero o se puede hacer todo desde terminal?
*/