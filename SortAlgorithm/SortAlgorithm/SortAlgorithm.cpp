// SortAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

/*��С�����������*/

void BubbleSort(int a[], int len) {
	for (int i = 1; i < len; i++) {			//��������
		for (int j = len-1; j >=i ; j--) {	//��������
			if (a[j] < a[j - 1]) {
				int temp = 0;
				temp = a[j];
				a[j] = a[j - 1];
				a[j - i] = temp;
			}
		}
	}	
}

void InsertionSort(int a[], int len) {		//��ץ�˿��ƹ������ƣ���������ÿ��ѡһ���ƣ��Ѵ��������������������(��ߵ����ж������ź����)
	for (int i = 1; i < len; i++) {
		int key = a[i];
		int j = i - 1;

		while (a[j] < key && j >= 0) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void main() {
	int a[5];

	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &a[i]);
	}

	//BubbleSort(a, 5);
	InsertionSort(a, 5);

	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
}

