#include<iostream>

#include "PrioQueue.hpp"

using namespace std;

int main(void) {
	PrioQueue<int> q(5);
	q.push(4,3);
	q.push(5,3);
	q.push(6,0);
	q.push(8,3);
	q.dump();
	return 0;
}
