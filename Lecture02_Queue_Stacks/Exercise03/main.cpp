#include<iostream>

#include "LLToolkit.hpp"
#include "Queue.hpp"

using namespace std;

int main(void) {
	Queue<int> q;
	std::cout << q.isEmpty() << std::endl;

	q.push(5);
	q.push(3);
	q.push(4);
	q.dump();
	q.pop();
	q.pop();
	q.pop();
	try
	{
		q.pop();
	}
	catch (exception& e)
	{
		cout << e.what() << '\n';
	}
	q.push(4);
	q.dump();
	return 0;
}
