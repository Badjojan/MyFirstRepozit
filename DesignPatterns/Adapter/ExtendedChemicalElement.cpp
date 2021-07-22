#include "ExtendedChemicalElement.h"



ExtendedChemicalElement::ExtendedChemicalElement(string pName):ChemicalElement(pName)
{
	pInformation = new ChemicalElementsInformation();
}


ExtendedChemicalElement::~ExtendedChemicalElement()
{
	delete pInformation;
}

void ExtendedChemicalElement::Show()
{
	cout << "\n============================\n";
	ChemicalElement::Show();
	density = pInformation->GetDensity(name);
	position = pInformation->GetPositionFromPeriodicTable(name);
	group = pInformation->GetGroupFromPeriodicTable(name);
	cout << "\nDensity of Element: " << density << endl;
	cout << "\nPosition in Periodic Table:" << position << endl;
	cout << "\group in Periodic Table:" << group << endl;
	cout << "\n============================\n";
}
