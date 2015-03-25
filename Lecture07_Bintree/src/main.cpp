#include <iostream>
#include <string>

#include "BTNode.hpp"
#include "BTNodeToolkit.hpp"

int main(void)
{
	BTNode<int>* node = new BTNode<int>(5);
	node->left = new BTNode<int>(6);
	node->left->right = new BTNode<int>(9);
	node->right = new BTNode<int>(7);
	node->right->right = new BTNode<int>(7);
	node->right->left = new BTNode<int>(7);
	std::cout << "Sum: " << BTNodeToolkit<int>::sum(node) << "\n";
	BTNodeToolkit<int>::print(node);
}
