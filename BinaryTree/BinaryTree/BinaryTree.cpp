// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char data;
	struct Node *left, *right, *pre, *next;
}Node, *BiNode;

void CreatBiTree(BiNode *head) {
	char ch;
	scanf_s("%c", &ch);
	
	if (ch == '#') {
		*head = NULL;
	}
	else{
		*head = (BiNode)malloc(sizeof(Node));
		(*head)->data = ch;
		CreatBiTree(&(*head)->left);
		CreatBiTree(&(*head)->right);
	}
}

void PreOrderTraverse(BiNode head) {
	if (head == NULL) {
		return;
	}
	else{
		printf("%d", head->data);
		PreOrderTraverse(head->left);
		PreOrderTraverse(head->right);
	}
}

void TransRecursively(BiNode pNode, BiNode *previous, BiNode *current){
	if (pNode == NULL) {
		return;
	}
	TransRecursively(pNode->left, previous, current);

	(*current) = pNode;
	(*current)->pre = (*previous);
	if ((*previous) != NULL) {
		(*previous)->next = (*current);
	}
	*previous = *current;

	TransRecursively(pNode->right, previous, current);
	if ((*current)->left == NULL && (*current)->right == NULL) {
		(*current)->next = NULL; 
	}
}

void TransToLinkedList(BiNode pNode) {
	BiNode previous = NULL;
	BiNode current = NULL;

	TransRecursively(pNode, &previous, &current);
}

BiNode Constrcut(int *pre, int *in, int len) {
	if (pre == NULL || in == NULL || len <= 0) {
		return NULL;
	}

	int lenLeft = 0;
	int *p = in;

	while (*pre != *p && lenLeft <= len) {
		p++;
		lenLeft++;
		if (lenLeft > len) {
			return NULL;
		}
	}

	int lenRight = len - lenLeft - 1;
	BiNode root = (BiNode)malloc(sizeof(Node));
	root->data = *pre;
	root->left = Constrcut(pre + 1, in, lenLeft);
	root->right = Constrcut(pre + lenLeft + 1, in + lenLeft + 1, lenRight);

	return root;
}

void main(){
	/*
	BiNode tree = (BiNode)malloc(sizeof(Node));
	CreatBiTree(&tree);
	PreOrderTraverse(tree);
	TransToLinkedList(tree);
	printf("\n");
	while (tree->pre != NULL) {
		tree = tree->pre;
	}
	while(tree) {
		printf("%c", tree->data);
		tree = tree->next;
	}*/

	int a[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int b[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BiNode p = Constrcut(a, b, 8);
	PreOrderTraverse(p);
}