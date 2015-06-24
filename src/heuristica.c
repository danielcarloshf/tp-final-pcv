#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include "heuristica.h"

/*--------------------------------------------------------------------------------
int MaiorGrau(TipoGrafo* grafo)

Função: retorna o vértice de maior grau do grafo.
--------------------------------------------------------------------------------*/
int MaiorGrau(TipoGrafo* grafo)
{
	int i, maior;

	maior = 0;

	for (i=1; i<grafo->numVertices; i++)
	{
		if (grafo->vertices[i].grau > grafo->vertices[maior].grau)
			maior = i;
	}

	return maior;
}

/*--------------------------------------------------------------------------------
void AtualizaGrau(TipoGrafo* grafo, int v)

Função: propaga para as listas do grafo se determinada aresta foi visitada.
--------------------------------------------------------------------------------*/
void AtualizaGrau(TipoGrafo* grafo, int v)
{
	TipoAresta* aux;

	aux = grafo->arestas->prim->prox;
	
	while (aux != NULL)
	{
		if ((aux->vertice1 == v) || (aux->vertice2 == v))
		{
			grafo->vertices[aux->vertice1].grau--;
			grafo->vertices[aux->vertice2].grau--;
		}

		aux = aux->prox;
	}
}

/*--------------------------------------------------------------------------------
int NaoVisitada(TipoGrafo* grafo)

Função: indica se há arestas que ainda não foram visitados.
--------------------------------------------------------------------------------*/
int NaoVisitada(TipoLista* lista)
{
	return (!ListaVazia(lista));
}
