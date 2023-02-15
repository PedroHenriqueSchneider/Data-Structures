#ifndef LISTA_H // conferir se é com letra maiúscula!
#define LISTA_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct node
{ // elemento dentro do struct. Observar se vai ser do tipo char ou int ou float
    int ra;
    struct node *prox, *anterior; // ponteiro que aponta para o elemento da frente e de trás
} node;

typedef struct
{
    node *sentinela;             // ponteiro do sentinela
    unsigned quantidadeElements; // quantidade de elementos armazenados
} listaEncadeada;

typedef struct
{
    struct node *posicao;
    listaEncadeada *estrutura;
} iterador;

void inicializar(listaEncadeada *p);
void destroyL(listaEncadeada *p);
int vaziaL(listaEncadeada *p);
int insereI(listaEncadeada *p, int ra);
int insereF(listaEncadeada *p, int ra);
int removeI(listaEncadeada *p);
int removeF(listaEncadeada *p);
void alunosCadastrados(listaEncadeada *p);
iterador begin(listaEncadeada *p);
iterador end(listaEncadeada *p);
iterador proximo( iterador i);
int acabou(iterador i);
int elemento(iterador i);
void insereAntes(listaEncadeada *p, iterador it, int ra);
void insereDepois(listaEncadeada *p, iterador it, int ra);
int removePosicao(listaEncadeada *p, iterador it);

#endif