#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    n=4;
    int i;
    char **cadena = (char**)malloc(n*sizeof(char*));
    for (i=0; i<n; i++){
        cadena[i] = (char*)malloc(sizeof(char));       //Si quito el 1024, me sigue funcionando.
        if(fgets(cadena[i], 1024, stdin)){             //fgets devuelve un puntero, luego como comprobacion podriamos poner: if (fgets != NULL){}
            printf("%s", cadena[i]);                   //He quitado el \n porque el propio fgets ya incluye el salto de linea que hemos introducido por teclado
        } else{
            printf("An unexpected error occurred\n");
        }
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