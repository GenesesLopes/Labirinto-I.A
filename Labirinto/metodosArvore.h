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

void pecorreArvore(char **matriz, arvore *local, int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    arvore *no, *aux;
    int i, indice;
    //condicao de parada
    if(linhaOrigem == linhaDestino && colunaOrigem == colunaDestino){
        while(local != NULL){
            inserirCaminho(local);
            local = local->pai;
        }
        pecorreCaminho(matriz);
    }else{
        //caso seja a primeira entrada
        if(inicioArvore == NULL){
            //Alocando memoria
            no = inserirNoArvore(linhaOrigem,colunaOrigem);
            //Abrindo e contando quantidade de filhos
            quantidadeFilhos(no,matriz,linhaOrigem,colunaOrigem,linhaDestino,colunaDestino);
            //inserir no atual na lista de nos fechados
            inserirFechado(no);
            //escolher melhor caminho
            aux = decisao(no);
            //inserir nos filhos entre os nos abertos
            for(i=0; i<no->filhos; i++)
                inserirAberto(no->proximo[i]);
            //chamando a propria funcao
            pecorreArvore(matriz,aux,aux->linha,aux->coluna,linhaDestino,colunaDestino);
        }else{
            //Abrindo e contando quantidade de filhos
            quantidadeFilhos(local,matriz,linhaOrigem,colunaOrigem,linhaDestino,colunaDestino);
            //inserir no atual na lista de nos fechados
            inserirFechado(local);
            //escolher melhor caminho
            aux = decisao(local);
            //inserir nos filhos entre os nos abertos
            for(i=0; i<local->filhos; i++)
                inserirAberto(local->proximo[i]);
            //chamando a propria funcao
            pecorreArvore(matriz,aux,aux->linha,aux->coluna,linhaDestino,colunaDestino);

        }
    }
}


#endif // METODOSARVORE_H_INCLUDED
