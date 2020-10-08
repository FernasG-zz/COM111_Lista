#include <stdlib.h>
#include <stdio.h>
#include "modulo.h"

Lista *criaLista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));

    if (li == NULL)
        *li = NULL;

    return li;
}

void liberaLista(Lista *li)
{
    if (li != NULL)
    {
        Elemento *no;
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanhoLista(Lista *li)
{
    if (li == NULL)
        return 0;

    int cont = 0; //  Contador
    Elemento *no = *li;

    while (no != NULL)
    {
        cont++;        //  Conta o numero de termos ate o ultimo
        no = no->prox; // Verifica se chegou no fim da lista (Ultimo termo = NULL)
    }
    return cont;
}

int vaziaLista(Lista *li)
{
    if (li == NULL)
        return 1; //  Lista nao foi criada/ não existente
    if (*li == NULL)
        return 1; //  Lista existente porém vazia
    return 0;
}

int insereInicioLista(Lista *li, Aluno al)
{
    if (li == NULL) // Se lista nao existe
        return 0;
    //  Aloca espaço para Lista
    Elemento *no = (Elemento *)malloc(sizeof(Elemento));
    if (no == NULL) //  Verifica alocação
        return 0;

    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;

    if (*li != NULL)
        (*li)->ant = no;

    *li = no;
    return 1;
}

int insereFinalLista(Lista *li, Aluno al)
{
    if (li == NULL) // Se lista nao existe
        return 0;
    //  Aloca espaço para Lista
    Elemento *no = (Elemento *)malloc(sizeof(Elemento));
    if (no == NULL) //  Verifica alocação
        return 0;

    no->dados = al;
    no->prox = NULL;

    if ((*li) == NULL) //  Lista vaiza: insere início
    {
        no->ant = NULL;
        *li = no;
    }
    else
    {
        Elemento *aux = *li;

        while (aux->prox != NULL)
            aux = aux->prox;

        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int insereOrdenadamente(Lista *li, Aluno al)
{   
    if(li == NULL) return 0;

    Elemento *no = (Elemento *)malloc(sizeof(Elemento));
    if(no == NULL) return 0;

    no->dados = al;
    if(vaziaLista(li)){
        no->prox = NULL;
        no->ant = NULL;
        return 1;
    }else{
        Elemento *ante, *atual = *li;

        while(atual != NULL && atual->dados.matricula < al.matricula){ //Loop aque faz as comparacoes
            ante = atual;
            atual = atual->prox;
        }

        if(atual == *li){ //Se o matricula for o primeiro elemento da lista
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }else{//Se nao for o inicio da lista a insercao é no meio ou no final
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if(atual != NULL)
                atual->ant = no;
        }
        
        return 1;
    }

}

int removeInicioLista(Lista *li)
{
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;

    Elemento *no = *li;
    *li = no->prox;
    if(no->prox != NULL)
        no->prox->ant = NULL;
    
    free(no);
    return 1;
}

int removeFinalLista(Lista *li)
{
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;

    Elemento *no = *li;
    while(no->prox != NULL)//Percorrer a lista ate NULL
        no = no->prox;

    if(no->ant == NULL)//Se a lista tiver somente um elemnto remove ele
        *li = no->prox;
    else
        no->ant->prox = NULL;            
    
    free(no);
    return 1;
}  

int removePorMatricula(Lista *li, int mat)
{
    if(li == NULL) return 0;
    Elemento *no = *li;

    while(no != NULL && no->dados.matricula != mat){//Percorre lista em busca da matricula
        no = no->prox;
    }

    if(no == NULL) return 0; // Nao encontrou a matricula
    if(no->ant == NULL) //Remove primeiro elemento
        *li = no->prox;
    else     //Removendo no meio
        no->ant->prox = no->prox;

    if(no->prox != NULL)// Remove no final
        no->prox->ant = no->ant;

    free(no);
    return 1;
} 

int consultaListaPosicao(Lista *li, int pos, Aluno *al)
{
    if(li == NULL || pos <= 0) return 0;
    Elemento *no = *li;
    int i = 1;
    while(no != NULL && i < pos){ //Percorre a lista ate a posicao passada
        no = no->prox;
        i++;
    } 
    if(no == NULL)
        return 0;
    else {
        *al = no->dados; //Retorna informacoes referente a posicao
        return 1;
    }
}   

int consultaListaMatricula(Lista *li, int mat, Aluno *al)
{
    if (li == NULL) return 0;
    Elemento *no = *li;

    while (no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }

    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

void imprimirLista(Lista *li){
    Elemento *no = *li;

    if(li != NULL){
        while(no != NULL){
            printf("\nMatricula: %d", no->dados.matricula);
            printf("\nNome: %s", no->dados.nome);
            printf("\nNota 1: %f", no->dados.n1);
            printf("\nNota 2: %f", no->dados.n2);
            printf("\nNota 3: %f", no->dados.n3);


            no = no->prox;
        }
    }
}