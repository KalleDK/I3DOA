#include<iostream>

#include "LLToolkit.hpp"

using namespace std;

int list_length(Node<int>* head) {
	if (head->next == NULL) {
		return 1;
	}
	else {
		return 1 + list_length(head->next);
	}
}

int main(void) {
	int val[7] = { 4, 5, 6, 6, 7, 8, 9};
	Node<int>* head = LLToolkit<int>::build(val, 7);
	LLToolkit<int>::print(head);
	cout << list_length(head) << endl;
}
