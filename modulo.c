#include <stdlib.h>
#include <stdio.h>
#include "modulo.h"

Lista *criaLista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));

    if (li != NULL)
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