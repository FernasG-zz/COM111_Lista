typedef struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
} Aluno;

typedef struct elemento
{
    Elemento *ant;
    Aluno dados;
    Elemento *prox;
} Elemento;

typedef Elemento *Lista;

Lista *criaLista();

void liberaLista(Lista *li);

int tamanhoLista(Lista *li);

int vaziaLista(Lista *li);

int insereInicioLista(Lista *li, Aluno al);

int insereFinalLista(Lista *li, Aluno al);