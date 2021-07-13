

#include <iostream>
#include "Employer.h"
#include "Header.h"

int main()
{
	//Employer** employer = new Employer * [3];
	//employer[0] = new President;
	//employer[1] = new Manager;
	//employer[2] = new Worker;

	//for (int i = 0; i < 3; i++)
	//{
	//	employer[i]->Print();
	//	cout << endl;
	//}
	////delete employer[0];
	//for (int i = 0; i < 3; i++)
	//{
	//	delete employer[i];
	//}
	//delete[] employer;


	Weapon** weapon = new Weapon * [3];
	weapon[0] = new Gun;
	weapon[1] = new Сrossbow;
	weapon[2] = new Bomb;

	for (int i = 0; i < 3; i++)
	{
		weapon[i]->Attact(5);
		cout << endl;
	}
	
	for (int i = 0; i < 3; i++)
	{
		delete weapon[i];
	}
	delete[] weapon;

}


