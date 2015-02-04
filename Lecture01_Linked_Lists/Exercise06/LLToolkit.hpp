#pragma once
#include "node.hpp"

class LLToolkit
{
public:
	static void headInsert(Node*& headPtr, int info);
	static void headRemove(Node*& headPtr);
	static void insert(Node* prevPtr, int info);
	static void remove(Node* prevPtr);
	static Node* copy(Node* sourcePtr);
	static void clear(Node*& headPtr);
	static void print(Node* headPtr);
	static void reverse(Node*& headPtr);
	static Node* split(Node* splitPtr);
	static Node* build(int* values, size_t n);
	static void join(Node* head1, Node* head2);
	static void rotateLeft(Node*& head);
	static void rotateRight(Node*& head);

};
