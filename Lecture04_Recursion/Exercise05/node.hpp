#pragma once
#include<iostream>

template <typename T>
class Node
{
public:
	Node(T info = T(), Node* next = NULL) {
		this->next = next;
		this->info = info;
	}
	T info;
	Node* next;

};
