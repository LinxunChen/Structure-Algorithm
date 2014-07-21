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
	for (int i = 0; i < 9; i++) {
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

dnode *insert(dnode *head, int content, int insertCont) {
	dnode *p,*s;
	p = head->next;
	while (p != NULL) {
		if (p->data == content) {			
			break;
		}
		p = p->next;
	}
	if (p == NULL) {
		printf("没有这个数");
		return head;
	}
	s = (dnode *)malloc(sizeof(dnode));
	s->data = insertCont;
	s->next = p->next;
	if (p->next != NULL) {
		p->next->prior = s;
	}	
	p->next = s;
	s->prior = p;
	return head;
}

dnode *del(dnode* head, int content) {
	dnode *p, *q, *s;
	p = head->next;
	while (p != NULL) {
		if (p->data == content) {
			break;
		}
		p = p->next;
	}
	if (p == NULL) {
		printf("没有这个数");
		return head;
	}
	q = p->prior;
	s = p->next;
	if (s != NULL) {
		s->prior = q;
	}	
	q->next = s;
	free(p);
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
	head = insert(head, 8, 107);
	head = del(head, 5);
	printList(head);
}


