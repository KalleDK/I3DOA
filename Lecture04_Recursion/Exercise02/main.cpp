#include <iostream>

bool recursive_search(unsigned int* ar , unsigned int n, unsigned int x) {
	if (ar[n] == x) {
		return true;
	}
	else if (n == 0) {
		return false;
	}
	else {
		return recursive_search(ar, n-1, x);
	}
}

int main(int narg, char *argv[]) {
	unsigned int tal[6] = {1,2,3,4,5,6};
	std::cout << recursive_search(tal, 5, 4) << "\n";	
	std::cout << recursive_search(tal, 5, 8) << "\n";	
	std::cout << recursive_search(tal, 3, 5) << "\n";	
	std::cout << recursive_search(tal, 3, 4) << "\n";	
}
