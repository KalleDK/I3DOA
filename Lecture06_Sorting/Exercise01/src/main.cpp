#include <iostream>
#include <stdlib.h>

#define ARRAY_SIZE 20

void insertionsort(int* arr, int size) {
	int mover;
	for (int i = 1; i < size; ++i) {
		int j = i;
		while(j > 0 && arr[j-1] > arr[j]) {
			mover = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = mover;
			--j;
		}
	}
}

int main(void) {
	srand (time(NULL));
	int arr[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	insertionsort(arr, ARRAY_SIZE);
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	return 0;
}
