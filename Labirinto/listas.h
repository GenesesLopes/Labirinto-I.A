#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include "Arvore.h"

//Estrutura da lista de abertos
typedef struct ListaAberto{
    arvore *no;
    struct ListaAberto *proximo;
} listaAberto;

//Iniciando Ponteiro
listaAberto *inicioAberto = NULL;

//Estrutura da lista de fechados
typedef struct ListaFechado{
    arvore *no;
    struct ListaFechado *proximo;
} listaFechado;

//Iniciando Ponteiro
listaFechado *inicioFechado = NULL;
listaFechado *fimFechado = NULL;
//Estrutura da lista de caminho
typedef struct ListaCaminho{
    arvore *no;
    struct ListaCaminho *proximo;
}caminho;
//Iniciando os ponteiros
caminho *inicioCaminho = NULL;


#endif // LISTAS_H_INCLUDED
