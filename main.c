#include "Labirinto/imprimir.h"
#include "Labirinto/labirinto.h"
#include "Labirinto/metodosMatriz.h"
#include "Labirinto/metodosArvore.h"

void main(){
    char **matriz;
    int linhaOrigem, colunaOrigem, linhaDestino, colunaDestino;
    matriz = labirinto();
    imprimir(matriz);
    printf("digite o valor para linha de origem:\t");
    scanf("%d",&linhaOrigem);
    printf("digite o valor para coluna de origem:\t");
    scanf("%d",&colunaOrigem);
    printf("digite o valor para linha de destino:\t");
    scanf("%d",&linhaDestino);
    printf("digite o valor para coluna de destino:\t");
    scanf("%d",&colunaDestino);


    pecorreArvore(matriz,inicioArvore,linhaOrigem,colunaOrigem,linhaDestino,colunaDestino);


}
