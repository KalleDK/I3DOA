#include "binsearch.hpp"

void printar(int* base, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << base[i] << "- ";
	}
	std::cout << "\\\n";
}

bool binsearch(int* base, int size, int x) {
	int i = size / 2;

	#ifdef DEBUG
	std::cout << "\n------------------\n";
	printar(base, size);
	#endif

	if (base[i] == x) {
		#ifdef DEBUG
		std::cout << base[i] << " == " << x << "\n";
		#endif
		return true;
	} else if (i == 0) {
		#ifdef DEBUG
		std::cout << "Not here\n";
		#endif
		return false;
	} else  if (x < base[i]) {
		#ifdef DEBUG
		std::cout << base[i] << " > " << x << "\n";
		#endif
		return binsearch(base, i, x);
	} else {
		#ifdef DEBUG
		std::cout << base[i] << " < " << x << "\n";
		#endif
		return binsearch(base+i+1, i, x);
	}
}
