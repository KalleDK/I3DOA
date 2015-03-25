#include <iostream>
#include <string>

#include "BTNode.hpp"
#include "BTNodeToolkit.hpp"

int main(void)
{
	BTNode<int>* root = NULL;
	BTNodeToolkit<int>::insert(root, 5);
	BTNodeToolkit<int>::insert(root, 6);
	BTNodeToolkit<int>::insert(root, 7);
	BTNodeToolkit<int>::insert(root, 8);
	BTNodeToolkit<int>::insert(root, 0);
	BTNodeToolkit<int>::insert(root, 6);
	BTNodeToolkit<int>::insert(root, 6);
	BTNodeToolkit<int>::insert(root, 2);
	std::cout << "Print:\n";
	BTNodeToolkit<int>::print(root);
	std::cout << "Sum: " << BTNodeToolkit<int>::sum(root) << "\n";
	std::cout << "Search 4: " << BTNodeToolkit<int>::search(root, 4) << "\n";
	std::cout << "Search 7: " << BTNodeToolkit<int>::search(root, 7) << "\n";
	std::cout << "Depth : " << BTNodeToolkit<int>::getDepth(root) << "\n";
	root = BTNodeToolkit<int>::rotateRight(root);
	std::cout << "Print Rotate right:\n";
	BTNodeToolkit<int>::print(root);
	std::cout << "Print Rotate right:\n";
	root->right = BTNodeToolkit<int>::rotateRight(root->right);
	BTNodeToolkit<int>::print(root);
	std::cout << "Print Rotate left:\n";
	root->right = BTNodeToolkit<int>::rotateLeft(root->right);
	BTNodeToolkit<int>::print(root);
	std::cout << "Print Rotate left:\n";
	root->right = BTNodeToolkit<int>::rotateLeft(root->right);
	BTNodeToolkit<int>::print(root);
	std::cout << "Print Rotate left:\n";
	BTNodeToolkit<int>::rotateRight(root->right->left);
	BTNodeToolkit<int>::print(root);
	std::cout << "Print Rotate left:\n";
	BTNodeToolkit<int>::rotateLeft(root->right->right);
	BTNodeToolkit<int>::print(root);
	std::cout << "Print Rotate left:\n";
	BTNodeToolkit<int>::rotateLeft(root->right);
	BTNodeToolkit<int>::print(root);
}
