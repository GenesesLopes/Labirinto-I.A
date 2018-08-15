#ifndef IMPRIMIR_H_INCLUDED
#define IMPRIMIR_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "labirinto.h"


void imprimir(){

    srand(time(NULL));
    int i,j;
    char **matriz = labirinto();

    for(i=0; i<20; i++){
        for(j=0; j<20; j++){
            printf("%c ",matriz[i][j]);
        }
        printf("\n");
    }


}


#endif // IMPRIMIR_H_INCLUDED
