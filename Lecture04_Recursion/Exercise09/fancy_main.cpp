#include <iostream>

#include "LLToolkit.hpp"
#include "node.hpp"

using namespace std;

void hanoi(int from, int via , int to, int size, Node<int>** q) {
	if ( size == 0 ) {
		return;
	}
	else {
		hanoi(from, to, via, size-1, q);
		cout << "Moving disk " << size << "# from " << from << " to " << to << "\n";
		LLToolkit<int>::headRemove(q[from-1]);
		LLToolkit<int>::headInsert(q[to-1], size);
		LLToolkit<int>::revPrint(q[0]);
		cout << "\n";
		LLToolkit<int>::revPrint(q[1]);
		cout << "\n";
		LLToolkit<int>::revPrint(q[2]);
		cout << "\n";
		hanoi(via, from, to, size-1, q);
	}
}

int main(int narg, char *argv[]) {
	Node<int>* q[3];
	int size = 4;
	q[1] = NULL;
	q[2] = NULL;
	for (int i = size; i > 0 ; --i) {
		LLToolkit<int>::headInsert(q[0],i);
	}
	LLToolkit<int>::revPrint(q[0]);
		cout << "\n";
	LLToolkit<int>::revPrint(q[1]);
		cout << "\n";
	LLToolkit<int>::revPrint(q[2]);
		cout << "\n";
	hanoi(1,2,3,4,q);
}
