#include <iostream>
#include <limits.h>

// Numero de vertices do grafo.
#define V 9

using namespace std;

/*Função que encontra o valor minino da distancia, do conjunto
dos vertices que ainda não foram inclusos no menor caminho*/
int minDistance(int dist[], bool sptSet[])
{

	// inicializando valor minino.
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[])
{
	cout <<"Vertice \t Distancia da fonte" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t"<<dist[i]<< endl;
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // O vetor de saida. dist[i] vai conter o valor da menor distancia da fonte até i.
	

	bool sptSet[V]; /* sptSet[i] vai ser true se o vertice i for concluido no menor caminho
	ou na menor distancia da fonte ate i ser finalizado */ 

	// Inicializa todas as distancias sendo infinito e stpSet[] como false.
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distancia do vertice fonte dele mesmo que é igual a 0.
	dist[src] = 0;

	// encontra o menor caminho para todos os vertices.
	for (int count = 0; count < V - 1; count++) {
		/* Escolhe a minima distacia do vertice do grupo dos vertices ainda não processados.
		u é sempre igual a fonte na primeira interação.*/
		int u = minDistance(dist, sptSet);

		// Marca o vertice escolhido como processado.
		sptSet[u] = true;

		// Atualiza o valor de dist do vertice adjacente ao vertice escolhido.
		for (int v = 0; v < V; v++)

			/* Atualiza dist[v] somente se a condição !sptSet[v] for satisfeita,
            e o peso total do caminho, da fonte até v passndo por u,
            for menor que valor atual da dist[v]*/
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
				dist[v] = dist[u] + graph[u][v];
            }
	}

	
	printSolution(dist);
}