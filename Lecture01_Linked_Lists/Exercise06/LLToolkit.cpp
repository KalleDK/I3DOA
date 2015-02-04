#include <iostream>
#include "LLToolkit.hpp"

using namespace std;


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

void LLToolkit::clear(Node*& headPtr) {
	while (headPtr != NULL) {
		headRemove(headPtr);
	}
}

void LLToolkit::print(Node* headPtr) {
	while (headPtr != NULL) {
		cout << headPtr->info << " - ";
		headPtr = headPtr->next;
	}
	cout << "/\n";
}

void LLToolkit::reverse(Node*& headPtr) {
	Node* runnerPtr = headPtr->next;
	Node* moverPtr = NULL;
	headPtr->next = NULL;

	while (runnerPtr != NULL) {
		moverPtr = runnerPtr;
		runnerPtr = runnerPtr->next;
		moverPtr->next = headPtr;
		headPtr = moverPtr;
	}
}

Node* LLToolkit::split(Node* splitPtr) {
	Node* headPtr = splitPtr->next;
	splitPtr->next = NULL;
	return headPtr;
}

Node* LLToolkit::build(int* values, size_t n) {
	Node* headPtr = NULL;
	for (int i = 0; i < n; i++) {
		headInsert(headPtr, values[i]);
	}
	return headPtr;
}

void LLToolkit::join(Node* head1, Node* head2) {
	Node* runnerPtr = head1;
	while (runnerPtr->next != NULL) {
		runnerPtr = runnerPtr->next;
	}
	runnerPtr->next = head2;
}

void LLToolkit::rotateLeft(Node*& head) {
	Node* runnerPtr = head;
	while(runnerPtr->next != NULL) {
		runnerPtr = runnerPtr->next;
	}
	runnerPtr->next = head;
	head = head->next;
	runnerPtr->next->next = NULL;
}

void LLToolkit::rotateRight(Node*& head) {
	Node* runnerPtr = head;
	while(runnerPtr->next->next != NULL) {
		runnerPtr = runnerPtr->next;
	}
	runnerPtr->next->next = head;
	head = runnerPtr->next;
	runnerPtr->next = NULL;
}
