#pragma once

#include"GraphNode.h"
#include<iostream>
#include<queue>

using namespace std;


template<class Item>
class GraphToolkit
{
public:
	// These typedef's allow us to define nodes and graphs easily.
	// Note that everything in this toolkit could be done without these typedef's
	// - they only exist to make life a little easier for us
	typedef vector<GraphNode<Item>*> Graph;	// Vector is used to hold the complete Graph
	typedef typename Graph::iterator GraphIter;			// Iterator for a Graph
	typedef GraphNode<Item> Node;				// Node in a graph

	typedef vector<Edge<Item>*> EdgeList;
	typedef typename vector<Edge<Item>*>::iterator EdgeListIter;

	static void addEdge(Node*& from, Node*& to, size_t weight=1)
	{
		from->neighbors.push_back(new Edge<Item>(from, to, weight));
	}


	static void removeEdge(Node*& from, Node*& to)
	{
		EdgeListIter ix = from->neighbors.begin();

		for(;ix != from->neighbors.end(); ++ix)
		{
			if((*ix)->to==to)
			{
				from->neighbors.erase(ix);
				return;
			}
		}
	}


	static void dumpGraph(Graph g)
	{
		for (GraphIter curNode = g.begin(); curNode != g.end(); ++curNode)
		{
			cout << "Node " << (*curNode)->data << " (" << (*curNode)->marked << ", " << (*curNode)->cost << "): neighbors: ";
			
			for(EdgeListIter ix =(*curNode)->neighbors.begin(); ix != (*curNode)->neighbors.end(); ++ix)
			{
				cout << (*ix)->to->data << " (" << (*ix)->weight << "), ";
			}
			cout << endl;
			printRoute(*curNode);
		}
	}

	static void Dijkstra(Graph g, Node* node)
	{
		
		queue<GraphNode<Item>*> q;
		Node* n;

		for (GraphIter curNode = g.begin(); curNode != g.end(); ++curNode)
		{
			(*curNode)->prev = (*curNode);
			(*curNode)->cost = SIZE_MAX;
		}

		node->cost = 0;
		node->prev = node;
		q.push(node);
		while (! q.empty())
		{
			n = q.front();
			q.pop();
			for(auto it = n->neighbors.begin(); it != n->neighbors.end(); ++it) {
				if (n->cost + (*it)->weight < (*it)->to->cost) {
					(*it)->to->cost = n->cost + (*it)->weight;
					(*it)->to->prev = n;
					q.push((*it)->to);
				}
			}
		}
	}

	static void printRoute(Node* node) 
	{
		Node* n = node;
		while (n->prev != n) {
			cout << n->data << " -> ";
			n = n->prev;
		}
		cout << n->data << endl;
	}

};
