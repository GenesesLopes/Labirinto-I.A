#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

/*
F = G + H
G = Distancia que andou
H = Distancia que falta
*/
typedef struct Arvore {
    int g;
    int h;
    int f;
    int linha;
    int coluna;
    int filhos;
    struct Arvore **proximo;//Array de poneiros para armazenar os proximos nós
    struct Arvore *pai;
}arvore;

//iniciando ponteiro inicio da arvore
arvore *inicioArvore = NULL;

#endif // ARVORE_H_INCLUDED
