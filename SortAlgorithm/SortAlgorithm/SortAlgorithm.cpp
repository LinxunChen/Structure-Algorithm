// SortAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

/*从小到大进行排序*/

void BubbleSort(int a[], int len) {
	for (int i = 1; i < len; i++) {			//从左往右
		for (int j = len-1; j >=i ; j--) {	//从右往左
			if (a[j] < a[j - 1]) {
				int temp = 0;
				temp = a[j];
				a[j] = a[j - 1];
				a[j - i] = temp;
			}
		}
	}	
}

void InsertionSort(int a[], int len) {		//和抓扑克牌过程类似，从左往右每次选一张牌，把此牌有序插入左方有序数列(左边的序列都是已排好序的)
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

