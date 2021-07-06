

#include <iostream>
#include "Employer.h"

int main()
{
	Employer** employer = new Employer * [3];
	employer[0] = new President;
	employer[1] = new Manager;
	employer[2] = new Worker;

	for (int i = 0; i < 3; i++)
	{
		employer[i]->Print();
		cout << endl;
	}
	//delete employer[0];
	for (int i = 0; i < 3; i++)
	{
		delete employer[i];
	}
	delete[] employer;
}


