#include<iostream>
#include "Header.h"
#include <ctime>
#define ArraySize 100000

using namespace std;

void elapsedTime(void (*funcName)(int*, int), int* arr, int array_size)
{
	int i, j;
	int t1, t2;
	double seconds, res = 0;
	srand(time(0));
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < array_size; j++)
		{
			arr[j] = rand() % ArraySize;
		}
		t1 = clock();
		funcName(arr, array_size);
		t2 = clock() - t1;
		seconds = double(t2);
		res += seconds * 1000 / CLOCKS_PER_SEC;
		cout << seconds * 1000 / CLOCKS_PER_SEC << " ";
	}
	cout << endl;
	res /= 10;
	cout << res << endl;
}

int main()
{
	int mass[ArraySize];
	void (*kind[2])(int*, int);
	kind[0] = QuickSort;
	kind[1] = InsertionSort;
	elapsedTime(kind[0], mass, 10);
	elapsedTime(kind[0], mass, 100);
	elapsedTime(kind[0], mass, 1000);
	elapsedTime(kind[0], mass, 10000);
	elapsedTime(kind[0], mass, 100000);
	elapsedTime(kind[1], mass, 10);
	elapsedTime(kind[1], mass, 100);
	elapsedTime(kind[1], mass, 1000);
	elapsedTime(kind[1], mass, 10000);
	elapsedTime(kind[1], mass, 100000);
	return 0;
}