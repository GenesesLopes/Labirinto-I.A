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
    int f = g + h;


}arvore;


#endif // ARVORE_H_INCLUDED
