#pragma once

#include "Device.h"

/*
 * ���������� ������� ���������� ����� Car
 */
class Table : public Device {
private:
	// �������� ������
	string manufacturer;
	
	string color;

	int year;

public:
	// ������������
	Table() :Table("No information",  "No color", 0) {
		SetName("Table");
	}
	Table(string cmanufacturer,  string ccolor, int cyear);
public:
	// ��������������� �������
	int GetYear()const {
		return year;
	}
	string GetManufacturer()const {
		return manufacturer;
	}
	
	string GetColor()const {
		return color;
	}

	void SetYear(int cyear) {
		year = cyear;
	}
	void SetManufacturer(string cmanufacturer) {
		manufacturer = cmanufacturer;
	}
	void SetColor(string ccolor) {
		color = ccolor;
	}
	

	// ���������� ����������� ������� � �������
	Device* Clone()const;
	void Show() const;
};

// ���������� ������������
Table::Table(string cmanufacturer,  string ccolor, int cyear) {
	SetName("Table");

	SetManufacturer(cmanufacturer);
	
	SetColor(ccolor);
	SetYear(cyear);
}

// ������� ������������
Device* Table::Clone() const {
	Table* tempCar = new Table();

	/* �������� ��������!
	 * ��� ��� ������ � ������������ ������� ����� ����������
	 * ����������� �����������, ����������� ��������
	 * � ����������� �������� =
	 */

	*tempCar = *this;
	return tempCar;
}

// ����������� �� ����� ������
void Table::Show() const {
	Device::Show();
	
	cout << "\nManufacturer of Table is\n" << GetManufacturer() << "\n";
	cout << "\nYear of Table is\n" << GetYear() << "\n";
	cout << "\nColor of Table is\n" << GetColor() << "\n";
}
