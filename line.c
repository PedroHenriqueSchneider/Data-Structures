#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

// O PROGRAMA CONTEM TRES ENTRADAS
// A PRIMEIRA LINHA CONTEM "N", A QUANTIDADE DE ALUNOS QUE SE INSCREVERAM
// A SEGUNDA LINHA CONTEM OS ALUNOS QUE SE INSCREVERAM (NOME RA) EM ORDEM DE CHEGADA
// A TERCEIRA LINHA CONTEM UM NUMERO "V" DE VAGAS DISPONIVEIS
// A FILA IRA MANDA OS "V" PRIMEIROS ALUNOS PARA SEREM ORDENADOS E PRINTADOS PELA LISTA

void initialize(Fila *f, int n)
{ // INICIANDO A FILA
    f->primeiro = f->ultimo = NULL;
    f->quantidade = 0;
    f->qnt_total = n; // TAMANHO MAXIMO DA FILA
}
int vaziaF(Fila *f)
{ // INDICA SE A FILA ESTA FAZIA
    return f->primeiro == NULL;
}
int cheia(Fila *f)
{
    return f->quantidade == f->qnt_total;
}
void destroyF(Fila *f)
{ // RETIRANDO TODOS OS ELEMENTOS DA FILA
    while (!vaziaF(f))
    {
        retira(f);
    }
}
int insere(Fila *f, int ra)
{                                              // ADICIONANDO NA FILA OS ELEMENTOS
    Aluno *n = (Aluno *)malloc(sizeof(Aluno)); // ALOCANDO ESPACO NA MEMORIA
    n->ra = ra;                                // ITEM RECEBE O ELEMEfTO

    n->link = NULL;
    if (f->ultimo)
    { // SE O PONTEIRO *ULTIMO TIVER QUALQUER VALOR > 0, RECEBE O ENDERECO ALOCADO POR MALLOC
        f->ultimo->link = n;
    }
    else
    {
        f->primeiro = n;
    }
    f->ultimo = n;
    f->quantidade++;
    return n->ra;
}
int retira(Fila *f)
{
    int x = 0;
    if (!vaziaF(f))
    {                           // f->primeiro != NULL
        Aluno *n = f->primeiro; // PONTEIRO *N APONTA PASSA A APONTAR PARA ONDE O PONTEIRO *PRIMEIRO APONTA
        x = n->ra;              // VARIAVEL RECEBE O VALOR PARA ONDE O PONTEIRO *PRIMEIRO APONTA
        f->primeiro = n->link;  // PONTEIRO *PRIMEIRO PASSA A APONTAR PARA O PROXIMO DA SEQUENCIA
        free(n);                // LIBERANDO ESPACO NA MEMORIA
        if (f->primeiro == NULL)
        { // VERIFICANDO SE ACABOU A SEQUENCIA
            f->ultimo = NULL;
        }
        f->quantidade--;
    }
    return x;
}