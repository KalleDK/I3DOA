#include<iostream>

#include "LLToolkit.hpp"

using namespace std;

int main(void) {
	int val[7] = { 4, 5, 6, 6, 7, 8, 9};
	Node<int>* head = LLToolkit<int>::build(val, 7);
	LLToolkit<int>::print(head);
	LLToolkit<int>::headInsert(head, 3);
	LLToolkit<int>::headInsert(head, 5);
	LLToolkit<int>::headInsert(head, 6);
	LLToolkit<int>::headInsert(head, 5);
	LLToolkit<int>::headInsert(head, 8);
	std::cout << "Copy\n";
	Node<int>* flaf = LLToolkit<int>::copy(head);
	LLToolkit<int>::print(flaf);
	LLToolkit<int>::print(head);
	LLToolkit<int>::headRemove(head);
	LLToolkit<int>::print(flaf);
	LLToolkit<int>::print(head);
	LLToolkit<int>::reverse(flaf);
	LLToolkit<int>::print(flaf);
	LLToolkit<int>::print(head);
	Node<int>* half = LLToolkit<int>::split(flaf->next->next);
	std::cout << "Join\n";
	LLToolkit<int>::print(flaf);
	LLToolkit<int>::print(half);
	LLToolkit<int>::join(flaf,half);
	LLToolkit<int>::print(flaf);
	LLToolkit<int>::rotateLeft(flaf);
	LLToolkit<int>::print(flaf);
	LLToolkit<int>::rotateLeft(flaf);
	LLToolkit<int>::print(flaf);
	LLToolkit<int>::rotateRight(flaf);
	LLToolkit<int>::print(flaf);
	LLToolkit<int>::rotateRight(flaf);
	LLToolkit<int>::print(flaf);
	std::cout << "Clearing\n";
	LLToolkit<int>::clear(flaf);
	LLToolkit<int>::print(flaf);
	LLToolkit<int>::headInsert(flaf, 3);
	LLToolkit<int>::headInsert(flaf, 5);
	LLToolkit<int>::print(flaf);
	LLToolkit<int>::rotateRight(flaf);
	LLToolkit<int>::print(flaf);
	LLToolkit<int>::rotateRight(flaf);
	LLToolkit<int>::print(flaf);
	LLToolkit<int>::rotateLeft(flaf);
	LLToolkit<int>::print(flaf);
	LLToolkit<int>::rotateLeft(flaf);
	LLToolkit<int>::print(flaf);
	Node<int>* g = new Node<int>(6);
	LLToolkit<int>::print(g);
	LLToolkit<int>::rotateLeft(g);
	LLToolkit<int>::print(g);
	
}
