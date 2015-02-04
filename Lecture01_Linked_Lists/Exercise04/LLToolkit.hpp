#pragma once
#include<iostream>
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
		free(tempPtr);
	}

	static void insert(Node<T>* prevPtr, T info) {
		prevPtr->next = new Node<T>(info, prevPtr->next);
	}

	static void remove(Node<T>* prevPtr) {
		Node<T>* tempPtr = prevPtr->next;
		prevPtr->next = prevPtr->next->next;
		free(tempPtr);
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

	static clear(Node<T>*& headPtr) {
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

};
