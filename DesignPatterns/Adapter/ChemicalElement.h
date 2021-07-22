#pragma once
#include <string>
#include <iostream>
using namespace std;

// Target
class ChemicalElement
{
protected:
	string name;
	double density;
	int position;
	int group;

public:
	ChemicalElement(string);
	virtual ~ChemicalElement();
	virtual void Show()
	{
		cout << "\nChemical Element: " << name << endl;
	}
};

