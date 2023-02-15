#include <stdio.h>
#include <stdlib.h>

// Neste caso temos a implementação de uma busca em largura em grafos, o que ocorre neste caso é que ocorre a visita de seus vizinhos adjacentes
//de maneira instantanea, sendo assim, primeiro ele visita seus vizinhos mais proximos, para depois seguir. Aqui temos uma implementação de grafos em 
//matriz. 

struct grafo
{ // parte de cima da struct é usada para definir elementos do mesmo tipo, dentro da struct.
    // necessário termos vértices, arestas e a matriz.
    int vertices; // número de vértices do grafo.
    int aresta;   // número de arestas do grafo.
    int **adj;    // matriz de adjacência.
};                // parte de baixo da struct define o seu tipo.
typedef struct grafo graph;

// Define o número de vértices e arestas e instância a matriz.
void inicializar(graph *G, unsigned nVertices)
{                                                         // passa como parametro o próprio grafo e o número de vértices como unsigned pelo fato de n poder ser negativo
    G->vertices = nVertices;                              // número de vértices é estático e já pré-definido, nesse caso.
    G->aresta = 0;                                        // Como os vértices ainda não estão ligados, a quantidade de arestas é 0.
    G->adj = (int **)malloc(sizeof(int *) * G->vertices); // instância um array com o número de elementos iguais ao número de vértices.
    for (unsigned v = 0; v < G->vertices; v++)
    {
        G->adj[v] = (int *)malloc(sizeof(int) * G->vertices); // instancia para cada elemento do vetor, um outro vetor com o mesmo número de vértices.
                                                              // fazendo assim uma matriz.
    }
}

// passa por todos os elementos do array principal e da free nos mesmos.
void destruir(graph *G)
{
    for (unsigned v = 0; v < G->vertices; v++)
    {
        free(G->adj[v]); // damos free em cada elemento do vetor de vetores.
    }
    free(G->adj);                // posteriormente damos free no vetor completo.
    G->vertices = G->aresta = 0; // zeramos o número de vértices e arestas.
}

// Vamos passar como parâmetro o próprio grafo e quais são os dois vértices que desejamos ligar para fazer uma aresta. E adiciona mais uma aresta.
void adicionarAresta(graph *G, unsigned v, unsigned w)
{
    if (G->adj[v][w] == 0)
    {
        G->adj[v][w] = 1;
        G->aresta++;
    }
}

// Aqui temos a busca em largura 
void bfs(graph *g) {
    int vis[g->vertices]; // definimos o vetor de vértices visitados

    for(unsigned v = 0; v < g->vertices; v++) { // zeramos todo o vetor, pois nenhum vértice foi visitado ainda
        vis[v] = 0; 
    }

    fila f; // declara uma fila, first in - first out
    inicializaF(&f); // inicializa a fila 
    insereF(&f, 0); // insere na fila elemento 0, zero se refere ao primeiro vértice
    vis[0] = 1; // declara o zero como visitado

    while( !vaziaFila(f)) { // enquanto não chega no final da fila
        unsigned v = primeiroF(f); // pegamos o primeiro elemento da fila e colocamos em v
        removeF(&f); // removemos o primeiro elemento, lembrando que ele se encontra na váriavel v 

        printf("%u", v); // printa o elemetno removido

        for(unsigned w = 0; w < g->vertices; w++) { // percorre todos as colunas da matriz sobre a linha do vértice v 
            if(g->adj[v][w] == 1) { // se houver uma aresta, ou seja, o vértice v for ligado ao vértice w
                if(vis[w] == 0) { // e se o vértice ligado ao vértice v não tiver sido visitado
                    vis[w] = 1; // declaramos o vértice w como visitado
                    insereF(&f, w); // e então inserimos na fila o próximo vértice, sendo assim a fila sempre tera um elemento e quando ela estiver vazia,
                                    //então quer dizer que todos os vértices foram visitados
                }
            }
        }
    }
}

