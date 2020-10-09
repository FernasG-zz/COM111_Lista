#include <stdlib.h> 
#include <stdio.h>
#include "modulo.h"

int criarValor(int *valor){
    printf("\nDigite um valor: ");
    scanf("%d", valor);

    return 1;
}

int main(){
    Lista *li = NULL;
    int opcao, res, valor, pos;

    do {
        printf("\n\nMenu de opções");
        printf("\n1 - Criar lista");
        printf("\n2 - Liberar lista");
        printf("\n3 - Inserir elemento no início");
        printf("\n4 - Inserir elemento no final");
        printf("\n5 - Inserir elemento (ordenado)");
        printf("\n6 - Remover elemento do início");
        printf("\n7 - Remover elemento do final");
        printf("\n8 - Remover elemento (especifo)");
        printf("\n9 - Buscar elemento pela posição");
        printf("\n10 - Buscar elemento pelo dado");
        printf("\n11 - Imprimir lista");
        printf("\n12 - Sair");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                li = criarLista();

                if(li != NULL){
                    printf("\n Lista criada com sucesso!");
                }else{
                    printf("\n Lista não criada!");
                }
                break;
            case 2:
                res = liberarLista(li);

                if(res){
                    printf("\n Lista liberada com sucesso!");
                }else{
                    printf("\n Lista não liberada!");
                }

                break;
            case 3:
                res = criarValor(&valor);
                res = inserirInicioLista(li, valor);

                if(res == 1){
                    printf("\n Inserção realizada com sucesso!");
                }else{
                    printf("\n Falha na inserção!");
                }

                break;
            case 4: 
                res = criarValor(&valor);
                res = inserirFinalLista(li, valor);

                if(res == 1){
                    printf("\n Inserção realizada com sucesso!");
                }else{
                    printf("\n Falha na inserção!");
                }

                break;
            case 5:
                res = criarValor(&valor);
                res = inserirOrdemLista(li, valor);

                if(res == 1){
                    printf("\n Inserção realizada com sucesso!");
                }else{
                    printf("\n Falha na inserção!");
                }

                break;
            case 6:
                res = removerInicioLista(li);

                if(res == 1){
                    printf("\n Remoção realizada com sucesso!");
                }else{
                    printf("\n Falha na remoção!");
                }

                break;
             case 7:
                res = removerFinalLista(li);

                if(res == 1){
                    printf("\n Remoção realizada com sucesso!");
                }else{
                    printf("\n Falha na remoção!");
                }

                break;
            case 8:
                res = criarValor(&valor);
                res = removerEspecifico(li, valor);

                if(res == 1){
                    printf("\n Remoção realizada com sucesso!");
                }else{
                    printf("\n Falha na remoção, elemento não encontrado!");
                }

                break;
            case 9:
                printf("\n Posição do elemento a ser buscado: ");
                scanf("%d", &pos);
                res = buscaCelulaPosicao(li, pos, &valor);

                 if(res){
                    printf("\n Busca realizada com sucesso!");
                    printf("\n Elemento da %dª posição: ", pos);
                    printf("%d", valor);
                }else{
                    printf("\n Posição não existe!");
                }

                break;
            case 10:
                printf("\n Valor a ser buscado: ");
                scanf("%d", &valor);

                res = buscaCelulaDado(li, valor, &pos);

                if(res){
                    printf("\n Busca realizada com sucesso!");
                    printf("\n Elemento da %dª posição: ", pos);
                    printf("%d", valor);
                }else{
                    printf("\n Elemento não encontrado!");
                }

                break;
            case 11:
                printf("\n Lista duplamente encadeada: ");
                res = imprimirLista(li);

                if(!res){
                    printf("\n Lista não encontrada!");
                }

                break;
            case 12:
                liberarLista(li);
                printf("\nFinalizando...");

                break;
        }

    }while (opcao != 12);

    return 0;
}