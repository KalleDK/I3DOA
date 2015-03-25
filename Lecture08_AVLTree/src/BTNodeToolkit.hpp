#pragma once

#include <iostream>
#include <algorithm>
#include "BTNode.hpp"

template <class T>
class BTNodeToolkit
{
public:
	static int getDepth(BTNode<T>*& root)
	{
		if (root == NULL)
			return 0;
		return 1 + std::max(getDepth(root->left), getDepth(root->right));
	}
	// Root != NULL
	// Root->left != NULL
	static BTNode<T>* rotateRight(BTNode<T>* root)
	{
		// Move old root parent to new root parent
		root->left->parent = root->parent;
		// Move new root to old root parent
		root->parent = root->left;
		// Move new root right to old root left
		root->left = root->parent->right;
		// Move old root to new root right
		root->parent->right = root;

		// Update moved node
		if (root->left != NULL) {
			root->left->parent = root->right->left;
		}

		// Update old parent
		if (root->parent->parent != NULL) {
			if (root->parent->parent->right == root->parent->right) {
				root->parent->parent->right = root->parent;
			} else {
				root->parent->parent->left = root->parent;
			}
		}

		return root->parent;
	}

	static BTNode<T>* rotateLeft(BTNode<T>* root)
	{
		// Move old root parent to new root parent
		root->right->parent = root->parent;
		// Move new root to old root parent
		root->parent = root->right;
		// Move new root left to old root right
		root->right = root->parent->left;
		// Move old root to new root left
		root->parent->left = root;

		// Update moved node
		if (root->right != NULL) {
			root->right->parent = root->left->right;
		}

		// Update old parent
		if (root->parent->parent != NULL) {
			if (root->parent->parent->right == root->parent->left) {
				root->parent->parent->right = root->parent;
			} else {
				root->parent->parent->left = root->parent;
			}
		}

		return root->parent;
	}

	static void insert(BTNode<T>*& root, const T& data)
	{
		if (root == NULL) {
			root = new BTNode<T>(data);
		}
		else if (data < root->data) {
			if (root->left == NULL) {
				root->left = new BTNode<T>(data);
				root->left->parent = root;
			} else {
				insert(root->left, data);
			}
		}
		else if (data > root->data) {
			if (root->right == NULL) {
				root->right = new BTNode<T>(data);
				root->right->parent = root;
			} else {
				insert(root->right, data);
			}
		}
	}
	static bool search(BTNode<T>*& root, const T& data)
	{
		if (root == NULL) {
			return false;
		}
		else if (root->data == data) {
			return true;
		}
		else if (root->data < data) {
			return search(root->right, data);
		} else {
			return search(root->left, data);
		}
		
	}
	static void remove(BTNode<T>*& root, T data)
	{
		
	}
	static T sum(BTNode<T>* root)
	{
		if (root == NULL)
			return 0;
		return root->data + sum(root->left) + sum(root->right);
	}

	static void print(BTNode<T>* root, int depth = 0)
	{
		char y;
		if (root == NULL)
		{
			return;
		}
		print(root->right, depth + 1);
		std::cout << std::string(depth*3, ' ') << root->data << "\n";
		print(root->left, depth + 1);
	}

};
