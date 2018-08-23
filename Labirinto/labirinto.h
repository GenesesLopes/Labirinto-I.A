#ifndef LABIRINTO_H_INCLUDED
#define LABIRINTO_H_INCLUDED
/*
    Código criado por Gêneses Lopes!
    genesislopes@hotmail.com

    método para imprimir o labirinto
*/

#include<stdlib.h>
#include<stdio.h>


#define PAREDE '#'
#define TAMANHO 24


char **labirinto(){

    int i,j;
    char **matriz;
    FILE *arquivoMatriz;
    //alocando linhas da matriz
    matriz = (char**) calloc(TAMANHO,sizeof(char*));

    //Alocando colunas
    for(i=0; i<TAMANHO; i++)
        matriz[i] = (char*) calloc(TAMANHO,sizeof(char));

    //Lendo a matriz de um arquivo de Texto
    arquivoMatriz = fopen("Matriz/matriz.txt","rt");
    for(i=0;i<TAMANHO -1;i++){
        for(j=0; j<TAMANHO -1; j++){
            fscanf(arquivoMatriz,"%c",&matriz[i][j]);
        }
        fscanf(arquivoMatriz,"%c",&matriz[i][j]);
    }
    fclose(arquivoMatriz);

    return matriz;
}


#endif // LABIRINTO_H_INCLUDED
