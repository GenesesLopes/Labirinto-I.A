#ifndef METODOSLISTAS_H_INCLUDED
#define METODOSLISTAS_H_INCLUDED

#include "listas.h"

//Inicio dos métodos da lista de abertos

void inserirAberto(arvore *no){
    int i;
    for(i=0; i<8; i++){
        if(no->proximo[i]!= NULL){
            listaAberto * novo = (listaAberto*) malloc(sizeof(listaAberto));
            novo->no = no->proximo[i];
            novo->proximo = inicioAberto;
            inicioAberto = novo;
        }
    }
}

listaAberto * pecorreAberto(int linha, int coluna){
    listaAberto *aux = inicioAberto;
    while (aux != NULL){
        if(aux->no->linha == linha && aux->no->coluna == coluna)
          break;
        else
            aux = aux->proximo;
    }
    return aux;
}

//fim de métodos da lista aberto

//Inicio de métodos da lista de fechado

void inserirFechado(arvore *no){

    listaFechado * novo = (listaFechado*) malloc(sizeof(listaFechado));
    novo->no = no;
    if(fimFechado == NULL){
        novo->proximo = fimFechado;
        inicioFechado = novo;
        fimFechado = novo;
    }else{
        novo->proximo = NULL;
        fimFechado->proximo = novo;
        fimFechado = novo;
    }

}

listaFechado * pecorreFechado(int linha, int coluna){
    listaFechado *aux = inicioFechado;
    int linha1, coluna1;

    while (aux != NULL){
        linha1 = aux->no->linha;
        coluna1 = aux->no->coluna;
        if(aux->no->linha == linha && aux->no->coluna == coluna)
            return aux;
        aux = aux->proximo;
    }

    return aux;
}
//fim de metodos de lista fechada

//Inicio métodos da lista de caminho
void inserirCaminho(arvore *no){
    caminho * novo = (caminho*) malloc(sizeof(caminho));
    novo->no = no;
    novo->proximo = inicioCaminho;
    inicioCaminho = novo;
}



void pecorreCaminho(char **matriz){
   caminho *aux = inicioCaminho;

   while (aux != NULL){
        system("clear");
        matriz[aux->no->linha][aux->no->coluna] = '*';
        imprimir(matriz);
        aux = aux->proximo;
   }

}
//fim de métodos caminho
#endif // METODOSLISTAS_H_INCLUDED
