#ifndef LABIRINTO_H_INCLUDED
#define LABIRINTO_H_INCLUDED
/*
    Código criado por Gêneses Lopes!
    genesislopes@hotmail.com

    método para imprimir o labirinto
*/

#include <stdlib.h>
#include <time.h>
#define PAREDE '#'


char **labirinto(){

    int i,j;
    char **matriz;

    //alocando linhas da matriz
    matriz = (char**) calloc(21,sizeof(char*));

    //Alocando colunas
    for(i=0; i<21; i++)
        matriz[i] = (char*) calloc(21,sizeof(char));

    //Preenchendo Laterais de matriz
    for(i=0; i<20; i++){
        for(j=0; j<20; j++){
            matriz[i][j] = PAREDE;
        }
    }

    //gerar matriz
    for(i=1;i<19;i++){
        for(j=1; j<19; j++){
            if(rand() %3 == 0)
                matriz[i][j] = '#';
            else
                matriz[i][j] = ' ';
        }
    }

    return matriz;
}


#endif // LABIRINTO_H_INCLUDED
