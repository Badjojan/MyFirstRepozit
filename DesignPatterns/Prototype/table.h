#pragma once

#include "Device.h"

/*
 * Конкретный потомок устройства класс Car
 */
class Table : public Device {
private:
	// свойства машины
	string manufacturer;
	
	string color;

	int year;

public:
	// конструктора
	Table() :Table("No information",  "No color", 0) {
		SetName("Table");
	}
	Table(string cmanufacturer,  string ccolor, int cyear);
public:
	// вспомогательные функции
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
	

	// реализация виртуальной функции в потомке
	Device* Clone()const;
	void Show() const;
};

// реализация конструктора
Table::Table(string cmanufacturer,  string ccolor, int cyear) {
	SetName("Table");

	SetManufacturer(cmanufacturer);
	
	SetColor(ccolor);
	SetYear(cyear);
}

// функция клонирования
Device* Table::Clone() const {
	Table* tempCar = new Table();

	/* Обратите внимание!
	 * При при работе с динамической памятью нужно определить
	 * конструктор копирования, конструктор переноса
	 * и перегрузить оператор =
	 */

	*tempCar = *this;
	return tempCar;
}

// Отображение на экран данных
void Table::Show() const {
	Device::Show();
	
	cout << "\nManufacturer of Table is\n" << GetManufacturer() << "\n";
	cout << "\nYear of Table is\n" << GetYear() << "\n";
	cout << "\nColor of Table is\n" << GetColor() << "\n";
}
