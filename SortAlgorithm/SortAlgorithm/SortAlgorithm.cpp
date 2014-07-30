// SortAlgorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

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

void Merge(int a[], int start, int half, int end) {
	int n1 = half - start + 1;
	int n2 = end - half;
	int *L, *R;

	L = (int *)malloc(sizeof(int)*n1);
	R = (int *)malloc(sizeof(int)*n2);

	for (int i = 0; i < n1; i++) {
		L[i] = a[start + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = a[half + 1 + i];
	}

	int i = 0;
	int j = 0;
	for (int p = start; p <= end; p++) {
		if (i<n1 && (L[i]>=R[j] || j>=n2)) {
			a[p] = L[i];
			i++;
		}
		if (j<n2 && (L[i]<R[j] || i>=n1)) {
			a[p] = R[j];
			j++;
		}
	}
	free(L);
	free(R);
}

void MergeSort(int a[], int start, int end) {		//�����������������й鲢�����ϳ�һ����������
	if (start < end) {
		int half = (start + end) / 2;

		MergeSort(a, start, half);
		MergeSort(a, half+1, end);
		Merge(a, start, half, end);
	}
}

int Partition(int a[], int start, int end) {
	int separate, nonius, pivot;
	pivot = start;
	separate = start;

	for (nonius = start + 1; nonius <= end; nonius++) {
		if (a[nonius] >= a[pivot]) {
			separate++;
			int temp = a[separate];
			a[separate] = a[nonius];
			a[nonius] = temp;
		}
	}
	int temp = a[pivot];
	a[pivot] = a[separate];
	a[separate] = temp;

	return separate;
}

void QuickSort(int a[], int start, int end) {		//ѡ�����п�ͷΪ��׼�����б��Ϊ��ߴ��ڻ�׼ֵ��������ұ�С�ڻ�׼ֵ�����䣬Ȼ��ݹ�
	int pivot;

	if (start < end) {
		pivot = Partition(a, start, end);
		QuickSort(a, start, pivot-1);
		QuickSort(a, pivot+1, end);
	}
}

void main() {
	int a[5];

	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &a[i]);
	}

	//BubbleSort(a, 5);
	//InsertionSort(a, 5);
	//MergeSort(a, 0, 4);
	QuickSort(a, 0, 4);

	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
}

