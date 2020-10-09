#ifndef _MODULO
#define _MODULO

typedef struct celula Celula;
typedef Celula *Lista;

//  gerenciamento
int criarValor(void);
Lista *alocarLista(void);
Celula *alocarCelula(void);
int liberarLista(Lista *li);

//  insercao
int inserirInicioLista(Lista *li);
int inserirFinalLista(Lista *li);
int inserirOrdemLista(Lista *li);

//  remocao
int removerInicioLista(Lista *li);
int removerFinalLista(Lista *li);
int removerEspecifico(Lista *li);

//  consulta
int buscaCelulaPosicao(Lista *li);
int buscaCelulaDado(Lista *li);

//  imprimir lista
int imprimirLista(Lista *li);

#endif
