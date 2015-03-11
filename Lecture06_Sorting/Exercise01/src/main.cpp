#include <iostream>
#include <stdlib.h>

#define ARRAY_SIZE 20

int main(void) {
	srand (time(NULL));
	int arr[ARRAY_SIZE];
	int mover;
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	for (int i = 1; i < ARRAY_SIZE; ++i) {
		int j = i;
		while(j > 0 && arr[j-1] > arr[j]) {
			mover = arr[j-1];
			arr[j-1] = arr[j];
			arr[j] = mover;
			--j;
		}
		
	}
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	return 0;
}
