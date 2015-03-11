#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define ARRAY_SIZE 2000

template<class T>
void insertionsort(T* arr, const int size) {
	int mover;
	for (int i = 1; i < size; ++i) {
		int j = i;
		while(j > 0 && arr[j-1] > arr[j]) {
			swap(arr[j-1], arr[j]);
			--j;
		}
	}
}

template<class T>
void quicksort(T data[], int first, int last, int bc) {
	if (first + bc > last) {
		insertionsort<T>(&data[first], last-first+1);
	} else {
		// Set lower and upper
		int lower = first + 1, upper = last;
		// Swip pivot to front
		swap(data[first], data[(first + last) / 2]);
		T bound = data[first];
		while (lower <= upper) {
			while (data[lower] < bound)
				++lower;
			while (bound < data[upper])
				--upper;
			if (lower < upper)
				swap(data[lower++], data[upper--]);
			else lower++;
		}
		//Move pivot to center
		swap(data[upper], data[first]);
		if (first < upper - 1)
			quicksort(data, first, upper - 1, bc);
		if (upper + 1 < last)
			quicksort(data, upper + 1, last, bc);
	}
}

template<class T>
void quicksort(T data[], const int n, const int bc) {
	int i, max;
	if (n < 2)
		return;
	for (i = 1, max = 0; i < n; i++)	// find the largest
		if (data[max] < data[i])	// element and put it
			max = i;		// at the end of data[];
	swap(data[n - 1], data[max]);		// largest el is now in its
	quicksort(data, 0, n - 2, bc);		// final position;
}


int main(void) {
	srand (time(NULL));
	int arr[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		arr[i] = rand() % ARRAY_SIZE;
	}
	//insertionsort(arr, ARRAY_SIZE);
	quicksort<int>(arr, ARRAY_SIZE, 20);
	for (int i  = 1; i < ARRAY_SIZE; ++i) {
		if (arr[i-1] > arr[i]) {cout << "Error\n";}
	}
	return 0;
}
