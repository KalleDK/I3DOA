#include "LLToolkit.hpp"


void LLToolkit::headInsert(Node*& headPtr, int info) {
	headPtr = new Node(info, headPtr);
}

void LLToolkit::headRemove(Node*& headPtr) {
	Node* tempPtr = headPtr;
	headPtr = headPtr->next;
	free(tempPtr);
}

void LLToolkit::insert(Node* prevPtr, int info) {
	prevPtr->next = new Node(info, prevPtr->next);
}

void LLToolkit::remove(Node* prevPtr) {
	Node* tempPtr = prevPtr->next;
	prevPtr->next = prevPtr->next->next;
	free(tempPtr);
}

Node* LLToolkit::copy(Node* sourcePtr) {
	Node* headPtr = new Node(sourcePtr->info);
	Node* lastPtr = headPtr;

	for (Node* cursor = sourcePtr->next; cursor != NULL; cursor = cursor->next) {
		lastPtr->next = new Node(cursor->info);
		lastPtr = lastPtr->next;
	}
	return headPtr;
}

