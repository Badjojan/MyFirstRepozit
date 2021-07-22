#include<iostream>
#include "Car.h"
#include<time.h>
#include "table.h"

using namespace std;

int main() {

	//// ������ ������
	//string manufacturer;
	//cout << endl << "Input manufacturer of car:" << endl;
	//std::getline(std::cin, manufacturer);

	//string description;
	//cout << "Input description of car:" << endl;
	//std::getline(std::cin, description);

	//string color;
	//cout << "Input color of car:" << endl;
	//std::getline(std::cin, color);

	//int year;
	//cout << "Input year of car:" << endl;
	//cin >> year;

	//// �������� ������
	//Car c(manufacturer, description, color, year);
	//c.Show();

	//cout << "Let's clone!\nLet's prototype!" << endl;

	//// ��������� ������
	//Car* copy = (Car*)c.Clone();
	//copy->Show();
	//// ������� ������������� ������
	//delete copy;

	//return 0;

	// ������ ������
	string manufacturer;
	cout << endl << "Input manufacturer of Table:" << endl;
	std::getline(std::cin, manufacturer);

	

	string color;
	cout << "Input color of Table:" << endl;
	std::getline(std::cin, color);

	int year;
	cout << "Input year of Table:" << endl;
	cin >> year;

	// �������� ������
	Table c(manufacturer, color, year);
	c.Show();

	cout << "Let's clone!\nLet's prototype!" << endl;

	// ��������� ������
	Table* copy = (Table*)c.Clone();
	copy->Show();
	// ������� ������������� ������
	delete copy;

	return 0;
}