#pragma once
#include<iostream>

class Node
{
public:
	Node(int info = 0, Node* next = NULL);
	int info;
	Node* next;

};
