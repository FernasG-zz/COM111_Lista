#include <stdlib.h>
#include <stdio.h>
#include "modulo.h"

int main()
{
    Lista *li = NULL;
    int opcao, res;

    do
    {
        printf("\n\n################# MENU DE OPCOES #################");
        printf("\n 0 - Sair\t\t\t\t\t 1 - Criar lista");
        printf("\n 2 - Liberar lista\t\t\t 3 - Inserir inicio");
        printf("\n 4 - Inserir final\t\t\t 5 - Inserir ordenado");
        printf("\n 6 - Remover inicio\t\t\t 7 - Remover final");
        printf("\n 8 - Remover especifico\t\t 9 - Buscar posição");
        printf("\n10 - Buscar dado\t\t\t11 - Imprimir lista");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 0:
            liberarLista(li);
            printf("\nFinalizando...\n\n");
            return 0;
            break;
        case 1:
            li = alocarLista();

            if (li != NULL)
                printf("\nLista criada com sucesso!");
            else
                printf("\nLista nao criada!");

            break;
        case 2:
            res = liberarLista(li);

            if (res == 1)
                printf("\nLista liberada com sucesso!");
            else
                printf("\nLista nao liberada!");

            break;
        case 3:
            res = inserirInicioLista(li);

            if (res == 1)
                printf("\nInsercao realizada com sucesso!");
            else
                printf("\nFalha na insercao!");

            break;
        case 4:
            res = inserirFinalLista(li);

            if (res == 1)
                printf("\nInsercao realizada com sucesso!");
            else
                printf("\nFalha na insercao!");

            break;
        case 5:
            res = inserirOrdemLista(li);

            if (res == 1)
                printf("\nInsercao realizada com sucesso!");
            else
                printf("\n Falha na insercao!");

            break;
        case 6:
            res = removerInicioLista(li);

            if (res == 1)
                printf("\nRemocao realizada com sucesso!");
            else
                printf("\nFalha na remocao!");

            break;
        case 7:
            res = removerFinalLista(li);

            if (res == 1)
                printf("\nRemocao realizada com sucesso!");
            else
                printf("\nFalha na remocao!");

            break;
        case 8:
            res = removerEspecifico(li);

            if (res == 1)
                printf("\nRemocao realizada com sucesso!");
            else
                printf("\nFalha na remocao, elemento nao encontrado!");

            break;
        case 9:
            res = buscaCelulaPosicao(li);

            if (res == 0)
                printf("\nPosicao nao existe!");

            break;
        case 10:
            res = buscaCelulaDado(li);

            if (res == 0)
                printf("\nElemento nao encontrado!");

            break;
        case 11:
            imprimirLista(li);
            break;

        default:
            printf("\nOpcao invalida!");
            break;
        }
    } while (1 == 1);

    return 0;
}