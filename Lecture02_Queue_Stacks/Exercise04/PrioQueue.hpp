#pragma once
#include <iostream>
#include <exception>
#include <vector>
#include "Queue.hpp"

template <typename T>
class PrioQueue
{
public:
	Queue<T>** queuelist;
	size_t size;
	
	PrioQueue(size_t size) {
		this->size = size;
		queuelist = new Queue<T>*[size];
		for (size_t i = 0; i < this->size; ++i) {
			queuelist[i] = new Queue<T>;
		}
	}

	virtual ~PrioQueue() {
		for (size_t i = 0; i < this->size; ++i) {
			delete(queuelist[i]);
		}
		delete[] queuelist;
	}

	//push
	void push(T data, size_t prio) {
		queuelist[prio]->push(data);
	}

	//pop
	void pop() {
		for (size_t i = 0; i < this->size; ++i) {
			if (!queuelist[i]->isEmpty()) {
				queuelist[i]->pop();
				return;
			}
		}
		throw QueueEmpty;
	}
	
	//front
	T front() {
		for (size_t i = 0; i < this->size; ++i) {
			if (!queuelist[i]->isEmpty()) {
				return queuelist[i]->front();
			}
		}
		throw QueueEmpty;
	}

	//isEmpty

	bool isEmpty() {
		for (size_t i = 0; i < this->size; ++i) {
			if (!queuelist[i]->isEmpty()) {
				return false;
			}
		}
		return true;
	}

	void dump() {
		for (size_t i = 0; i < this->size; ++i) {
			queuelist[i]->dump();
		}
	}

};
