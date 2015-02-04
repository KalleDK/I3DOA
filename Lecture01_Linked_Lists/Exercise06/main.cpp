#include<iostream>

#include "LLToolkit.hpp"

using namespace std;

int main(void) {
	int val[7] = { 4, 5, 6, 6, 7, 8, 9};
	Node* head = LLToolkit::build(val, 7);
	LLToolkit::headInsert(head, 3);
	LLToolkit::headInsert(head, 5);
	LLToolkit::headInsert(head, 6);
	LLToolkit::headInsert(head, 5);
	LLToolkit::headInsert(head, 8);
	Node* flaf = LLToolkit::copy(head);
	LLToolkit::print(flaf);
	LLToolkit::headRemove(head);
	LLToolkit::print(flaf);
	LLToolkit::reverse(flaf);
	LLToolkit::print(flaf);
	Node* half = LLToolkit::split(flaf->next->next);
	LLToolkit::print(flaf);
	LLToolkit::print(half);
	LLToolkit::join(flaf,half);
	LLToolkit::print(flaf);
	LLToolkit::rotateLeft(flaf);
	LLToolkit::print(flaf);
	LLToolkit::rotateLeft(flaf);
	LLToolkit::print(flaf);
	LLToolkit::rotateRight(flaf);
	LLToolkit::print(flaf);
	LLToolkit::rotateRight(flaf);
	LLToolkit::print(flaf);
	LLToolkit::clear(flaf);
	LLToolkit::print(flaf);
	LLToolkit::headInsert(flaf, 3);
	LLToolkit::headInsert(flaf, 5);
	LLToolkit::print(flaf);
	LLToolkit::rotateRight(flaf);
	LLToolkit::print(flaf);
	LLToolkit::rotateRight(flaf);
	LLToolkit::print(flaf);
	LLToolkit::rotateLeft(flaf);
	LLToolkit::print(flaf);
	LLToolkit::rotateLeft(flaf);
	LLToolkit::print(flaf);
}
