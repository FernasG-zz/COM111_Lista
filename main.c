#include <stdlib.h>
#include <stdio.h>
#include "modulo.c"
#include "modulo.h"

int main()
{
    Lista *li = NULL;
    int opcao, res, valor, pos;

    do
    {
        printf("\n\n################### MENU DE OPCOES ###################");
        printf("\n 0 - Sair\t\t\t 1 - Criar lista");
        printf("\n 2 - Liberar lista\t\t 3 - Inserir inicio");
        printf("\n 4 - Inserir final\t\t 5 - Inserir ordenado");
        printf("\n 6 - Remover inicio\t\t 7 - Remover final");
        printf("\n 8 - Remover especifico\t\t 9 - Buscar posição");
        printf("\n10 - Buscar dado\t\t11 - Imprimir lista");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            li = alocarLista();

            if (li != NULL)
                printf("\nLista criada com sucesso!");
            else
                printf("\nLista não criada!");

            break;
        case 2:
            res = liberarLista(li);

            if (res)
                printf("\nLista liberada com sucesso!");
            else
                printf("\nLista não liberada!");

            break;
        case 3:
            res = criarValor(&valor);
            res = inserirInicioLista(li, valor);

            if (res == 1)
                printf("\nInserção realizada com sucesso!");
            else
                printf("\nFalha na inserção!");

            break;
        case 4:
            res = criarValor(&valor);
            res = inserirFinalLista(li, valor);

            if (res == 1)
                printf("\nInserção realizada com sucesso!");
            else
                printf("\nFalha na inserção!");

            break;
        case 5:
            res = criarValor(&valor);
            res = inserirOrdemLista(li, valor);

            if (res == 1)
                printf("\nInserção realizada com sucesso!");
            else
                printf("\n Falha na inserção!");

            break;
        case 6:
            res = removerInicioLista(li);

            if (res == 1)
                printf("\nRemoção realizada com sucesso!");
            else
                printf("\nFalha na remoção!");

            break;
        case 7:
            res = removerFinalLista(li);

            if (res == 1)
                printf("\nRemoção realizada com sucesso!");
            else
                printf("\nFalha na remoção!");

            break;
        case 8:
            res = criarValor(&valor);
            res = removerEspecifico(li, valor);

            if (res == 1)
                printf("\nRemoção realizada com sucesso!");
            else
                printf("\nFalha na remoção, elemento não encontrado!");

            break;
        case 9:
            printf("\nPosição do elemento a ser buscado: ");
            scanf("%d", &pos);
            res = buscaCelulaPosicao(li, pos, &valor);

            if (res)
            {
                printf("\nBusca realizada com sucesso!");
                printf("\nElemento da %dª posição: ", pos);
                printf("%d", valor);
            }
            else
                printf("\nPosição não existe!");

            break;
        case 10:
            printf("\nValor a ser buscado: ");
            scanf("%d", &valor);

            res = buscaCelulaDado(li, valor, &pos);

            if (res)
            {
                printf("\n Busca realizada com sucesso!");
                printf("\n Elemento da %dª posição: ", pos);
                printf("%d", valor);
            }
            else
                printf("\n Elemento não encontrado!");

            break;
        case 11:
            imprimirLista(li);
            break;

        default:
            liberarLista(li);
            printf("\nFinalizando...");
            break;
        }
    } while (opcao != 12);

    return 0;
}