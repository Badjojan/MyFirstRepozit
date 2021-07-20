
#include <iostream>
#include "Tree.h"
using namespace std;


template<typename T>
struct Node {
	Node<T>* next=NULL;
	T data;
	Node<T>* prev = NULL;
};
template<typename T>
void AddNodeEnd(Node<T>*& Head, Node<T>*& Tail, T data)
{
	Node<T>* temp = new Node<T>;
	temp->data = data;
	temp->next = NULL;
	if (Head != NULL)
	{
		Tail->next = temp;
		temp->prev = Tail;
		Tail = temp;
	}
	else
	{
		Head = Tail = temp;
	}
}
template<typename T>
void ViewForvard(Node<T>* head) {
	Node<int>* help = head;
	while (help != NULL)
	{
		cout << help->data << "\t";
		help = help->next;
	}
	cout << endl;
}
template<typename T>
void View(Node<T>* tail) {
	Node<int>* help = tail;
	while (help != NULL)
	{
		cout << help->data << "\t";
		help = help->prev;
	}
	cout << endl;
}

int main()
{
	/*Node<int> * head = new Node <int>;
	
	head->data = 0;
	head->prev = NULL;
	

	head->next = new Node<int>;
	head->next->data = 1;
	head->next->prev = head;
	
	Node<int>* Tail = new Node <int>;
	Tail->data = 2;
	Tail->prev = head->next;
	
	head->next->next = Tail;

	Node<int> *help = head;
	while (help != NULL)
	{
		cout << help->data << "\t";
		help = help->next;
	}
	cout << endl;
	Node<int>* help2 = Tail;
	while (help2 != NULL)
	{
		cout << help2->data << "\t";
		help2 = help2->prev;
	}*/
	
	
	
	
	/*Node<int>* Head=NULL;
	Node<int>* Tail = NULL;
	for (int i = 0; i <10 ; i++)
	{
		AddNodeEnd(Head, Tail, i);
	}
	ViewForvard(Head);
	View(Tail);*/

	BinaryTree tree;
	tree.Add(8);
	tree.Add(3);
	tree.Add(10);
	tree.Add(6);
	tree.Add(9);
	tree.InOrder();
}


