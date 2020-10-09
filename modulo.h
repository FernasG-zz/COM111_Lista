#ifndef _MODULO
#define _MODULO

typedef struct celula Celula;
typedef Celula *Lista;

int criarValor(int *valor);

// gerenciamento
Lista *alocarLista(void);
Celula *alocarCelula(void);
int liberarLista(Lista *li);

// insercao
int inserirInicioLista(Lista *li, int dado);
int inserirFinalLista(Lista *li, int dado);
int inserirOrdemLista(Lista *li, int dado);

// remocao
int removerInicioLista(Lista *li);
int removerFinalLista(Lista *li);
int removerEspecifico(Lista *li, int dado);

//consulta
int buscaCelulaPosicao(Lista *li, int pos, int *dado);
int buscaCelulaDado(Lista *li, int dado, int *pos);

//imprimir lista
int imprimirLista(Lista *li);

#endif
