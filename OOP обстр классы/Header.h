#pragma once
#include <iostream>
#include "Windows.h"
using namespace std;

class Weapon
{
	/*int count;*/
public:
	void virtual OneUse() = 0;
	void virtual Attact(int count)
	{
		for (int i = 0; i < count; i++)
		{
			this->OneUse();
			Sleep(50);
		}
	}
	virtual ~Weapon(){}
};

class Gun :virtual public Weapon
{
public:
	void OneUse()override
	{
		cout << "Gun ----->" << endl;
	}

};
class Ñrossbow :virtual public Weapon
{
public:
	void OneUse()override
	{
		cout << "Crossbow ----->" << endl;
	}

};
class Bomb :virtual public Weapon
{
public:
	void OneUse()override
	{
		cout << "Bomb ----->" << endl;
	}

};