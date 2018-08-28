#ifndef METODOSARVORE_H_INCLUDED
#define METODOSARVORE_H_INCLUDED
#include "Arvore.h"
//inserir novo nó na arvore
arvore * inserirNoArvore(int linha, int coluna){
    arvore *novo = (arvore *) malloc(sizeof(arvore));
    novo->g = 0;
    novo->h = 0;
    novo->linha = linha;
    novo->coluna = coluna;
    novo->pai = inicioArvore;
    inicioArvore = novo;
    return novo;
}

void pecorreArvore(char **matriz,arvore *aux,int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    arvore * aux2, *aux3;

    int i;

    if(linhaOrigem == linhaDestino && colunaOrigem == colunaDestino){

        system("clear");
        aux3 = aux;

        while(aux3->pai != NULL){
            inserirCaminho(aux3);
            aux3 = aux3->pai;
        }
        pecorreCaminho(matriz);
        exit(0);
    }

    if(inicioArvore == NULL){
        arvore * novo;
        novo = inserirNoArvore(linhaOrigem,colunaOrigem);
        //filhos, calculos e decisao
        filhos(matriz,novo,linhaDestino,colunaDestino,linhaOrigem,colunaOrigem);
        //calculo(aux,linhadestino,colunaDestino);
        inserirFechado(novo);
        aux2 = decisao(novo);
        matriz[novo->linha][novo->coluna] = '*';
        imprimir(matriz);
        pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
    }

        //filhos, calculos e decisao
        filhos(matriz,aux,linhaDestino,colunaDestino,linhaOrigem,colunaOrigem);

        //inserindo no nó de fechados
        inserirFechado(aux);
        aux2 = decisao(aux);
        //Seleção com a melhor opção
        if(aux->proximo[0] != NULL){
            //aux2 = decisao(aux);
            if(aux->proximo[0]->linha == aux2->linha && aux->proximo[0]->coluna == aux2->coluna){
                pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
            }
        }
        if(aux->proximo[1] != NULL){
            //aux2 = decisao(aux);
            if(aux->proximo[1]->linha == aux2->linha && aux->proximo[1]->coluna == aux2->coluna){
                pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
            }
        }
        if(aux->proximo[2] != NULL){
            //aux2 = decisao(aux);
            if(aux->proximo[2]->linha == aux2->linha && aux->proximo[2]->coluna == aux2->coluna){
                pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
            }
        }
        if(aux->proximo[3] != NULL){
            //aux2 = decisao(aux);
            if(aux->proximo[3]->linha == aux2->linha && aux->proximo[3]->coluna == aux2->coluna){
                pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
            }
        }
        if(aux->proximo[4] != NULL){
            //aux2 = decisao(aux);
            if(aux->proximo[4]->linha == aux2->linha && aux->proximo[4]->coluna == aux2->coluna){
                pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
            }
        }
        if(aux->proximo[5] != NULL){
            //aux2 = decisao(aux);
            if(aux->proximo[5]->linha == aux2->linha && aux->proximo[5]->coluna == aux2->coluna){
                pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
            }
        }
        if(aux->proximo[6] != NULL){
            //aux2 = decisao(aux);
            if(aux->proximo[6]->linha == aux2->linha && aux->proximo[6]->coluna == aux2->coluna){
                pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
            }
        }
        if(aux->proximo[7] != NULL){
            //aux2 = decisao(aux);
            if(aux->proximo[7]->linha == aux2->linha && aux->proximo[7]->coluna == aux2->coluna){
                pecorreArvore(matriz,aux2,aux2->linha,aux2->coluna, linhaDestino,colunaDestino);
            }
        }
        //fim de seleção com a melhor opção

        //seleção com o nó livre
        if(aux->proximo[0] != NULL){
            if(pecorreFechado(aux->proximo[0]->linha,aux->proximo[0]->coluna) == NULL)
                pecorreArvore(matriz,aux->proximo[0],aux->proximo[0]->linha,aux->proximo[0]->coluna, linhaDestino,colunaDestino);
        }
        if(aux->proximo[1] != NULL){
            if(pecorreFechado(aux->proximo[1]->linha,aux->proximo[1]->coluna) == NULL)
                pecorreArvore(matriz,aux->proximo[1],aux->proximo[1]->linha,aux->proximo[1]->coluna, linhaDestino,colunaDestino);
        }
        if(aux->proximo[2] != NULL){
            if(pecorreFechado(aux->proximo[2]->linha,aux->proximo[2]->coluna) == NULL)
                pecorreArvore(matriz,aux->proximo[2],aux->proximo[2]->linha,aux->proximo[2]->coluna, linhaDestino,colunaDestino);
        }
        if(aux->proximo[3] != NULL){
            if(pecorreFechado(aux->proximo[3]->linha,aux->proximo[3]->coluna) == NULL)
                pecorreArvore(matriz,aux->proximo[3],aux->proximo[3]->linha,aux->proximo[3]->coluna, linhaDestino,colunaDestino);
        }
        if(aux->proximo[4] != NULL){
            if(pecorreFechado(aux->proximo[4]->linha,aux->proximo[4]->coluna) == NULL)
                pecorreArvore(matriz,aux->proximo[4],aux->proximo[4]->linha,aux->proximo[4]->coluna, linhaDestino,colunaDestino);
        }
        if(aux->proximo[5] != NULL){
            if(pecorreFechado(aux->proximo[5]->linha,aux->proximo[5]->coluna) == NULL)
                pecorreArvore(matriz,aux->proximo[5],aux->proximo[5]->linha,aux->proximo[5]->coluna, linhaDestino,colunaDestino);
        }
        if(aux->proximo[6] != NULL){
            if(pecorreFechado(aux->proximo[6]->linha,aux->proximo[6]->coluna) == NULL)
                pecorreArvore(matriz,aux->proximo[6],aux->proximo[6]->linha,aux->proximo[6]->coluna, linhaDestino,colunaDestino);
        }
        if(aux->proximo[7] != NULL){
            if(pecorreFechado(aux->proximo[7]->linha,aux->proximo[7]->coluna) == NULL)
                pecorreArvore(matriz,aux->proximo[7],aux->proximo[7]->linha,aux->proximo[7]->coluna, linhaDestino,colunaDestino);
        }
        //fim de seleção por nó livre


}


#endif // METODOSARVORE_H_INCLUDED
