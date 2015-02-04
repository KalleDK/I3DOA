#include<iostream>

#include "LLToolkit.hpp"

using namespace std;

int main(void) {

	Node* head = NULL;
	LLToolkit::headInsert(head, 3);
	LLToolkit::headInsert(head, 5);
	Node* flaf = LLToolkit::copy(head);
	LLToolkit::headRemove(head);
	cout << flaf->info << endl;
	cout << flaf->next->info << endl;

}
