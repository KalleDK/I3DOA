#pragma once
#include <iostream>
#include "node.hpp"


template <typename T>
class LLToolkit
{
public:
	static void headInsert(Node<T>*& headPtr, T info) {
		headPtr = new Node<T>(info, headPtr);
	}

	static void headRemove(Node<T>*& headPtr) {
		Node<T>* tempPtr = headPtr;
		headPtr = headPtr->next;
		delete(tempPtr);
	}

	static void insert(Node<T>* prevPtr, T info) {
		prevPtr->next = new Node<T>(info, prevPtr->next);
	}

	static void remove(Node<T>* prevPtr) {
		Node<T>* tempPtr = prevPtr->next;
		prevPtr->next = prevPtr->next->next;
		delete(tempPtr);
	}

	static Node<T>* copy(Node<T>* sourcePtr) {
		Node<T>* headPtr = new Node<T>(sourcePtr->info);
		Node<T>* lastPtr = headPtr;
	
		for (Node<T>* cursor = sourcePtr->next; cursor != NULL; cursor = cursor->next) {
			lastPtr->next = new Node<T>(cursor->info);
			lastPtr = lastPtr->next;
		}
		return headPtr;
	}

	static void clear(Node<T>*& headPtr) {
		while (headPtr != NULL) {
			headRemove(headPtr);
		}
	}

	static void print(Node<T>* headPtr) {
		while (headPtr != NULL) {
			std::cout << headPtr->info << " - ";
			headPtr = headPtr->next;
		}
		std::cout << "/\n";
	}

	static void reverse(Node<T>*& headPtr) {
		Node<T>* runnerPtr = headPtr->next;
		Node<T>* moverPtr = NULL;
		headPtr->next = NULL;

		while (runnerPtr != NULL) {
			moverPtr = runnerPtr;
			runnerPtr = runnerPtr->next;
			moverPtr->next = headPtr;
			headPtr = moverPtr;
		}
	}

	static Node<T>* split(Node<T>* splitPtr) {
		Node<T>* headPtr = splitPtr->next;
		splitPtr->next = NULL;
		return headPtr;
	}

	static Node<T>* build(T * values, size_t n) {
		Node<T>* headPtr = NULL;
		if (n > 0) {
			for (int i = n-1; 0 <= i ; --i) {
				headInsert(headPtr, values[i]);
			}
		}
		return headPtr;
	}

	static void join(Node<T>*& head1, Node<T>* head2) {
		Node<T>* runnerPtr = head1;
		if (head1 == NULL) {
			head1 = head2;
		} else {
			while (runnerPtr->next != NULL) {
				runnerPtr = runnerPtr->next;
			}
			runnerPtr->next = head2;
		}
	}

	static void rotateLeft(Node<T>*& head) {
		if (head != NULL && head->next != NULL) {
			Node<T>* runnerPtr = head;
			while(runnerPtr->next != NULL) {
				runnerPtr = runnerPtr->next;
			}
			runnerPtr->next = head;
			head = head->next;
			runnerPtr->next->next = NULL;
		}
	}

	static void rotateRight(Node<T>*& head) {
		if (head != NULL && head->next != NULL) {
			Node<T>* runnerPtr = head;
			while(runnerPtr->next->next != NULL) {
				runnerPtr = runnerPtr->next;
			}
			runnerPtr->next->next = head;
			head = runnerPtr->next;
			runnerPtr->next = NULL;
		}
	}

};
