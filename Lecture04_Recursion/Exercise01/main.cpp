#include <iostream>

void triangle(unsigned int m, unsigned int n) {
	std::cout << std::string(m, '*') << "\n";
	if (m < n) {
		triangle(m+1,n);
	}
	std::cout << std::string(m, '*') << "\n";
}

int main(int narg, char *argv[]) {
	if (narg == 3) {
		triangle(atoi(argv[1]),atoi(argv[2]));
	} else {
		triangle(5,8);
	}
}
