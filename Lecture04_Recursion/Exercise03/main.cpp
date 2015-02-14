#include <iostream>

void print_booklet(int startpage, int endpage) {
	std::cout << "Sheet " << (startpage + 1) / 2 << " contains pages " \
	<< startpage << ", " << startpage+1 << ", " \
	<< endpage -1  << ", " << endpage << ".\n";
	if (startpage >= (endpage - 3)) {
		return;
	} else {
		print_booklet(startpage + 2, endpage - 2);
	}
}

int main(int narg, char *argv[]) {
	print_booklet(1,16);
}
