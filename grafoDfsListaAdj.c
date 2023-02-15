#include <stdio.h>
#include <stdlib.h>

// Nesse tipo de implementação, teremos uma lista ligada contendo os vértices, ao invés de uma matriz.
// Faremos uma busca em profundidade neste caso 

typedef struct node
{
    int w;             // valor do nó da lista
    struct node *prox; // ponteiro para o próximo nó
} node;

typedef struct grafo
{
    int vertices; // vertices do grafo
    int arestas;  // arestas do grafo
    node **adj;   // lista ligada com os vértices adjacentes
} graph;

// inicializa o grafo, passando o grafo e o número de vértices pré-definido e estático
void inicializar(graph *g, unsigned v)
{
    g->vertices = v;
    g->arestas = 0;
    g->adj = (node **)malloc(sizeof(node *) * g->vertices); // aloca a lista ligada. Adj é uma lista ligada agora
    for (int i = 0; i < g->vertices; i++)
    {
        g->adj[i] = NULL; // define os elementos da lista como nulos. A instância
    }
}

// Pesquisar e tentar executar o destruir de uma lista ligada por meio de uma recursão.
void destruir(graph *g)
{
    for (int i = 0; i < g->vertices; i++)
    {
        while (g->adj[i])
        {                                // enquanto a lista encadeada existe
            node *l = g->adj[i];         // l é auxiliar, armazena temporariamente o nó da lista, para que o nó próximo seja o nó atual e o nó atual seja liberado.
            g->adj[i] = g->adj[i]->prox; // nó atual é assumido pelo próximo nó
            free(l);                     // libera o espaço do nó auxiliar criado
            // temos que ter um nó auxiliar, pois quando damos free no espaço, se não temos ninguém apontando para o nó, esse nó é perdido e o nó liberado
            // não é o nó desejado, exemplo : g->adj[i] = g->adj[i]->prox; free(g->adj[i]); nesse caso o g->adj[i] é perdido pois ninguém aponta para ele
            // e o espaço liberado na verdade é o nó que era inicialmente o g[i]->prox;
        }
    }
    free(g->adj);
    g->vertices = g->arestas = 0; // zera o número de vértices e arestas já que a lista foi destruída
}

// adiciona um novo arco, ou seja faz uma relação entre dois vértices que são os passados como parâmetro
void adiciona_arco(graph *g, unsigned v, unsigned w)
{
    node *l = (node *)malloc(sizeof(node)); // define o elemento da lista
    l->w = w;                               // define o seu vértice como o vértice passado
    l->prox = g->adj[v];                    // seu próximo elemento apontará para o vértice passado para ser representado como arco
    g->adj[v] = l;                          // seu elemento atual se torna o próprio elemento da lista
    g->arestas++;
}

// busca em profundida em lista linkada. Coloca o vetor na posição do vértice como 1, dizendo que o vértice foi visitado
void dfs_private(graph *g, int vis[], unsigned v)
{
    vis[v] = 1;      // marca como o vértice visitado
    printf("%d", v); // printa o vértice
    for (node *n = g->adj[v]; n != NULL; n = n->prox)
    { // percorre todos os elementos da lista encadeada
        if (vis[n->w] == 0)
        {                              // se o vértice naquela posição for igual a zero
            dfs_private(g, vis, n->w); // chamar novamente a função na posição em que ele ainda não foi visitado para marca-lo como visitado e partir dele
        }
    }
}

void dfs(graph *g)
{
    int vis[g->vertices]; // cria o array de inteiros contendo todos os vértices
    for (unsigned v = 0; v < g->vertices; v++)
    {               // percorre todos os vértices
        vis[v] = 0; // deixa o vetor todos com zero, pois nenhum vértice foi visitado ainda
    }
    for (unsigned v = 0; v < g->vertices; v++)
    {
        if (vis[v] == 0)
        { // se o vértice não tiver sido visitado ainda, ele chama a função para visitar esse vértice
            dfs_private(g, vis, v);
        }
    }
}

int main()
{
    graph *exemplo;
    inicializar(exemplo, 6);
    adiciona_arco(exemplo, 0, 2);
    adiciona_arco(exemplo, 0, 3);
    adiciona_arco(exemplo, 0, 5);
    adiciona_arco(exemplo, 1, 0);
    adiciona_arco(exemplo, 2, 1);
    adiciona_arco(exemplo, 2, 4);
    adiciona_arco(exemplo, 4, 1);
    adiciona_arco(exemplo, 4, 3);
    dfs(exemplo);
    destruir(exemplo);
    return 0;
}