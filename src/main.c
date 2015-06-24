/*--------------------------------------------------------------------------------
Trabalho Prático de Pesquisa Operacional - DCC UFMG
Disciplina: DCC035 - Pesquisa Operacional

Alunos: Álvaro Souza; Daniel Hovadick; Guilherme Gonzaga.
Data: 16/06/2015

Arquivos: 'makefile', 'main.c', 'heuristica.c', 'heuristica.h',
	  'tipos.c' e 'tipos.h'
--------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "heuristica.h"

TipoGrafo Grafo;

int main(int argc, char* argv[])
{
	FILE* arq1;
	FILE* arq2;

	arq1 = fopen(argv[1], "r");
	arq2 = fopen(argv[2], "w");

	/*--------------------------------------------------------------------------------
	Leitura das primeiras informações do grafo.
	--------------------------------------------------------------------------------*/
	fscanf(arq1, "%d %d ", &Grafo.numVertices, &Grafo.numArestas);

	/*--------------------------------------------------------------------------------
	Alocação dinâmica do grafo.
	--------------------------------------------------------------------------------*/
	Grafo.arestas = (TipoLista*) malloc(Grafo.numArestas*sizeof(TipoLista));
	Grafo.vertices = (TipoVertice*) malloc(Grafo.numVertices*sizeof(TipoVertice));

	CriaLista(Grafo.arestas);

	/*--------------------------------------------------------------------------------
	Inicialização dos vértices e leitura dos pesos.
	--------------------------------------------------------------------------------*/
	int i;
	for (i=0; i<Grafo.numVertices; i++)
	{
		Grafo.vertices[i].id = i;
		Grafo.vertices[i].grau = 0;
		fscanf(arq1, "%d ", &Grafo.vertices[i].peso);
	}

	/*--------------------------------------------------------------------------------
	Leitura das arestas e verificação do grau de cada vértice.
	--------------------------------------------------------------------------------*/
	int v; char k;
	for (i=0; i<Grafo.numVertices; i++)
		{
		do
			{
			fscanf(arq1, "%d%c", &v, &k);

			if (i != v-1)
			{
				Grafo.vertices[i].grau++;
				Grafo.vertices[v-1].grau++;
				InsereAresta(Grafo.arestas, i, v-1);
			}	
		}while(k != '\n');
	}

	/*--------------------------------------------------------------------------------
	Identifica o vértice de maior grau (considerando apenas as arestas ainda não 
	cobertas); incrementa a quantidade de vértices à solução; incrementa o custo 
	da solução; registra a solução parcial no arquivo de saída; atualiza o valor dos 
	graus de cada vértice (desconsiderando as arestas já cobertas); remove da lista 
	de arestas aquelas já cobertas; e por fim, verifica se ainda há arestas não 
	cobertas.
	--------------------------------------------------------------------------------*/
	int maior; int minimo = 0; int custo = 0; int nao = 1;
	if ((Grafo.numVertices != 0) && (Grafo.numArestas != 0))
	{
		fprintf(arq2, "Vertices |\tGrau |\tCusto Parcial |\n");
		fprintf(arq2, "----------\t------\t---------------\n");
		do
		{
			maior = MaiorGrau(&Grafo);
			minimo++; custo = custo + Grafo.vertices[maior].peso;
			fprintf(arq2, "%8d |\t%4d |\t%13d |\n", maior+1, Grafo.vertices[maior].grau, custo);

			AtualizaGrau(&Grafo, maior);
			RemoveArestas(Grafo.arestas, maior);
			nao = NaoVisitada(Grafo.arestas);
		} while (nao != 0);

		fprintf(arq2, "\n\n");
	}

	/*--------------------------------------------------------------------------------
	Gravação da resposta no arquivo de saída.
	--------------------------------------------------------------------------------*/
	fprintf(arq2, "SOLUCAO\n");
	fprintf(arq2, "-------\n");
	fprintf(arq2, "* Nro de vertices : %d\n", minimo);
	fprintf(arq2, "* Custo total     : %d\n", custo);

	/*--------------------------------------------------------------------------------
	Liberação dos dados alocados dinamicamente e fechamento dos arquivos.
	--------------------------------------------------------------------------------*/
	LiberaGrafo(&Grafo);
	fclose(arq2);
	fclose(arq1);

	return 0;
}
