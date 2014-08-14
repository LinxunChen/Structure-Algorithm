// Graph.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>
#include<queue>

#define MAX 100
#define FALSE 0
#define TRUE 1

typedef struct {
	int arc[MAX][MAX];
	int numVex, numEdge;
}MGraph;

void creatMGraph(MGraph *G) {
	printf("please enter numVex and numEdge\n");
	scanf_s("%d, %d", &G->numVex, &G->numEdge);

	for (int i = 0; i < G->numVex; i++) {
		for (int j = 0; j < G->numVex; j++) {
			G->arc[i][j] = 0;
		}
	}

	for (int i = 0; i < G->numEdge; i++) {
		int m, n;
		printf("please enter two vexes of each edge\n");
		scanf_s("%d, %d", &m, &n);
		G->arc[m][n] = 1;
		G->arc[n][m] = G->arc[m][n];
	}
}

typedef int boolean;
boolean visited[MAX];

void DFS(MGraph G, int i) {
	visited[i] = TRUE;
	printf("%d", i);
	for (int j = 0; j < G.numVex; j++) {
		if (!visited[j] && G.arc[i][j] == 1) {
			DFS(G, j);
		}
	}
}

void DFSTransvel(MGraph G) {
	for (int i = 0; i < G.numVex; i++) {
		visited[i] = FALSE;
	}

	for (int i = 0; i < G.numVex; i++) {
		if (!visited[i]) {
			DFS(G, i);
		}
	}
}

void BFS(MGraph G) {
	for (int i = 0; i < G.numVex; i++) {
		visited[i] = FALSE;
	}

	for (int i = 0; i < G.numVex; i++) {
		if (!visited[i]){
			visited[i] = TRUE;
			printf("%d", i);

			queue<int> Q;

		}
	}
}

void main(){
	MGraph *G = (MGraph *)malloc(sizeof(MGraph));
	creatMGraph(G);
	//DFSTransvel(*G);
	BFS(*G);
}


