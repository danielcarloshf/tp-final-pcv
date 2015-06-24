#ifndef __tipos_HEADER__
#define __tipos_HEADER__

/*--------------------------------------------------------------------------------
struct TipoCelula* TipoPonteiro
--------------------------------------------------------------------------------*/
typedef struct TipoAresta* TipoPonteiro;

/*--------------------------------------------------------------------------------
struct TipoVertice

- int id: identificador do vértice;
- int peso: indica o peso do vértice;
- int grau: grau do vértice.
--------------------------------------------------------------------------------*/
typedef struct TipoVertice
{
	int id, peso, grau;
}TipoVertice;

/*--------------------------------------------------------------------------------
struct TipoAresta

- int vertice1: primeiro vértice da aresta;
- int vertice2: segundo vértice da aresta;
- TipoPonteiro prox: ponteiro para o próxima aresta na lista.
--------------------------------------------------------------------------------*/
typedef struct TipoAresta
{
	int vertice1, vertice2;
	TipoPonteiro prox;
}TipoAresta;

/*--------------------------------------------------------------------------------
struct TipoLista

- TipoPonteiro prim: ponteiro para a primeira célula da lista;
- TipoPonteiro ult: ponteiro para a última célula da lista.
--------------------------------------------------------------------------------*/
typedef struct TipoLista
{
	TipoPonteiro prim, ult;
}TipoLista;

/*--------------------------------------------------------------------------------
struct TipoGrafo

- TipoLista* arestas: ponteiro para a lista com as arestas do grafo;
- TipoVertice* vertice: ponteiro para o vetor com os vértices do grafo;
- int numAresta: número de arestas do grafo;
- int numVertices: número de vértices do grafo.
--------------------------------------------------------------------------------*/
typedef struct TipoGrafo
{
	TipoLista* arestas;
	TipoVertice* vertices;
	int numArestas, numVertices;
}TipoGrafo;

/*--------------------------------------------------------------------------------
void CriaLista(TipoLista* lista)

Função: cria uma nova lista.

Entrada: um ponteiro para uma lista.

Saída: nenhuma.
--------------------------------------------------------------------------------*/
void CriaLista(TipoLista* lista);

/*--------------------------------------------------------------------------------
int ListaVazia(TipoLista* lista)

Função: verifica se uma lista está vazia ou não.

Entrada: um ponteiro para a lista.

Saída: um inteiro '0' significando 'lista não vazia' ou '1' para 'lista vazia'.
--------------------------------------------------------------------------------*/
int ListaVazia(TipoLista* lista);

/*--------------------------------------------------------------------------------
void InsereAresta(TipoGrafo* grafo, int v1, int v2)

Função: insere uma aresta no grafo passado como parâmetro.

Entrada: um ponteiro para a lista e dois inteiros representando os 
identificadores dos vértices adjacentes.

Saída: nenhuma.
--------------------------------------------------------------------------------*/
void InsereAresta(TipoLista* lista, int v1, int v2);

/*--------------------------------------------------------------------------------
void RemoveArestas(TipoLista* lista, int v)

Função: remove as arestas na lista passada como parâmetro que contém o vértice 
passado como parâmetro.

Entrada: um ponteiro para o grafo e um identificador do vértice.

Saída: nenhuma.
--------------------------------------------------------------------------------*/
void RemoveArestas(TipoLista* lista, int v);

/*--------------------------------------------------------------------------------
void LiberaGrafo(TipoGrafo* grafo)

Função: desaloca a memória utilizada pelo grafo.

Entrada: um ponteiro para o grafo.

Saída: nenhuma.
--------------------------------------------------------------------------------*/
void LiberaGrafo(TipoGrafo* grafo);
#endif
