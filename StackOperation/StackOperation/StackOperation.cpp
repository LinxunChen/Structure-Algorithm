// StackOperation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>

typedef struct Student {
	int data;
	struct Student *next;
}node;

typedef struct stack {
	node *bottom, *top;
}stack;

stack *push(stack *HQ, int content) {
	node *s = (node *)malloc(sizeof(node));
	s->data = content;
	s->next = NULL;

	if (HQ->top == NULL) {
		HQ->bottom = s;
		HQ->top = s;
	}
	else {
		HQ->top->next = s;
		HQ->top = s;
	}
	return HQ;
}

stack *pop(stack *HQ) {
	node *p;

	if (HQ->top == NULL) {
		printf("溢出了");
	}
	else if (HQ->bottom == HQ->top) {
		free(HQ->bottom);
		HQ->bottom = NULL;
		HQ->top = NULL;
	}
	else {
		p = HQ->bottom;
		while (p->next != HQ->top) {
			p = p->next;
		}
		free(HQ->top);
		HQ->top = p;
		p->next = NULL;
	}
	return HQ;
}

void print(stack *HQ) {
	node *p;
	p = HQ->bottom;

	do {
		printf("%d ", p->data);
		p = p->next;
	} while (p != NULL);
}

void main() {
	stack *HQ = (stack *)malloc(sizeof(stack));
	HQ->bottom = NULL;
	HQ->top = NULL;
	HQ = push(HQ, 3);
	HQ = push(HQ, 5);
	HQ = push(HQ, 7);
	HQ = pop(HQ);
	HQ = pop(HQ);
	print(HQ);
}