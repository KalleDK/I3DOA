#include <iostream>
#include "binsearch.hpp"

#ifndef A_SIZE
#define A_SIZE 10
#endif


#ifndef X
#define X 10
#endif

int main(int narg, char *argv[]) {
	int base[A_SIZE];
	int base_max = 0;
	for (int i = 0; i < A_SIZE; ++i) {
		base_max += rand() % 5;
		base[i] = base_max;
	}
	printar(base, A_SIZE);
	binsearch(base, A_SIZE, X);
	std::cout << start << "\t" << end << "\t" << end-start << "\n";
	return 0;
}
