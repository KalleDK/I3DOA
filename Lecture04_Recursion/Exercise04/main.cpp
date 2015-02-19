#include <iostream>

void print_stars(int n, int i) {
	if (n == 0) {
		return;
	}
	else {
		print_stars(n/2, i);
		std::cout << std::string(i, ' ') << std::string(n, '*') << "\n";
		print_stars(n/2, i+n/2);
	}
}

int main(int narg, char *argv[]) {
	print_stars(8, 2);
}
