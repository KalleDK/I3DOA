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

};
