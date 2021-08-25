#include <iostream>
#include "Student.h"
using namespace std;

int main(int argc, char **argv) {

	Group g(15);

	g.AddStudent("Petrov", 9);

	try {

		auto s = g.At(0);
		cout << s.name;
	}
	catch (const std::exception &e) {
		cout << "--> " << e.what() << endl;
	}


	return 0;
}