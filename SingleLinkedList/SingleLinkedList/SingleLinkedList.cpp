// SingleLinkedList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct Student {
	int data;
	struct Student *next;
}node;

node *creat() {
	node *head, *p, *s;
	head = (node *)malloc(sizeof(node));
	int i;
	p = head;
	for (i = 0; i < 7; i++) {
		s = (node *)malloc(sizeof(node));
		s->data = i;
		p->next = s;
		p = s;
	}
	s->next = NULL;
	return head;
}

node *del(node *head, int content) {
	node *p, *s;
	p = head->next;
	s = p;
	while (p != NULL) {
		if (p->data == content) {
			break;
		}
		s = p;
		p = p->next;
	}
	if (p == NULL) {
		printf("没有该内容");
		return head;
	}
	s->next = p->next;
	free(p);
	return head;
}

node *insert(node *head, int content, int insertCont) {
	node *p, *s;
	p = head->next;
	while (p != NULL) {
		if (p->data == content) {
			break;
		}
		p = p->next;
	}
	s = (node *)malloc(sizeof(node));
	s->data = insertCont;
	s->next = p->next;
	p->next = s;
	return head;
}

node *sort(node *head) {
	node *p, *s, *flag;
	int temp;
	p = head->next;
	flag = NULL;
	while (p->next != flag) {
		s = p;
		while (s->next != flag) {
			if (s->data < s->next->data) {
				temp = s->next->data;
				s->next->data = s->data;
				s->data = temp;
			}
			s = s->next;
		}
		flag = s;
	}
	return head;
}

node *inverse(node *head) {
	node *p, *s, *temp;
	p = head->next;
	temp = p->next;
	s = p->next;
	while (temp != NULL) {
		temp = s->next;
		s->next = p;
		p = s;
		s = temp;
	}
	head->next->next = NULL;
	head = p;
	return head;
}

void printList(node *head) {
	node *p;
	p = head->next;
	do{
		printf("%d ", p->data);
		p = p->next;
	} while (p != NULL);
}

void main() {
	node *head = creat();
	//head = del(head, 4);
	head = insert(head, 5, 105);
	head = sort(head);
	head = inverse(head);
	printList(head);
}

