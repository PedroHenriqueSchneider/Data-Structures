#include <stdio.h>
#include <stdlib.h>

// Busca em profundidade, depth first search, ocorre quando percorremos recursivamente todos os vértices adjacentes (arcos) não marcados.
// quando passamos pelo vértice, marcamos que ele foi visitado. A busca em profundidade gera uma arvore enraizada no vértice que teve início.
// Nesse tipo de execução, estamos formalizando uma matriz, para armazenar o relacionamento entre vértices.
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

// Teremos como parâmetro o grafo, um vetor de quais foram os vértices visitados, v é o vértice visitado
void dfsPrivado(graph *G, int vis[], unsigned v)
{
    vis[v] = 1;      // define o vértice como visitado na posição do vetor
    printf("%u", v); // printa o vértice
    for (int w = 0; w < G->vertices; w++)
    { // roda por todas as colunas, do vértice v escolhido
    // se o vértice estiver ligado na aresta
        if (G->adj[v][w] == 1)
        { 
            if (vis[w] == 0)
            {                          // e se o vertice adjacente não tiver sido visitado ainda
                dfsPrivado(G, vis, w); // ele chama recursivamente a função para o próximo vértice
            }
        }
    }
}

void dfs(graph *G)
{
    int vis[G->vertices]; // define o vértice dos visitados
    for (int i = 0; i < G->vertices; i++)
    { // deixa todos os elementos do vetor de visitados como zero, ou seja, nenhum vértice foi visitado ainda.
        vis[i] = 0;
    }
    for (int i = 0; i < G->vertices; i++)
    { // percorre todos os elementos do vetor de visitados, se o vértice não tiver sido visitado, ele chama a função.
        if (vis[i] == 0)
            dfsPrivado(G, vis, i);
    }
}

int main()
{
    graph exemplo;
    inicializar(&exemplo, 6);
    adicionarAresta(&exemplo, 0, 2);
    adicionarAresta(&exemplo, 0, 3);
    adicionarAresta(&exemplo, 0, 5);
    adicionarAresta(&exemplo, 1, 0);
    adicionarAresta(&exemplo, 2, 1);
    adicionarAresta(&exemplo, 2, 4);
    adicionarAresta(&exemplo, 4, 1);
    adicionarAresta(&exemplo, 4, 3);
    dfs(&exemplo);
    destruir(&exemplo);
    return 0;
}
