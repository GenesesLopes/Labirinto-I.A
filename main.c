#include "Labirinto/imprimir.h"
#include "Labirinto/labirinto.h"

void main(){
    char valor, **matriz;



    valor = getchar();
    matriz = labirinto();
    while(valor == '\n'){
        printf("Labirinto...\n");
        imprimir(matriz);
        valor = getchar();

        system("clear");

    }


}
