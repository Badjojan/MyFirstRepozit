#pragma once
#include <iostream>
using namespace std;

class Employer
{
protected:
	int priority;
public:
	void virtual Print() = 0;

	virtual ~Employer() {}

};

class President :virtual public Employer
{

public:
	President(int _priority = 1)
	{
		priority = _priority;
	}
	void Print()override {
		cout << "Priority president # " << priority;
	}

};
class Manager :virtual public Employer
{
public:
	Manager(int _priority = 2)
	{
		priority = _priority;
	}
	void Print()override {
		cout << "Priority manager # " << priority;
	}

};
class Worker :virtual public Employer
{
public:
	Worker(int _priority = 3)
	{
		priority = _priority;
	}
	void Print()override {
		cout << "Priority worker # " << priority;
	}

};