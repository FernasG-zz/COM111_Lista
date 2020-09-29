#include <stdlib.h>
#include <stdio.h>
#include "modulo.h"

int main()
{
    //  li = inicio da lista/primeiro no
    Lista *li = criaLista();

    liberaLista(li);

    int n = tamanhoLista(li);

    return 0;
}