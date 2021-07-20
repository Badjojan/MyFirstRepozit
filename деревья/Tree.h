#pragma once
#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left = NULL;
	node* right = NULL;
};

class BinaryTree
{
private:
	node* root;
	void _PreOder(node*);

	void _Inoder(node*);
	void _Add(node*& curr, int data);
public:
	BinaryTree(node* _root= NULL);

	void AddRight(int valua);
	void AddLeft(int valua);

	void Preoder() {
		this->_PreOder(this->root);
	}
	/*{
		if (root == NULL)
		{
			return;
		}
		cout << root->data << "\t";
		Preoder(root->left);
		Preoder(root->right);
	}*/

	void Add(int data) ;

	void InOrder() {
		this->_Inoder(this->root);
	}
	void PostOrder();

	void Clear();
	~BinaryTree() { this->Clear(); }
};