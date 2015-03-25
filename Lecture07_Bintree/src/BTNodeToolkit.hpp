#pragma once

#include <iostream>
#include "BTNode.hpp"

template <class T>
class BTNodeToolkit
{
public:
	static T sum(BTNode<T>* root)
	{
		if (root == NULL)
			return 0;
		return root->data + sum(root->left) + sum(root->right);
	}

	static void print(BTNode<T>* root, int depth = 0)
	{
		if (root == NULL)
			return;
		print(root->right, depth + 1);
		std::cout << std::string(depth*3, ' ') << root->data << "\n";
		print(root->left, depth + 1);
	}
};
