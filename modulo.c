#include <stdlib.h>
#include <stdio.h>
#include "modulo.h"

struct celula
{
    struct celula *ant;
    int valor;
    struct celula *prox;
};

int criarValor(void)
{
    int valor;
    printf("Digite um valor: ");
    scanf("%i", &valor);

    return valor;
}

Celula *alocarCelula()
{
    Celula *no = (Celula *)malloc(sizeof(Celula));

    return no;
}

Lista *alocarLista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));

    if (li != NULL)
        *li = NULL;

    return li;
}

int liberarLista(Lista *li)
{
    if (li == NULL) // verifica se a lista existe
        return 0;

    Celula *no;
    while (*li != NULL) // percorre os nos liberando o ultimo repetidamente
    {
        no = *li;
        *li = (*li)->prox;
        free(no);
    }

    free(li); // libera a cabeca da lista

    return 1;
}

int inserirInicioLista(Lista *li)
{
    if (li == NULL) // verifica se a lista existe
        return 0;

    int dado = criarValor();
    Celula *no = alocarCelula();

    if (no == NULL) // verifica se no foi criado corretamente
        return 0;

    if (*li == NULL) // se lista vazia, insere no comeco
    {
        no->valor = dado;
        no->prox = no->ant = NULL;
        *li = no;
    }
    else // se cheia, cabeca aponta para novo no, novo no aponta para proximo no
    {
        no->valor = dado;
        no->ant = NULL;
        no->prox = *li;
        (*li)->ant = no;
        *li = no;
    }

    return 1;
}

int inserirFinalLista(Lista *li)
{
    if (li == NULL) // verifica se a lista existe
        return 0;

    int dado = criarValor();
    Celula *no = alocarCelula();

    if (no == NULL) // verifica se no foi criado corretamente
        return 0;

    if ((*li) == NULL) // se lista vazia, insere no inicio
    {
        no->valor = dado;
        no->prox = no->ant = NULL;
        *li = no;
    }
    else // se cheia, insere no final
    {
        Celula *aux;
        aux = *li;

        while (aux->prox != NULL) // percorre a lista ate o final
            aux = aux->prox;

        no->valor = dado;
        no->ant = aux;
        no->prox = NULL;
        aux->prox = no;
    }

    return 1;
}

int inserirOrdemLista(Lista *li)
{
    if (li == NULL) // verifica se a lista existe
        return 0;

    int dado = criarValor();

    Celula *no = alocarCelula();

    if (no == NULL) // verifica se no foi criado corretamente
        return 0;

    no->valor = dado;

    if ((*li) == NULL) // se lista vazia, insere no inicio
    {
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
    }
    else // se cheia
    {
        Celula *anterior, *atual;
        atual = *li;

        while (atual != NULL && atual->valor < dado)
        {
            anterior = atual;
            atual = atual->prox;
        }

        if (atual == (*li))
        {
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }
        else
        {
            no->prox = anterior->prox;
            no->ant = anterior;
            anterior->prox = no;
            if (atual != NULL)
            {
                atual->ant = no;
            }
        }
    }

    return 1;
}

int removerInicioLista(Lista *li)
{
    if (li == NULL) // verifica se a lista existe
        return 0;

    if ((*li) == NULL)
        return 0;

    Celula *atual;
    atual = *li;
    *li = atual->prox;

    if (atual->prox != NULL)
        atual->prox->ant = NULL;

    free(atual);

    return 1;
}

int removerFinalLista(Lista *li)
{
    if (li == NULL) // verifica se a lista existe
        return 0;

    if ((*li) == NULL)
        return 0;

    Celula *atual;
    atual = *li;

    while (atual->prox != NULL)
        atual = atual->prox;

    if (atual->ant == NULL)
        *li = atual->prox;
    else
        atual->ant->prox = NULL;

    free(atual);

    return 1;
}

int removerEspecifico(Lista *li)
{
    if (li == NULL) // verifica se a lista existe
        return 0;

    if ((*li) == NULL)
        return 0;

    int dado = criarValor();

    Celula *atual;
    atual = *li;

    while (atual != NULL && atual->valor != dado)
        atual = atual->prox;

    if (atual == NULL)
        return 0;

    if (atual->ant == NULL)
        *li = atual->prox;
    else
        atual->ant->prox = atual->prox;

    if (atual->prox != NULL)
        atual->prox->ant = atual->ant;

    free(atual);
    return 1;
}

int buscaCelulaPosicao(Lista *li)
{
    int pos;
    printf("\nPosição do elemento a ser buscado: ");
    scanf("%d", &pos);

    if (li == NULL || (*li) == NULL || pos <= 0)
        return 0;

    Celula *no = *li;
    int i = 1;

    while (no != NULL && i < pos)
    {
        no = no->prox;
        i++;
    }

    if (no == NULL) // verifica se no foi criado corretamente
        return 0;

    printf("\nElemento da %dª posição: %d", pos, no->valor);

    return 1;
}

int buscaCelulaDado(Lista *li)
{
    if (li == NULL || (*li) == NULL)
        return 0;

    int valor, pos = 1;
    printf("\nValor a ser buscado: ");
    scanf("%d", &valor);

    Celula *no = *li;

    while (no != NULL && no->valor != valor)
    {
        no = no->prox;
        pos++;
    }

    if (no == NULL) // verifica se no foi criado corretamente
        return 0;

    printf("\nElemento %d está na %dª posição", valor, pos);

    return 1;
}

int imprimirLista(Lista *li)
{
    if (li == NULL || (*li) == NULL)
    {
        printf("\nLista não encontrada!");
        return 0;
    }

    printf("\nLISTA: ");

    Celula *aux = (*li);

    while (aux->prox != NULL)
    {
        printf(" %d ", aux->valor);
        aux = aux->prox;
    }

    printf(" %d ", aux->valor);

    return 1;
}
