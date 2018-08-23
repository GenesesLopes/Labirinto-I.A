#ifndef METODOSMATRIZ_H_INCLUDED
#define METODOSMATRIZ_H_INCLUDED
#define PAREDE '#'
#include "metodosListas.h"
#include "Arvore.h"

//Calculando Distancia que falta

//heuristica
int Heuristica(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    int retorno = 0;

        do{
            if(linhaOrigem < linhaDestino){
                retorno +=10;
                linhaOrigem++;
            }
            if(colunaOrigem < colunaDestino){
                retorno +=10;
                colunaOrigem++;
            }
            if(linhaOrigem > linhaDestino){
                retorno +=10;
                linhaOrigem--;
            }
            if(colunaOrigem > colunaDestino){
                retorno +=10;
                colunaOrigem--;
            }
        }while(linhaOrigem != linhaDestino || colunaOrigem != colunaDestino);

    return retorno;
}

void calculo(arvore *aux, int linhaDestino, int colunaDestino){

    if(aux->proximo[0]!= NULL){
        aux->proximo[0]->g = aux->g + 10;
        aux->proximo[0]->h = Heuristica(aux->proximo[0]->linha,aux->proximo[0]->coluna,linhaDestino,colunaDestino);
        aux->proximo[0]->f = aux->proximo[0]->g + aux->proximo[0]->h;

    }
    if(aux->proximo[1]!= NULL){
        aux->proximo[1]->g = aux->g + 10;
        aux->proximo[1]->h = Heuristica(aux->proximo[1]->linha,aux->proximo[1]->coluna,linhaDestino,colunaDestino);
        aux->proximo[1]->f = aux->proximo[1]->g + aux->proximo[1]->h;

    }
    if(aux->proximo[2]!= NULL){
        aux->proximo[2]->g = aux->g + 10;
        aux->proximo[2]->h = Heuristica(aux->proximo[2]->linha,aux->proximo[2]->coluna,linhaDestino,colunaDestino);
        aux->proximo[2]->f = aux->proximo[2]->g + aux->proximo[2]->h;

    }
    if(aux->proximo[3]!= NULL){
        aux->proximo[3]->g = aux->g + 10;
        aux->proximo[3]->h = Heuristica(aux->proximo[3]->linha,aux->proximo[3]->coluna,linhaDestino,colunaDestino);
        aux->proximo[3]->f = aux->proximo[3]->g + aux->proximo[3]->h;

    }
    if(aux->proximo[4]!= NULL){
        aux->proximo[4]->g = aux->g + 14;
        aux->proximo[4]->h = Heuristica(aux->proximo[4]->linha,aux->proximo[4]->coluna,linhaDestino,colunaDestino);
        aux->proximo[4]->f = aux->proximo[4]->g + aux->proximo[4]->h;

    }
    if(aux->proximo[5]!= NULL){
        aux->proximo[5]->g = aux->g + 14;
        aux->proximo[5]->h = Heuristica(aux->proximo[5]->linha,aux->proximo[5]->coluna,linhaDestino,colunaDestino);
        aux->proximo[5]->f = aux->proximo[5]->g + aux->proximo[5]->h;

    }
    if(aux->proximo[6]!= NULL){
        aux->proximo[6]->g = aux->g + 14;
        aux->proximo[6]->h = Heuristica(aux->proximo[6]->linha,aux->proximo[6]->coluna,linhaDestino,colunaDestino);
        aux->proximo[6]->f = aux->proximo[6]->g + aux->proximo[6]->h;
    }
    if(aux->proximo[7]!= NULL){
        aux->proximo[7]->g = aux->g + 14;
        aux->proximo[7]->h = Heuristica(aux->proximo[7]->linha,aux->proximo[7]->coluna,linhaDestino,colunaDestino);
        aux->proximo[7]->f = aux->proximo[7]->g + aux->proximo[7]->h;

    }


}
//escolhe a menor soma entre os nós abertos
arvore * decisao(arvore *no){
    int contador = 0, i,j, menor = 10000000;
    arvore *menorFilho;
    listaAberto *jaVisitado;
    listaAberto *lista = inicioAberto;

    //escolher o menor filho
    while(contador < 8){
        if(no->proximo[contador] != NULL){
            if(no->proximo[contador]->f <= menor){
                menor = no->proximo[contador]->f;
                menorFilho = no->proximo[contador];
            }
        }
        contador++;
    }
    //primeiro caso
    if(lista == NULL){
        inserirAberto(no);
        return menorFilho;
    }

    //verificar se o nó já foi visitado
    jaVisitado = pecorreAberto(menorFilho->linha,menorFilho->coluna);
    //inserindo na lista de abertos
    inserirAberto(no);
    //caso já tenha visitado o no
    if(jaVisitado != NULL)
        return jaVisitado->no;
    else
        return menorFilho;

}


//verificar filhos e calcular
void filhos(char **matriz,arvore *no, int linha, int coluna, int linhaOrigem, int colunaOrigem){
    char baixo = PAREDE, direita = PAREDE, acima = PAREDE, esquerda = PAREDE;
    int i;
    arvore *noFechado = NULL;


    no->proximo = (arvore **) calloc(8,sizeof(arvore*));

    for(i=0; i<8; i++)
        no->proximo[i] = NULL;

    //Para baixo
    if(matriz[linhaOrigem +1][colunaOrigem] != PAREDE){
        noFechado = pecorreFechado(linhaOrigem +1, coluna);
        if(noFechado == NULL){
            baixo = 'L';
            no->proximo[0] = (arvore *) malloc(sizeof(arvore));
            no->proximo[0]->linha = linhaOrigem +1;
            no->proximo[0]->coluna = colunaOrigem;
            no->proximo[0]->pai = no;
            calculo(no,linha,coluna);

        }
    }

    //Direita
    if(matriz[linhaOrigem][colunaOrigem +1] != PAREDE){
        noFechado = pecorreFechado(linhaOrigem, colunaOrigem +1);
        if(noFechado == NULL){
            direita = 'L';
            no->proximo[1] = (arvore *) malloc(sizeof(arvore));
            no->proximo[1]->linha = linhaOrigem;
            no->proximo[1]->coluna = colunaOrigem +1;
            no->proximo[1]->pai = no;
            calculo(no,linha,coluna);
        }
    }

    //acima
    if(matriz[linhaOrigem -1][colunaOrigem] != PAREDE){
        noFechado = pecorreFechado(linhaOrigem -1, colunaOrigem);
        if(noFechado == NULL){
            acima = 'L';
            no->proximo[2] = (arvore *) malloc(sizeof(arvore));
            no->proximo[2]->linha = linhaOrigem -1;
            no->proximo[2]->coluna = colunaOrigem;
            no->proximo[2]->pai = no;
            calculo(no,linha,coluna);
        }
    }

    //esquerda
    if(matriz[linhaOrigem][colunaOrigem -1] != PAREDE){
        noFechado = pecorreFechado(linhaOrigem, colunaOrigem -1);
        if(noFechado == NULL){
            esquerda = 'L';
            no->proximo[3] = (arvore *) malloc(sizeof(arvore));
            no->proximo[3]->linha = linhaOrigem;
            no->proximo[3]->coluna = colunaOrigem -1;
            no->proximo[3]->pai = no;
            calculo(no,linha,coluna);
        }
    }

    //Diagonal direita abaixo
    if(matriz[linhaOrigem +1][colunaOrigem +1] != PAREDE){
        noFechado = pecorreFechado(linhaOrigem +1, colunaOrigem +1);
        if(noFechado == NULL){
            if(direita != PAREDE && baixo != PAREDE){
                no->proximo[4] = (arvore *) malloc(sizeof(arvore));
                no->proximo[4]->linha = linhaOrigem +1;
                no->proximo[4]->coluna = colunaOrigem +1;
                no->proximo[4]->pai = no;
                calculo(no,linha,coluna);
            }
        }
    }

    //Diagonal direita acima
    if(matriz[linhaOrigem -1][colunaOrigem +1] != PAREDE){
        noFechado = pecorreFechado(linhaOrigem -1, colunaOrigem +1);
        if(noFechado == NULL){
            if(direita != PAREDE && acima != PAREDE){
                no->proximo[5] = (arvore *) malloc(sizeof(arvore));
                no->proximo[5]->linha = linhaOrigem -1;
                no->proximo[5]->coluna = colunaOrigem +1;
                no->proximo[5]->pai = no;
                calculo(no,linha,coluna);
            }
        }
    }

    //Diagonal esquerda acima
    if(matriz[linhaOrigem -1][colunaOrigem -1] != PAREDE){
        noFechado = pecorreFechado(linhaOrigem -1, colunaOrigem -1);
        if(noFechado == NULL){
            if(esquerda != PAREDE && acima != PAREDE){
                no->proximo[6] = (arvore *) malloc(sizeof(arvore));
                no->proximo[6]->linha = linhaOrigem -1;
                no->proximo[6]->coluna = colunaOrigem -1;
                no->proximo[6]->pai = no;
                calculo(no,linha,coluna);
            }
        }
    }

    //Diagonal esquerda abaixo
    if(matriz[linhaOrigem +1][colunaOrigem -1] != PAREDE){
        noFechado = pecorreFechado(linhaOrigem +1, colunaOrigem -1);
        if(noFechado == NULL){
            if(esquerda != PAREDE && baixo != PAREDE){
                no->proximo[7] = (arvore *) malloc(sizeof(arvore));
                no->proximo[7]->linha = linhaOrigem +1;
                no->proximo[7]->coluna = linhaOrigem -1;
                no->proximo[7]->pai = no;
                calculo(no,linha,coluna);
            }
        }
    }
}




#endif // METODOSMATRIZ_H_INCLUDED

