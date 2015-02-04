#include<iostream>

#include "node.hpp"
#include "LLToolkit.hpp"

using namespace std;

int main(void) {

	Node<int>* head = new Node<int>(6);

	LLToolkit<int>::headInsert(head, 5);
	
	LLToolkit<int>::print(head);
}
