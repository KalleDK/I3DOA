#include <iostream>
#include "MinHeap.h"

using namespace std;

int main(void)
{

	MinHeap<int> h;
	h.insert(1);
	h.insert(4);
	h.insert(7);
	h.insert(12);
	h.insert(31);
	h.insert(32);
	h.insert(54);
	h.insert(17);
	h.insert(79);
	h.insert(44);
	h.insert(59);
	h.insert(2);
	
	if (h.isHeap())
		std::cout << "Is Heap " << std::endl;
	else
		std::cout << "Is NOT Heap " << std::endl;

	h.print();
	return 0;
}
