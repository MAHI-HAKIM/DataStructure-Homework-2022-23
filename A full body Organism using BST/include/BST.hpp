#ifndef BST_HPP
#define BST_HPP

#include "Node.hpp"

class BST
{
public:
	BST();
	~BST();

	void DestroyTree();
	void Insert(int);
	Node* Root;
	int Height();
	bool IsBalanced();

private:
	int ElementSize;
	bool IsBalanced(Node* root);
	int Height(Node* root);
	void Insert(int, Node*);
	void DestroyTree(Node*);

};

#endif // !BST_HPP
