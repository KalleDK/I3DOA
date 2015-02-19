#include <iostream>

using namespace std;

void hanoi(int from, int via , int to, int size) {
	if ( size == 0 ) {
		return;
	}
	else {
		hanoi(from, to, via, size-1);
		cout << "Moving disk " << size << "# from " << from << " to " << to << "\n";
		hanoi(via, from, to, size-1);
	}
}

int main(int narg, char *argv[]) {
	hanoi(1,2,3,4);
}
