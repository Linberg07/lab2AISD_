#include<iostream>
#include "Header.h"
using namespace std;



int Binary_Search(int* a,int size, int value) {
	if (size < 0) throw "Uncorrect size";
	if (isSorted(a, size) == 0) throw "Array is not Sorted!";
	int right = size - 1;
	int left = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == value) return  mid;
		else if (a[mid] > value) right = mid - 1;
		else if (a[mid] < value) left = mid + 1;
	}
	throw "Not Find Value";
}

void QuickSort(int* a, int size) {
	if (size < 0) throw "Uncorrect Size!";
	int i = 0;
	int j = size - 1;
	int mid = a[size / 2];
	do {
		while (a[i] < mid) {
			i++;
		}
		while (a[j] > mid) {
			j--;
		}
		if (i <= j) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) {
		QuickSort(a, j + 1);
	}
	if (i < size) {
		QuickSort(&a[i], size - i);
	}
}

void InsertionSort(int* a,int size) {
	int temp, itemp;
	if (size < 0) throw "Uncorrect Size!";
	for (int i = 1; i < size; i++) {
		temp = a[i];
		itemp = i - 1;
		while (itemp >= 0 && a[itemp] > temp) {
			a[itemp + 1] = a[itemp];
			a[itemp] = temp;
			itemp--;
		}
	}
}

bool isSorted(int* a, int size) {
	while (size > 1) {
		if (a[size - 1] < a[size - 2]) return false;
		size--;
	}
	return true;
}

void shuffle(int* a, int size) {
	for (int i = 0; i < size; i++) {
		int swap = a[i];
		int index = (rand() % size);
		a[i] = a[index];
		a[index] = swap;
	}
}

void BogoSort(int* a, int size) {
	while (!isSorted(a, size)) {
		shuffle(a, size);
	}
}

void CountingSort(char* a, char* b, int const size) {
	if (size < 0) throw "Uncorrect Size!";
	int c[26];

	for (int i = 0; i < 26; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		c[int(a[i]) - 97]++;
	}
	int t = 0;
	for (int i = 0; i < 26; i++) {
		while (c[i] > 0) {
			b[t] = char(i + 97);
			t++;
			c[i]--;
		}
	}
}
