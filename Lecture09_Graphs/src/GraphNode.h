#pragma once

#include<vector>
#include"Edge.h"
using namespace std;


template<class Item>
class GraphNode
{
public:
	GraphNode(Item d = Item()) : data(d), marked(false), cost(0), prev(NULL) {}

	Item data;
	vector<Edge<Item>*> neighbors;
	size_t cost;
	GraphNode<Item>* prev;
	bool marked;
};



