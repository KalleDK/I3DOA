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
		if (sourcePtr == NULL) {
			return NULL;
		} else {
			return new Node<T>(sourcePtr->info, copy(sourcePtr->next));
		}
	}


	static void clear(Node<T>*& headPtr) {
		if (headPtr != NULL) {
			headRemove(headPtr);
			clear(headPtr);

		}
	}

	static void print(Node<T>* headPtr) {
		if (headPtr == NULL) {
			std::cout << "/\n";

		} else {
			std::cout << headPtr->info << " - ";
			print(headPtr->next);
		}
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
		if (n == 0) {
			return NULL;
		} else {
			return new Node<T>(values[0], build(values+1, n-1));
		}
	}

	static void join(Node<T>*& head1, Node<T>* head2) {
		Node<T>* runnerPtr = head1;
		if (head1 == NULL) {
			head1 = head2;
		} else {
			if (head1->next == NULL) {
				head1->next = head2;
			} else {
				join(head1->next, head2);
			}
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
