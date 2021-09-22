#pragma once
#include <iostream>
using namespace std;

class Student
{
public:
	string name;
	int rate;


	Student(string _name = "No name", int _rate = 0);

};

class Group
{
private:

	size_t _num_students = 0;
	size_t capacity = 10;
	Student* st = nullptr;

public:
	Group(size_t _capacity = 0);

	/*///*~Group();*/

	size_t AddStudent(const string _name, int _rate);
	bool isAppendAllowed();
	size_t AddStudents(const char* _name...);
	size_t FindStudent(const string& _name);
	Student& At(size_t _idx);
	size_t Delete(size_t _idx);
	Student& operator[] (size_t _idx) {

	}
};

class SmartPointer {
	struct Dt
	{
		Group* ptr;
		int count;
		Dt(Group* p) { ptr = p, count = 1; }
		~Dt() { delete[]ptr; }

	};

	Dt* m_dptr;

public:
	SmartPointer(Group* p = NULL) {
		m_dptr = new Dt(p);
	}
	SmartPointer(const SmartPointer& obj) {
		operator=(obj);
	}

	SmartPointer& operator =(const SmartPointer& obj) {

		m_dptr = obj.m_dptr;
		m_dptr->count++;
		return *this;
	}
	~SmartPointer() {
		m_dptr->count--;
		if (m_dptr->count == 0) {
			delete m_dptr;
		}
	}

	operator Group* () {
	return	m_dptr->ptr;
	}
	Group* operator->() {
		return m_dptr->ptr;
	}
};
