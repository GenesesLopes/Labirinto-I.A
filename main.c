#include "Labirinto/imprimir.h"
#include "Labirinto/labirinto.h"

void main(){
    char valor, **matriz;
    int numero = 49, coluna = 1;


    valor = getchar();
    matriz = labirinto();
    while(valor == '\n'){
        printf("Labirinto...\n");
        imprimir(matriz);

        valor = getchar();
        numero++;
        coluna++;
        system("clear");

    }


}
