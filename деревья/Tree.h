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

public:
	BinaryTree(node* _root= NULL);

	void AddRight(int valua);
	void AddLeft(int valua);

	void Preoder(node* root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->data << "\t";
		Preoder(root->left);
		Preoder(root->right);
	}
};