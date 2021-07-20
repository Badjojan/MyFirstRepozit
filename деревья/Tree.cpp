#include "Tree.h"

void BinaryTree::_PreOder(node*current)
{
	if (current == NULL)
		return;
	cout << current->data << "\t";
	this->_PreOder(current->left);
	this->_PreOder(current->right);
}

void BinaryTree::_Inoder(node* current)
{
	if (current == NULL)
		return;
	this->_Inoder(current->left);
	cout << current->data << "\t";
	
	this->_Inoder(current->right);
}

void BinaryTree::_Add(node*& curr, int data)
{
	node* newNode = new node{ data,NULL,NULL };
	if (curr == NULL) {
		curr = newNode;
		return;
	}
	else if (data < curr->data)
		_Add(curr->left, data);
	else
		_Add(curr->right, data);
}

BinaryTree::BinaryTree(node* _root)
{
	this->root = root;
	/*root->right = _root->right;
	root->left = _root->left;*/
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
	node* newNode = new node{ valua,NULL,NULL };

	if (this->root == NULL)
	{
		this->root = newNode;
		return;
	}
	node* help = this->root;
	while (help->left != NULL)
	{
		help = help->left;
	}
	help->left = newNode;
}

void BinaryTree::Add(int data) { this-> _Add( this->root, data); }




void BinaryTree::PostOrder()
{
}

void BinaryTree::Clear()
{
}
