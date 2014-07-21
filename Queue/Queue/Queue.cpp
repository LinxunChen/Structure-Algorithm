// Queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct Student {
	int data;
	struct Student *next;
}node;

typedef struct LinkQueue {
	node *front, *rear;
}queue;

queue *insert(queue *HQ, int content) {
	node *s;
	s = (node *)malloc(sizeof(node));
	s->data = content;
	s->next = NULL;

	if (HQ->rear == NULL) {
		HQ->front = s;
		HQ->rear = s;
	}
	else {
		HQ->rear->next = s;
		HQ->rear = s;
	}
	return HQ;
}

queue *del(queue *HQ) {
	node *p;

	if (HQ->front == NULL) {
		printf("溢出了");
	}
	else if(HQ->front == HQ->rear) {
		free(HQ->front);
		HQ->front = NULL;
		HQ->rear = NULL;
	}
	else {
		p = HQ->front;
		HQ->front = HQ->front->next;
		free(p);
	}
	return HQ;
}

void print(queue *HQ) {
	node *p;
	p = HQ->front;

	do {
		printf("%d ", p->data);
		p = p->next;
	} while (p != NULL);
}

void main() {
	queue *HQ = (queue *)malloc(sizeof(queue));
	HQ->front = NULL;
	HQ->rear = NULL;
	HQ = insert(HQ, 3);
	HQ = insert(HQ, 5);
	HQ = insert(HQ, 7);
	HQ = del(HQ);
	print(HQ);
}
