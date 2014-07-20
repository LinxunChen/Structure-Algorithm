// DouLinkedList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct Student {
	int data;
	struct Student *next;
	struct Student *prior;
}dnode;

dnode *creat() {
	dnode *head, *p, *q, *s;
	head = (dnode *)malloc(sizeof(dnode));
	p = head;
	q = head;
	for (int i = 0; i < 5; i++) {
		s = (dnode *)malloc(sizeof(dnode));
		s->data = i;
		s->prior = p;
		p->next = s;
		q = p;
		p = s;
	}
	s->next = NULL;
	return head;
}

void printList(dnode *head) {
	dnode *p;
	p = head->next;
	do{
		printf("%d ", p->data);
		p = p->next;
	} while (p->next != NULL);
}

void main() {
	dnode *head;
	head = creat();
	printList(head);
}


