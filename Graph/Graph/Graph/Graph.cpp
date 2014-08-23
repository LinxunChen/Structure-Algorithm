// Graph.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>

#define MAX 100
#define FALSE 0
#define TRUE 1

typedef struct {
	int arc[MAX][MAX];
	int numVex, numEdge;
}MGraph;

typedef struct N {
	int data;
	struct N *next;
}Node;

typedef struct Q {
	Node *head=NULL, *tail=NULL;
}Queue;

void push(Queue *Q, int num) {
	if (Q == NULL) {
		return;
	}

	Node *nd = (Node *)malloc(sizeof(Node));
	nd->data = num;
	nd->next = NULL;

	if (Q->head == NULL) {//队列为空
		Q->head = nd;
		Q->tail = nd;
	}
	else{//队列非空
		Q->tail->next = nd;
		Q->tail = nd;
	}
}

int pop(Queue *Q) {
	if (Q == NULL) {//异常
		return -1;
	}
	if (Q->head == NULL) {//队列空了
		printf("queue is empty");
		return -1;
	}
	if (Q->head->next == NULL) {//队列只有1个元素
		int temp = Q->head->data;
		free(Q->head);
		Q->head = NULL;
		Q->tail = NULL;
		return temp;
	}
	else{//队列至少2个元素
		int temp = Q->head->data;
		Node *p = Q->head;
		Q->head = Q->head->next;
		free(p);
		return temp;
	}
}

int empty(Queue *Q) {
	if (Q == NULL) {
		return -1;
	}
	if (Q->head == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

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
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	queue->head = NULL; 
	queue->tail = NULL;

	for (int i = 0; i < G.numVex; i++) {
		visited[i] = FALSE;
	}

	for (int i = 0; i < G.numVex; i++) {
		if (!visited[i]){
			visited[i] = TRUE;
			printf("%d", i);
			push(queue, i);

			while (!empty(queue)) {
				int j = pop(queue);
				for (int k = 0; k < G.numVex; k++) {
					if (!visited[k] && G.arc[j][k] == 1) {
						visited[k] = TRUE;
						printf("%d", k);
						push(queue, k);
					}
				}
			}
		}
	}
}

void main(){
	MGraph *G = (MGraph *)malloc(sizeof(MGraph));
	creatMGraph(G);
	//DFSTransvel(*G);
	BFS(*G);
}


