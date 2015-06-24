#ifndef __heuristica_HEADER__
#define __heuristica_HEADER__

/*--------------------------------------------------------------------------------
int MaiorGrau(TipoGrafo* grafo)

Função: retorna o vértice de maior grau do grafo.

Entrada: um ponteiro para o grafo.

Saída: índice do vértice de maior grau do grafo.
--------------------------------------------------------------------------------*/
int MaiorGrau(TipoGrafo* grafo);

/*--------------------------------------------------------------------------------
void AtualizaGrau(TipoGrafo* grafo, int v)

Função: atualiza os valores dos graus de cada vértice.

Entrada: um ponteiro para o grafo, um inteiro representando o vértice.

Saída: nenhuma.
--------------------------------------------------------------------------------*/
void AtualizaGrau(TipoGrafo* grafo, int v);

/*--------------------------------------------------------------------------------
int naoVisitada(TipoLista* lista)

Função: indica se há arestas que ainda não foram visitadas.

Entrada: um ponteiro para o grafo.

Saída: '1' para a resposta positiva e '0' para a resposta negativa.
--------------------------------------------------------------------------------*/
int NaoVisitada(TipoLista* lista);
#endif
