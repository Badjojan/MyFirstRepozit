#pragma once
#include <iostream>
using namespace std;

class Student
{
public:
	string name;
	int rate;


	Student(string _name="No name",int _rate=0);
	
};

class Group
{
private:
	
	size_t _num_students = 0;
	size_t capacity =10 ;
	Student* st = nullptr;

public:
	Group(size_t _capacity=0);
	
	~Group();

	size_t AddStudent(const string& _name, int _rate);
	size_t AddStudents(char* _name...);
	size_t FindStudent(const string& _name);
	Student& At(size_t _idx);
	size_t Delete(size_t _idx);
	Student& operator[] (size_t _idx) {
		
	}
};

