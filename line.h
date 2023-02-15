#ifndef FILA_H
#define FILA_H

typedef struct Aluno
{
    struct Aluno *link;
    int ra;
} Aluno;
typedef struct
{
    Aluno *primeiro, *ultimo;
    unsigned quantidade;
    int qnt_total;
} Fila;

void initialize(Fila *f, int n); // INICIA A FILA;
void destroyF(Fila *f);          // RETIRA TODOS OS ELEMENTOS
int vaziaF(Fila *f);             // VERIFICA SE A FILA ESTA VAZIA
int insere(Fila *f, int ra);     // INSERE NA FILA
int retira(Fila *f);
int cheia(Fila *f); // REMOVE O ELEMENTO DA FILA
#endif