#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

TipoLista* lista;
TipoGrafo* grafo;

/*--------------------------------------------------------------------------------
void CriaLista(TipoLista* lista)

Função: cria uma nova lista.
--------------------------------------------------------------------------------*/
void CriaLista(TipoLista* lista)
{
	lista->prim = (TipoPonteiro) malloc(sizeof(TipoAresta));
	lista->ult = lista->prim;
	lista->prim->prox = NULL;
}

/*--------------------------------------------------------------------------------
int ListaVazia(TipoLista* lista)

Função: verifica se uma lista está vazia ou não.
--------------------------------------------------------------------------------*/
int ListaVazia(TipoLista* lista)
{
	return (lista->prim == lista->ult);
}

/*--------------------------------------------------------------------------------
void InsereAresta(TipoLista* lista, int v1, int v2)

Função: insere uma aresta na lista passada como parâmetro.
--------------------------------------------------------------------------------*/
void InsereAresta(TipoLista* lista, int v1, int v2)
{
	lista->ult->prox = (TipoPonteiro) malloc(sizeof(TipoAresta));
	lista->ult = lista->ult->prox;
	lista->ult->vertice1 = v1;
	lista->ult->vertice2 = v2;
	lista->ult->prox = NULL;
}

/*--------------------------------------------------------------------------------
void RemoveArestas(TipoLista* lista, int v)

Função: remove as arestas na lista passada como parâmetro que contém o vértice 
passado como parâmetro.
--------------------------------------------------------------------------------*/
void RemoveArestas(TipoLista* lista, int v)
{
	TipoPonteiro ant;
	TipoPonteiro aux;
	TipoPonteiro item;
	int remocao;

	ant = lista->prim;

	if(!ListaVazia(lista))
	{
		while (ant->prox != NULL)
		{
			remocao = 0;
			aux = ant->prox;
			
			if ((aux->vertice1 == v) || (aux->vertice2 == v))
			{
				item = aux;
				ant->prox = aux->prox;

				if (ant->prox == NULL)
					lista->ult = ant;

				free(item);
				remocao = 1;
			}

			if (remocao == 0)
				ant = ant->prox;
		}
	}
}

/*--------------------------------------------------------------------------------
void LiberaGrafo(TipoGrafo* grafo)

Função: desaloca a memória utilizada pelo grafo.
--------------------------------------------------------------------------------*/
void LiberaGrafo(TipoGrafo* grafo)
{
	TipoPonteiro auxAnt, aux;

	aux = grafo->arestas->prim->prox;
	free(grafo->arestas->prim);
	grafo->arestas->prim = NULL;

	while (aux != NULL)
	{
		auxAnt = aux;
		aux = aux->prox;
		free(auxAnt);
	}

	free(grafo->arestas);
	free(grafo->vertices);
}
