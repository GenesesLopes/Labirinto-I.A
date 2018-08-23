#ifndef METODOSARVORE_H_INCLUDED
#define METODOSARVORE_H_INCLUDED
#include "Arvore.h"
//inserir novo nó na arvore
arvore * inserirNoArvore(int linha, int coluna){
    arvore *novo = (arvore *) malloc(sizeof(arvore));
    novo->g = 0;
    novo->h = 0;
    novo->filhos = 0;
    novo->linha = linha;
    novo->coluna = coluna;
    novo->pai = inicioArvore;
    inicioArvore = novo;
    return novo;
}

void pecorreArvore(char **matriz,arvore *aux,int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    arvore * aux2;
    int n1, n2,a1,a2,i;

    if(linhaOrigem == linhaDestino && colunaOrigem == colunaDestino){
        system("clear");
        matriz[linhaDestino][colunaDestino] = '*';
        imprimir(matriz);
        return 0;
    }
    //filhos, calculos e decisao
    filhos(matriz,aux,linhaDestino,colunaDestino,linhaOrigem,colunaOrigem);
    //calculo(aux,linhadestino,colunaDestino);
    inserirFechado(aux);
    //aux2 = decisao(aux);
    a1 = aux->linha;
    a2 = aux->coluna;
    aux2 = decisao(aux);
    matriz[aux->linha][aux->coluna] = '*';
    imprimir(matriz);
    n1 = aux2->linha;
    n2 = aux2->coluna;

    if(aux->proximo[0] != NULL){
        if(aux->proximo[0]->linha == aux2->linha && aux->proximo[0]->coluna == aux2->coluna){
            system("clear");
            //pecorreArvore(matriz,aux2,linhaOrigem -1,colunaOrigem, linhaDestino,colunaDestino);
            pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
        }
    }
    if(aux->proximo[1] != NULL){
      if(aux->proximo[1]->linha == aux2->linha && aux->proximo[1]->coluna == aux2->coluna){
            system("clear");
            //pecorreArvore(matriz,aux2,linhaOrigem,colunaOrigem +1,linhaDestino,colunaDestino);
            pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
        }
    }
    if(aux->proximo[2] != NULL){
         if(aux->proximo[2]->linha == aux2->linha && aux->proximo[2]->coluna == aux2->coluna){
            system("clear");
            //pecorreArvore(matriz,aux2,linhaOrigem +1,colunaOrigem,linhaDestino,colunaDestino);
            pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
        }
    }
    if(aux->proximo[3] != NULL){
         if(aux->proximo[3]->linha == aux2->linha && aux->proximo[3]->coluna == aux2->coluna){
            system("clear");
            //pecorreArvore(matriz,aux2,linhaOrigem -1,colunaOrigem,linhaDestino,colunaDestino);
            pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
        }
    }
    if(aux->proximo[4] != NULL){
       if(aux->proximo[4]->linha == aux2->linha && aux->proximo[4]->coluna == aux2->coluna){
            system("clear");
            //pecorreArvore(matriz,aux2,linhaOrigem +1,colunaOrigem +1,linhaDestino,colunaDestino);
            pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
        }
    }
    if(aux->proximo[5] != NULL){
         if(aux->proximo[5]->linha == aux2->linha && aux->proximo[5]->coluna == aux2->coluna){
            system("clear");
            //pecorreArvore(matriz,aux2,linhaOrigem -1, colunaOrigem +1,linhaDestino,colunaDestino);
            pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
        }
    }
    if(aux->proximo[6] != NULL){
        if(aux->proximo[6]->linha == aux2->linha && aux->proximo[6]->coluna == aux2->coluna){
            system("clear");
            //pecorreArvore(matriz,aux2,linhaOrigem -1, colunaOrigem -1,linhaDestino,colunaDestino);
            pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
        }
    }
    if(aux->proximo[7] != NULL){
        if(aux->proximo[7]->linha == aux2->linha && aux->proximo[7]->coluna == aux2->coluna){
            system("clear");
            //pecorreArvore(matriz,aux2,linhaOrigem +1, linhaDestino -1,linhaDestino,colunaDestino);
            pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
        }
    }


}


#endif // METODOSARVORE_H_INCLUDED
