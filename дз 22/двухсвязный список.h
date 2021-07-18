#pragma once
#include <iostream>
using namespace std;

struct Elem
{
	int data;
	Elem* next;
	Elem* prew;
};

class List {
protected:
	Elem* Head;
	Elem* Tail;
	int count=0;

public:
	List();
	~List();
	void AddHead(int n);
	void AddTail(int n);
	void Add(int plase, int data = 0);
	void Del(int pos);
	void DelAll();
	
	int GetCount();
	void Print();


};