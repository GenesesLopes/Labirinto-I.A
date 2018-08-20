#ifndef IMPRIMIR_H_INCLUDED
#define IMPRIMIR_H_INCLUDED
#define TAMANHO 25
#include <stdio.h>

void imprimir(char **matriz){

    int i,j;

    for(i=0; i<TAMANHO -1; i++){
        for(j=0; j<TAMANHO -1; j++){
            printf("%c",matriz[i][j]);
        }
    }


}


#endif // IMPRIMIR_H_INCLUDED
