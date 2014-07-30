// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char data;
	struct Node *left, *right;
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
		printf("%c", head->data);
		PreOrderTraverse(head->left);
		PreOrderTraverse(head->right);
	}
}

void main(){
	BiNode tree = (BiNode)malloc(sizeof(Node));
	CreatBiTree(&tree);
	PreOrderTraverse(tree);
}