#include "Tree.h"

BinaryTree::BinaryTree(node* _root)
{
	root->data = _root->data;
	root->right = _root->right;
	root->left = _root->left;
}

void BinaryTree::AddRight(int valua)
{
	node* newNode = new node{ valua,NULL,NULL };

	if (this->root == NULL)
	{
		this->root = newNode;
		return;
	}
	node* help = this->root;
	while (help->right != NULL)
	{
		help = help->right;
	}
	help->right = newNode;
}

void BinaryTree::AddLeft(int valua)
{
}
