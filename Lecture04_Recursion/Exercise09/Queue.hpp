#pragma once
#include <iostream>
#include <exception>
#include "LLToolkit.hpp"

class QueueExp: public std::exception
{
	virtual const char* what() const throw()
	{
		return "Queue is empty";
	}
} QueueEmpty;

template <typename T>
class Queue
{
public:
	Node<T>* head;
	Node<T>* tail;

	Queue() {
		this->head = NULL;
		this->tail = NULL;
	}
	
	virtual ~Queue() {
		LLToolkit<T>::clear(this->head);
	}

	bool isEmpty() {
		return (this->head == NULL);
	}

	//push
	void push(T data) {
		if (this->head == NULL) {
			LLToolkit<T>::headInsert(this->tail, data);
			this->head = this->tail;
		} else {
			LLToolkit<T>::insert(this->tail, data);
			this->tail = this->tail->next;
		}
	}

	//pop
	void pop(void) {
		if (this->head != NULL) {
			if (this->head->next == NULL) {
				this->tail = NULL;
			}
			LLToolkit<T>::headRemove(head);
		} else {
			throw QueueEmpty;
		}
	}

	//front
	T front(void) {
		if (this->head == NULL) {
			throw QueueEmpty;
		}
		return this->head->info;
	}
	
	
	//dump
	void dump(void) {
		LLToolkit<T>::print(this->head);
	}

};
