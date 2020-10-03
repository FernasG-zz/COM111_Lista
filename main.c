#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "modulo.h"

int main()
{
    //  li = inicio da lista/primeiro no
    Lista *li = criaLista();
    int confirm = 0;

    do{
        printf("Escolha uma opção: \n1 - Inserir no inicio\n2 - Inserir no final\n3 - Inserir ordenadamente\n4 - Remover no Inicio\n5 - Remover no Final\n6 - Remover por Matricula\n7 - Consultar posição\n9 - Consultar matricula\n10 - Imprimir lista\n0 - Sair\n:");
        scanf("%d", &confirm);

        switch(confirm){
            case 0:
                break;
        }

    }while(confirm != 0);

    liberaLista(li);

    return 0;
}