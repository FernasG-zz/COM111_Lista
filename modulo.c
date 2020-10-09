#include <stdlib.h> 
#include <stdio.h>
#include "modulo.h"

typedef struct celula{
    struct celula *prox;
    struct celula *ant;
    int valor;
}Celula;

Lista * criarLista(){
    Lista *li = (Lista*)malloc(sizeof(Lista));

    if(li != NULL){
        *li = NULL;
    }

    return li;
}

int liberarLista(Lista *li){
    if(li == NULL){    
        return 0;
    }

    Celula *no;
    while(*li != NULL){
        no = *li;
        *li = (*li)->prox;
        free(no);
    }

  free(li);

  return 1; 
}

Celula *criarCelula(){
    Celula *no = (Celula*) malloc(sizeof(Celula));  

    return no;
}

int inserirInicioLista(Lista *li, int dado){
    if(li == NULL){
        return 0;
    }

    Celula *no;
    no = criarCelula();

    if(no == NULL){
        return 0;
    }

    if(*li == NULL){ 
        no->valor = dado; 
        no->prox = no->ant = NULL; 
        *li = no;
    }
    else{   
        no->valor = dado; 
        no->ant = NULL;
        no->prox = *li;
        (*li)->ant = no;
        *li = no;
    }

    return 1;
}

int inserirFinalLista(Lista *li, int dado){
    if(li == NULL){
        return 0;
    }

    Celula *no;
    no = criarCelula();

    if(no == NULL){
        return 0;
    }

    if( (*li) == NULL ){
        no->valor = dado;    
        no->prox = no->ant = NULL;
        *li = no;
    }else{
        Celula *aux;
        aux = *li;
         
        while(aux->prox != NULL){
            aux = aux->prox;
        }

        no->valor = dado;
        no->ant = aux;
        no->prox = NULL; 
        aux->prox = no; 

    }

    return 1;
}

int inserirOrdemLista(Lista *li, int dado){
    if(li == NULL){
        return 0;
    }

    Celula *no;
    no = criarCelula();

    if(no == NULL){
        return 0;
    }

    no->valor = dado;

    if( (*li) == NULL ){
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
    }else{
        Celula *anterior, *atual;
        atual = *li;

        while(atual != NULL && atual->valor < dado){
            anterior = atual;
            atual = atual->prox;
        }
        
        if( atual == (*li) ){
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = anterior->prox;
            no->ant = anterior;
            anterior->prox = no;
            if(atual != NULL){
                atual->ant = no;
            }
        }
  }

  return 1;
}

int removerInicioLista(Lista *li){
    if(li == NULL){
        return 0;
    } 

    if((*li) == NULL){
        return 0;
    }

    Celula *atual;
    atual = *li;
    *li = atual->prox;
    if(atual->prox !=  NULL){
        atual->prox->ant = NULL;
    }

    free(atual);

    return 1;
}

int removerFinalLista(Lista *li){
    if(li == NULL){
        return 0;
    }

    if((*li) == NULL){
        return 0;
    }

    Celula *atual;
    atual = *li;
  
    while(atual->prox != NULL){
        atual = atual->prox;
    }

    if(atual->ant == NULL){ 
        *li = atual->prox;  
    }else{
        atual->ant->prox = NULL;
    }

    free(atual);

  return 1;

}

int removerEspecifico(Lista *li, int dado){
    if(li == NULL){
        return 0;
    }

    if((*li) == NULL){
        return 0;
    }

    Celula *atual;
    atual = *li;

    while(atual != NULL && atual->valor != dado){
        atual = atual->prox;
    }

    if(atual == NULL){
        return 0;
    }

    if(atual->ant == NULL){
        *li = atual->prox;
    }else{
        atual->ant->prox = atual->prox;
    }

    if(atual->prox != NULL){
        atual->prox->ant = atual->ant;
    }

    free(atual);
    return 1;
}

int buscaCelulaPosicao(Lista *li, int pos, int *dado){
    if(li == NULL || (*li) == NULL || pos <= 0){
        return 0;
    }

    Celula *no = *li;
    int i = 1;

    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }

    if(no == NULL){
        return 0;
    }else{
        *dado = no->valor;
    }

    return 1;
}

int buscaCelulaDado(Lista *li, int dado, int *pos){
    if(li == NULL || (*li) == NULL){
        return 0;
    }

    Celula *no = *li;
    int i = 1;

    while(no != NULL && no->valor != dado){
        no = no->prox;
        i++;
    }
  
    if(no == NULL){ 
        return 0;
    }else{
        *pos = i; 
    }

    return 1;
}

int imprimirLista(Lista *li){
    if(li == NULL || (*li) == NULL){
        return 0;
    }

    Celula *aux = (*li);

    while(aux->prox != NULL){
      printf(" %d ", aux->valor);
      aux = aux->prox;
    }

    printf(" %d ", aux->valor);

    return 1;
}
