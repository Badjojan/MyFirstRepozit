#include <iostream>
#include "Student2.h"
using namespace std;

int main(int argc, char **argv) {

	/*Group g(15);

	g.AddStudent("Petrov", 1);
	g.AddStudents("Petro");
	g.AddStudents("Petr");

	try {

		auto s = g.At(2);
		cout << s.name;
	}
	catch (const std::exception &e) {
		cout << "--> " << e.what() << endl;
	}


	return 0;*/
	//создаем объект
	//инициализируем этим объектом умный указатель
	SmartPointer PTR(new Group(15));
	//проверяем работу умного указателя
	PTR->AddStudent("hjkhhh",9);
	try {

		auto s = PTR->At(0);
		cout << s.name;
	}
	catch (const std::exception& e) {
		cout << "--> " << e.what() << endl;
	}
	SmartPointer PTR2 = PTR;
	static_cast<Group*>(PTR2)->AddStudent("AddStudent", 9);
	try {

		auto s = PTR2->At(1);
		cout << s.name;
	}
	catch (const std::exception& e) {
		cout << "--> " << e.what() << endl;
	}
}