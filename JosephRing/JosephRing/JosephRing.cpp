// JosephRing.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct jnode {
	int data;
	struct jnode *next;
}jnode;

jnode *creatCirList(int n) {
	jnode *head, *p, *s;
	head = (jnode *)malloc(sizeof(jnode));
	head->data = 1;
	p = head;
	for (int i = 2; i <= n; i++) {		
		s = (jnode *)malloc(sizeof(jnode));
		p->next = s;
		p = s;
	}
	p->next = head;
	return head;
}

jnode *insert(jnode *head, int content) {
	jnode *p, *s;
	p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	s = (jnode *)malloc(sizeof(jnode));
	s->data = content;
	p->next = s;
	s->next = NULL;
	return head;
}

void JosephRing(int n, int k, int m) {
	jnode *p, *s;
	int count = 1;
	jnode *headRing = creatCirList(n);
	jnode *headList = (jnode *)malloc(sizeof(jnode));
	p = headRing;
	while (p->data != k) {
		p = p->next;
	}	
	s = p;

	while (p != NULL) {
		while (count != m) {
			s = p;
			p = p->next;
			count++;
		}
		headList = insert(headList, p->data);
		s->next = p->next;
		free(p);
		p = s->next;
		count = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		printf("%d,", headList->data);
	}
}

void main() {
	JosephRing(12, 3, 7);
}