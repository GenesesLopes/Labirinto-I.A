#include "Labirinto/imprimir.h"

void main(){
    char valor;

    valor = getchar();
    while(valor == '\n'){
        printf("Labirinto...\n");
        imprimir();
        valor = getchar();
        system("clear");
    }


}
