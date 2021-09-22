

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include "Student.h"
#include <exception>
#include <stdarg.h>



Student::Student(string _name, int _rate)
{
	name = _name;
	rate = _rate;
}

Group::Group(size_t _capacity)
{
	st=new Student[_capacity];

}

Group::~Group()
{
	if (st != nullptr) {
		delete []st;
		st = nullptr;
	}
}

size_t Group::AddStudent(const string& _name, int _rate)
{
	
		if (_num_students >= capacity)
			throw std::out_of_range("out ");
		st[_num_students].name = _name;
		st[_num_students].rate = _rate;
		_num_students++;
		return _num_students-1;
	
	
}
bool Group::isAppendAllowed()
{
	return (_num_students >= capacity) ? true : false;
}

size_t Group::AddStudents(const char* _name ...)
{
	int counter = 0;
	if (_name == nullptr) {
		return 0;
		throw exception("Out");
	}
		va_list arg_ptr;       
		va_start(arg_ptr, _name);
		int rate = va_arg(arg_ptr, int);
		if (!isAppendAllowed()) {
			va_end(arg_ptr);
			throw exception("Out");
		}
		this->AddStudent(_name, rate);
		counter++;
		while (true) {
			if (isAppendAllowed()) {
				va_end(arg_ptr);
				throw exception("Out");
			}
			_name = va_arg(arg_ptr, const char*);
			if (_name == nullptr)
				break;
			rate = va_arg(arg_ptr,int);
			this->AddStudent(_name, rate);
			counter++;

		}
		va_end(arg_ptr);
		return counter;
	
}

size_t Group::FindStudent(const string& _name)
{

	for (size_t i = 0; i < _num_students; i++) {
		if (st[i].name == _name) {
			cout << st[i].name << endl;
			cout << st[i].rate << endl;
			return i;

		}
		
	}
	return size_t(-1);
}

Student& Group::At(size_t _idx)
{
	if (_idx== size_t(-1)|| _idx >= _num_students) {
		throw std::out_of_range("out ");
	}
	return st[_idx];
}

size_t Group::Delete(size_t _idx)
{
	if (_idx >= _num_students)
		throw std::out_of_range("out ");
	st[_idx].name .clear();
	st[_idx].rate = NULL;
	for (size_t i = 0; i < _num_students; i++) {
		
		if (i >= _idx) {
			st[i] = st[i + 1];
		}
	}
	_num_students--;
	return _num_students - 1;
}
