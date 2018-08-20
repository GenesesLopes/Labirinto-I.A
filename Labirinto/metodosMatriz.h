#ifndef METODOSMATRIZ_H_INCLUDED
#define METODOSMATRIZ_H_INCLUDED
#include "metodosListas.h"
//Calculando Distancia que falta

int distanciaFalta(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    int difLinha = 0;
    int difColuna = 0;
    //Calculando a diferença entre linhas e colunas
    difLinha = linhaOrigem - linhaDestino;
    difColuna = colunaOrigem - colunaDestino;

    //caso o cálculo seja negativo
    if(difLinha < 0)
        difLinha*= -1;
    if(difColuna < 0)
        difColuna*= -1;

    return (difLinha + difColuna) * 10;
}

//escolhe a menor soma entre os nós abertos
arvore * decisao(arvore *no){
    arvore *aux = no->proximo[0];
    listaAberto *aux2;
    int i;
    //pecorre até achar o menor
    for(i=0; i<no->filhos; i++){
        if(aux->f > no->proximo[i]->f)
            aux = no->proximo[i];
    }
    //compara nó em lista de abertos
    aux2 = comparaNo(aux);
    //caso não encontre
    if(aux2 == NULL)
        return aux;

    return aux2->no;
}


//Verificar quantidade de filhos
void quantidadeFilhos(arvore *no,char **matriz,  int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino){
    int contador = 0;
    char abaixo = PAREDE, acima = PAREDE, esquerda = PAREDE, direita = PAREDE;
    listaAberto *abertos;
    listaFechado *fechados;

    //alocando memoria para vetor
    no->proximo = (arvore **) malloc(sizeof(arvore*));

    //verificando se abaixo é diferente de parede
    if(matriz[linhaOrigem + 1][colunaOrigem] != PAREDE){//Direcao para baixo
        abaixo = 'L';
        abertos = pecorreAberto(linhaOrigem + 1,colunaOrigem);
        fechados = pecorreFechado(linhaOrigem + 1,colunaOrigem);
        //verificando se o nó ja foi aberto
        if( abertos == NULL && fechados == NULL){
            no->proximo[contador] = (arvore*) malloc(sizeof(arvore));
            //Calcular distancia que falta
            no->proximo[contador]->h = distanciaFalta(linhaOrigem + 1,colunaOrigem,linhaDestino,colunaDestino);
            //calcular p quanto andou
            no->proximo[contador]->g = no->g + 10;
            //distancia total que falta
            no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
            //linha e coluna da matriz
            no->proximo[contador]->linha = linhaOrigem + 1;
            no->proximo[contador]->coluna = colunaOrigem;
            no->proximo[contador]->pai = no;
            //adicionar mais uma posição para o array
            contador++;
        }
        else if(abertos != NULL && fechados == NULL){
            no->proximo[contador] = abertos->no;
            //calcular p quanto andou
            no->proximo[contador]->g = no->g + 10;
            //distancia total que falta
            no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
            //linha e coluna da matriz
            no->proximo[contador]->linha = linhaOrigem + 1;
            no->proximo[contador]->coluna = colunaOrigem;
            no->proximo[contador]->pai = no;
            //adicionar mais uma posição para o array
            contador++;
        }
    }//fim de acoes para diracao para baixo

    //direcao direira
    if(matriz[linhaOrigem][colunaOrigem + 1] != PAREDE){
        direita = 'L';
        abertos = pecorreAberto(linhaOrigem,colunaOrigem + 1);
        fechados = pecorreFechado(linhaOrigem,colunaOrigem + 1);
        //verificando se o nó ja foi aberto
        if(abertos == NULL && fechados == NULL){
            no->proximo[contador] = (arvore*) malloc(sizeof(arvore));
            //Calcular distancia que falta
            no->proximo[contador]->h = distanciaFalta(linhaOrigem,colunaOrigem + 1,linhaDestino,colunaDestino);
             //calcular p quanto andou
            no->proximo[contador]->g = no->g + 10;
            //distancia total que falta
            no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
            //linha e coluna da matriz
            no->proximo[contador]->linha = linhaOrigem;
            no->proximo[contador]->coluna = colunaOrigem + 1;
            no->proximo[contador]->pai = no;
            //adicionar mais uma posição para o array
            contador++;
        }
        else if(abertos != NULL && fechados == NULL){
            no->proximo[contador] = abertos->no;
            //calcular p quanto andou
            no->proximo[contador]->g = no->g + 10;
            //distancia total que falta
            no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
            //linha e coluna da matriz
            no->proximo[contador]->linha = linhaOrigem;
            no->proximo[contador]->coluna = colunaOrigem + 1;
            no->proximo[contador]->pai = no;
            //adicionar mais uma posição para o array
            contador++;

        }
    }//fim de acoes para diracao para direita

    //direcao acima
    if(matriz[linhaOrigem -1][colunaOrigem] != PAREDE){
        acima = 'L';
        abertos = pecorreAberto(linhaOrigem -1,colunaOrigem);
        fechados = pecorreFechado(linhaOrigem -1,colunaOrigem);
        //verificando se o nó ja foi aberto
        if(abertos == NULL && fechados == NULL){
            no->proximo[contador] = (arvore*) malloc(sizeof(arvore));
            //Calcular distancia que falta
            no->proximo[contador]->h = distanciaFalta(linhaOrigem -1,colunaOrigem,linhaDestino,colunaDestino);
            //calcular p quanto andou
            no->proximo[contador]->g = no->g + 10;
            //distancia total que falta
            no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
            //linha e coluna da matriz
            no->proximo[contador]->linha = linhaOrigem -1;
            no->proximo[contador]->coluna = colunaOrigem;
            no->proximo[contador]->pai = no;
            //adicionar mais uma posição para o array
            contador++;
        }
        else if(abertos != NULL && fechados == NULL){
            no->proximo[contador] = abertos->no;
            //calcular p quanto andou
            no->proximo[contador]->g = no->g + 10;
            //distancia total que falta
            no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
            //linha e coluna da matriz
            no->proximo[contador]->linha = linhaOrigem -1;
            no->proximo[contador]->coluna = colunaOrigem;
            no->proximo[contador]->pai = no;
            //adicionar mais uma posição para o array
            contador++;
        }
    }//fim de acoes para diracao para acima

    //direcao esquerda
    if(matriz[linhaOrigem][colunaOrigem -1] != PAREDE){
        esquerda = 'L';
        abertos = pecorreAberto(linhaOrigem,colunaOrigem -1);
        fechados = pecorreFechado(linhaOrigem,colunaOrigem -1);
        //verificando se o nó ja foi aberto
        if(abertos == NULL && fechados == NULL){
            no->proximo[contador] = (arvore*) malloc(sizeof(arvore));
            //Calcular distancia que falta
            no->proximo[contador]->h = distanciaFalta(linhaOrigem,colunaOrigem -1,linhaDestino,colunaDestino);
            //calcular p quanto andou
            no->proximo[contador]->g = no->g + 10;
            //distancia total que falta
            no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
            //linha e coluna da matriz
            no->proximo[contador]->linha = linhaOrigem;
            no->proximo[contador]->coluna = colunaOrigem -1;
            no->proximo[contador]->pai = no;
            //adicionar mais uma posição para o array
            contador++;
        }
        else if(abertos != NULL && fechados == NULL){
            no->proximo[contador] = abertos->no;
            //calcular p quanto andou
            no->proximo[contador]->g = no->g + 10;
            //distancia total que falta
            no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
            //linha e coluna da matriz
            no->proximo[contador]->linha = linhaOrigem;
            no->proximo[contador]->coluna = colunaOrigem -1;
            no->proximo[contador]->pai = no;
            //adicionar mais uma posição para o array
            contador++;
        }
    }//fim de acoes para diracao para esquerda

    //direcao diagonal abaixo para direita
      if(matriz[linhaOrigem +1][colunaOrigem +1] != PAREDE){

        //verificar se ao redor contem parede
        if(abaixo != PAREDE && direita != PAREDE){
            abertos = pecorreAberto(linhaOrigem +1,colunaOrigem +1);
            fechados = pecorreFechado(linhaOrigem +1,colunaOrigem +1);
            //verificando se o nó ja foi aberto
            if(abertos == NULL && fechados == NULL){
                no->proximo[contador] = (arvore*) malloc(sizeof(arvore));
                //Calcular distancia que falta
                no->proximo[contador]->h = distanciaFalta(linhaOrigem +1,colunaOrigem +1,linhaDestino,colunaDestino);
                //calcular p quanto andou
                no->proximo[contador]->g = no->g + 14;
                //distancia total que falta
                no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
                //linha e coluna da matriz
                no->proximo[contador]->linha = linhaOrigem +1;
                no->proximo[contador]->coluna = colunaOrigem +1;
                no->proximo[contador]->pai = no;
                //adicionar mais uma posição para o array
                contador++;
            }
            else if(abertos != NULL && fechados == NULL){
                no->proximo[contador] = abertos->no;
                //calcular p quanto andou
                no->proximo[contador]->g = no->g + 14;
                //distancia total que falta
                no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
                //linha e coluna da matriz
                no->proximo[contador]->linha = linhaOrigem +1;
                no->proximo[contador]->coluna = colunaOrigem +1;
                no->proximo[contador]->pai = no;
                //adicionar mais uma posição para o array
                contador++;
            }
        }
    }//fim de acoes para diracao para baixo

    //direcao diagonal acima para direita
    if(matriz[linhaOrigem -1][colunaOrigem +1] != PAREDE){

        //verificar se ao redor contem parede
        if(acima != PAREDE && direita != PAREDE){
            abertos = pecorreAberto(linhaOrigem -1,colunaOrigem +1);
            fechados = pecorreFechado(linhaOrigem -1,colunaOrigem +1);
            //verificando se o nó ja foi aberto
            if(abertos == NULL && fechados == NULL){
                no->proximo[contador] = (arvore*) malloc(sizeof(arvore));
                //Calcular distancia que falta
                no->proximo[contador]->h = distanciaFalta(linhaOrigem -1,colunaOrigem +1,linhaDestino,colunaDestino);
                //calcular p quanto andou
                no->proximo[contador]->g = no->g + 14;
                //distancia total que falta
                no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
                //linha e coluna da matriz
                no->proximo[contador]->linha = linhaOrigem -1;
                no->proximo[contador]->coluna = colunaOrigem +1;
                no->proximo[contador]->pai = no;
                //adicionar mais uma posição para o array
                contador++;
            }
            else if(abertos != NULL && fechados == NULL){
                no->proximo[contador] = abertos->no;
                //calcular p quanto andou
                no->proximo[contador]->g = no->g + 14;
                //distancia total que falta
                no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
                //linha e coluna da matriz
                no->proximo[contador]->linha = linhaOrigem -1;
                no->proximo[contador]->coluna = colunaOrigem +1;
                no->proximo[contador]->pai = no;
                //adicionar mais uma posição para o array
                contador++;
            }
        }
    }//fim de acoes para diracao diagonal direita acima

    //direcao diagonal acima para esquerda
    if(matriz[linhaOrigem -1][colunaOrigem -1] != PAREDE){

        //verificar se ao redor contem parede
        if(acima != PAREDE && esquerda != PAREDE){
            abertos = pecorreAberto(linhaOrigem -1,colunaOrigem -1);
            fechados = pecorreFechado(linhaOrigem -1,colunaOrigem -1);
            //verificando se o nó ja foi aberto
            if(abertos == NULL && fechados == NULL){
                no->proximo[contador] = (arvore*) malloc(sizeof(arvore));
                //Calcular distancia que falta
                no->proximo[contador]->h = distanciaFalta(linhaOrigem -1,colunaOrigem -1,linhaDestino,colunaDestino);
                //calcular p quanto andou
                no->proximo[contador]->g = no->g + 14;
                //distancia total que falta
                no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
                //linha e coluna da matriz
                no->proximo[contador]->linha = linhaOrigem -1;
                no->proximo[contador]->coluna = colunaOrigem -1;
                no->proximo[contador]->pai = no;
                //adicionar mais uma posição para o array
                contador++;
            }
            else if(abertos != NULL && fechados == NULL){
                no->proximo[contador] = abertos->no;
                //calcular p quanto andou
                no->proximo[contador]->g = no->g + 14;
                //distancia total que falta
                no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
                //linha e coluna da matriz
                no->proximo[contador]->linha = linhaOrigem -1;
                no->proximo[contador]->coluna = colunaOrigem -1;
                no->proximo[contador]->pai = no;
                //adicionar mais uma posição para o array
                contador++;
            }
        }
    }//fim de acoes para direcao diagonal acima esquerda

    //direcao diagonal abaixo para esquerda
    if(matriz[linhaOrigem +1][colunaOrigem -1] != PAREDE){

        //verificar se ao redor contem parede
        if(abaixo != PAREDE && esquerda != PAREDE){
            abertos = pecorreAberto(linhaOrigem +1,colunaOrigem -1);
            fechados = pecorreFechado(linhaOrigem +1,colunaOrigem -1);
            //verificando se o nó ja foi aberto
            if(abertos == NULL && fechados == NULL){
                no->proximo[contador] = (arvore*) malloc(sizeof(arvore));
                //Calcular distancia que falta
                no->proximo[contador]->h = distanciaFalta(linhaOrigem +1,colunaOrigem -1,linhaDestino,colunaDestino);
                //calcular p quanto andou
                no->proximo[contador]->g = no->g + 14;
                //distancia total que falta
                no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
                //linha e coluna da matriz
                no->proximo[contador]->linha = linhaOrigem +1;
                no->proximo[contador]->coluna = colunaOrigem -1;
                no->proximo[contador]->pai = no;
                //adicionar mais uma posição para o array
                contador++;

            }
            else if(abertos != NULL && fechados == NULL){
                no->proximo[contador] = abertos->no;
                //calcular p quanto andou
                no->proximo[contador]->g = no->g + 14;
                //distancia total que falta
                no->proximo[contador]->f = no->proximo[contador]->g + no->proximo[contador]->h;
                //linha e coluna da matriz
                no->proximo[contador]->linha = linhaOrigem +1;
                no->proximo[contador]->coluna = colunaOrigem -1;
                no->proximo[contador]->pai = no;
                //adicionar mais uma posição para o array
                contador++;

            }
        }
    }//fim de acoes para direcao diagonal abaixo esquerda

    //alocar quantidade de filhos do no
    no->filhos = contador;

}


#endif // METODOSMATRIZ_H_INCLUDED

