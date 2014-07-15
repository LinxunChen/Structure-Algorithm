// DouLinkedList.cpp : �������̨Ӧ�ó������ڵ㡣
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
	p = head;
	do{
		p = p->next;
		printf("%d ", p->data);
	} while (p->next != NULL);
}

void main() {
	dnode *head;
	head = creat();
	printList(head);
}


