// O sentinela fica no inicio e no fim da lista, ou seja, o sentinela aponta para o primeiro elemento da lista e o ultimo elemento da lista aponta para o sentinela..
// Na lista duplamente encadeada circular possuimos apenas um sentinela.
// Necessario ainda colocar os iteradores para colocar e remover elementos do meio da lista.

#include "lista.h"
// funcao que inicializa o sentinela
void inicializar(listaEncadeada *p)
{
    node *n = (node *)malloc(sizeof(node));
    n->prox = n->anterior = p->sentinela = n;
    p->quantidadeElements = 0;
    p->sentinela->ra = 0;
}

// destroi a lista e o sentinela
void destroyL(listaEncadeada *p)
{
    while (!vaziaL(p))
    {
        removeI(p);
    }
    free(p->sentinela);
}

int vaziaL(listaEncadeada *p)
{
    return p->sentinela->prox == p->sentinela;
}

int insereI(listaEncadeada *p, int ra)
{   // Funcao que recebe um numero de RA e insere no inicio da lista
    node *n = (node *)malloc(sizeof(node)); // aloca memoria
                                            // coloca dentro do elemento da struct ponteiro o elemento de quando chama a funcao
    n->ra = ra;
    n->prox = p->sentinela->prox; // coloca dentro do ponteiro que aponta para o proximo elemento o ponteiro da sentinela
    n->anterior = p->sentinela;   // coloca dentro do ponteiro que aponta para o elemento anterior o sentinela
    p->sentinela->prox = n;       // colocando dentro do sentinela que aponta para o proximo o struct n
    n->prox->anterior = n;
    p->quantidadeElements++; // aumenta dentro do struct o numero de elementos

    return n->ra;
}

int insereF(listaEncadeada *p, int ra)
{ // Funcao que recebe um numero de RA e insere na lista no fim
    node *n = (node *)malloc(sizeof(node));
    n->ra = ra;
    n->prox = p->sentinela;
    n->anterior = p->sentinela->anterior;
    p->sentinela->anterior = n;
    n->anterior->prox = n;
    p->quantidadeElements++;

    return n->ra;
}

int removeF(listaEncadeada *p)
{ // Remove um node do fim da lista
    node *n = p->sentinela->anterior;
    if (n != p->sentinela) // checando lista vazia
    {
        n->prox->anterior = n->anterior;
        n->anterior->prox = n->prox;
        int x = n->ra; // Reserva o valor de Ra para retorno
        free(n);
        p->quantidadeElements--;
        return x;
    }
    return -1;
}

int removeI(listaEncadeada *p)
{ // Remove um node do inicio da lista
    node *n = p->sentinela->prox;
    if (n != p->sentinela)
    { // lista vazia
        n->anterior->prox = n->prox;
        n->prox->anterior = n->anterior;
        int x = n->ra;
        free(n);
        p->quantidadeElements--;
        return x;
    }
    return -1;
}

//Para a segunda parte do projeto
iterador begin(listaEncadeada *p)
{
    iterador i;
    i.posicao = p->sentinela->prox;
    i.estrutura = p;
    return i;
}
iterador end(listaEncadeada *p)
{
    iterador i;
    i.posicao = p->sentinela->anterior;
    i.estrutura = p;
    return i;
}

int elemento(iterador i)
{
    return i.posicao->ra;
}

int acabou(iterador i)
{
    return i.posicao == i.estrutura->sentinela;
}

iterador proximo( iterador i)
{
    if(i.posicao != i.estrutura->sentinela)
        i.posicao = i.posicao->prox;

    return i;
}

iterador anterior(iterador i)
{
    if(i.posicao != i.estrutura->sentinela)
        i.posicao = i.posicao->anterior;
    
    return i;
}

void insereAntes(listaEncadeada *p, iterador it, int ra)
{  
    node *n = malloc(sizeof(node));
    listaEncadeada *l = p;

    n->ra = ra;
    n->prox = it.posicao;
    n->anterior = it.posicao->anterior;
    n->anterior->prox = n;
    n->prox->anterior = n;
    p->quantidadeElements++;
}


void insereDepois(listaEncadeada *p, iterador it, int ra)
{  
    node *n = malloc(sizeof(node));

    n->ra = ra;
    n->anterior = it.posicao;
    n->prox = it.posicao->prox;
    n->anterior->prox = n;
    n->prox->anterior = n;

    p->quantidadeElements++;

}

int removePosicao(listaEncadeada *p, iterador it)
{
    node *n = it.posicao;
    if (p->sentinela != it.posicao)
    {
        n->anterior->prox = n->prox;
        n->prox->anterior = n->anterior;
        int i = n->ra;
        proximo(it);
        free(n);
        return i;
    }
    return 0; 
}
void alunosCadastrados(listaEncadeada *p)
{
    node *n = p->sentinela->prox;
    while (n != p->sentinela)
    {
        n = n->prox;
    }
    return;
}