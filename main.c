#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "modulo.h"

void criarAluno(Aluno *al){
    printf("\nCadastro de Aluno\nMatricula: ");
    scanf("%d", &al->matricula);
    printf("Nome: ");
    scanf(" %s", al->nome);
    printf("Nota 1:");
    scanf("%f", &al->n1);
    printf("Nota 2:");
    scanf("%f", &al->n2);
    printf("Nota 3:");
    scanf("%f", &al->n3);
}

int main()
{
    //  li = inicio da lista/primeiro no
    Lista *li = criaLista();
    Aluno al;
    int confirm = 0;
    int response;

    do{
        printf("\nEscolha uma opção: \n1 - Inserir no inicio\n2 - Inserir no final\n3 - Inserir ordenadamente\n4 - Remover no Inicio\n5 - Remover no Final\n6 - Remover por Matricula\n7 - Consultar posição\n9 - Consultar matricula\n10 - Imprimir lista\n0 - Sair\n:");
        scanf("%d", &confirm);

        switch(confirm){
            case 0:
                break;
            case 1: 
                criarAluno(&al);
                response = insereInicioLista(li, al);
                printf(response == 0 ? "Erro ao realizar insercao" : "Insercao feita com sucesso");
                break;
            case 10:
                imprimirLista(li);
                break;  
        
        }

    }while(confirm != 0);

    liberaLista(li);

    return 0;
}