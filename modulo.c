#include <stdlib.h>
#include <stdio.h>
#include "modulo.h"

struct aluno
{
    int matricula;
    char nome[30];
    float nota;
};

struct celula
{
    Celula *ant;
    Aluno al;
    Celula *prox;
};

void preencherAluno(Aluno *al)
{
    printf("\nNome: ");
    scanf("%s", al->nome);
    printf("Matricula: ");
    scanf("%d", &al->matricula);
    printf("Nota: ");
    scanf("%f", &al->nota);
}

Aluno *alocarAluno()
{
    Aluno *al = (Aluno *)malloc(sizeof(Aluno));
    return al;
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
    if (li == NULL) // verifica se a lista foi alocada
        return 0;

    Celula *aux;
    while (*li != NULL) // percorre os nos liberando o ultimo repetidamente
    {
        aux = *li;
        *li = (*li)->prox;
        free(aux);
    }

    free(li); // libera a cabeca da lista

    return 1;
}

int inserirInicioLista(Lista *li)
{
    if (li == NULL) // verifica se a lista foi alocada corretamente
        return 0;

    Aluno *al = alocarAluno(); // cria um aluno novo
    preencherAluno(al);

    Celula *no = alocarCelula(); // cria uma celula nova

    if (no == NULL) // verifica se no foi criado corretamente
        return 0;

    no->al = *al;
    no->ant = NULL;
    no->prox = *li;
    // (*li)->ant = NULL;
    *li = no;

    return 1;
}

int inserirFinalLista(Lista *li)
{
    if (li == NULL) // verifica se a lista foi alocada corretamente
        return 0;

    Aluno *al = alocarAluno(); // cria um aluno novo
    preencherAluno(al);

    Celula *no = alocarCelula(); // cria uma celula nova

    if (no == NULL) // verifica se no foi criado corretamente
        return 0;

    if ((*li) == NULL) // se lista vazia, insere no inicio
    {
        no->al = *al;
        no->prox = no->ant = NULL;
        *li = no;
    }
    else // se cheia, insere no final
    {
        Celula *aux = *li;

        while (aux->prox != NULL) // percorre a lista ate o final
            aux = aux->prox;

        no->al = *al;
        no->ant = aux;
        no->prox = NULL;
        aux->prox = no;
    }

    return 1;
}

int inserirOrdemLista(Lista *li)
{
    if (li == NULL) // verifica se a lista foi alocada corretamente
        return 0;

    Aluno *al = alocarAluno(); // cria um aluno novo
    preencherAluno(al);

    Celula *no = alocarCelula(); // cria uma celula nova

    if (no == NULL) // verifica se no foi criado corretamente
        return 0;

    no->al = *al;

    if ((*li) == NULL) // se lista vazia, insere no inicio
    {

        no->prox = no->ant = NULL;
        *li = no;
    }
    else // se cheia
    {
        Celula *anterior, *proximo;
        proximo = *li;

        while (proximo != NULL && proximo->al.matricula < al->matricula)
        { // percorre a lista ate achar o local correto
            anterior = proximo;
            proximo = proximo->prox;
        }

        if (proximo == (*li)) // insere na primeira posicao
        {
            no->ant = NULL;
            no->prox = (*li);
            (*li)->ant = no;
            *li = no;
        }
        else // insere no local encontrado
        {
            no->prox = proximo;
            no->ant = anterior;
            anterior->prox = no;
            if (proximo != NULL)
            {
                proximo->ant = no;
            }
        }
    }

    return 1;
}

int removerInicioLista(Lista *li)
{
    if (li == NULL) // verifica se a lista foi alocada corretamente
        return 0;   // lista nao existe

    if ((*li) == NULL) // verifica se a lista foi criada corretamente
        return 0;      // mas não contém nenhum valor

    Celula *aux;
    aux = *li;
    *li = aux->prox;

    if (aux->prox != NULL)
        aux->prox->ant = NULL;

    free(aux);

    return 1;
}

int removerFinalLista(Lista *li)
{
    if (li == NULL) // verifica se a lista foi alocada corretamente
        return 0;

    if ((*li) == NULL) // verifica se a lista foi criada corretamente
        return 0;      // mas não contém nenhum valor

    Celula *atual;
    atual = *li;

    while (atual->prox != NULL) // percorre lista até o final
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

    if ((*li) == NULL) // verifica se a lista foi criada corretamente
        return 0;      // mas não contém nenhum valor

    int dado = criarValor();

    Celula *atual;
    atual = *li;

    while (atual != NULL && atual->al.matricula != dado)
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
