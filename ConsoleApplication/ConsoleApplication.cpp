﻿

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
//структура, хранящая
//информацию о человеке
struct Man {
	//Имя
	char str[255];
	//Возраст
	int age;
	/*int count;*/
};
void main()
{
	//Создание объектов структуры
	Man A, B;
	//Запись в объект A
	//информации, полученной с клавиатуры
	int count =0;
	cout << "\nEnter count:\n";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << "\nEnter name:\n";
		cin >> A.str;
		cout << "\nEnter age:\n";
		cin >> A.age;

		//открытие файла на запись
		FILE* f = fopen("Test3.txt", "wb+");
		if (!f) exit(0);
		//запись объекта А в файл
		fwrite(&A, sizeof(Man), 1, f);

		fclose(f);
		//открытие файла на чтение
		f = fopen("Test3.txt", "rb+");
		if (!f) exit(0);
		//считывание содержимого файла
		//в объект B
		fread(&B, sizeof(Man), 1, f);
		//открытие файла на запись
		fclose(f);
		//показ результата на экран
		cout << "\nName — " << B.str << "\n\nAge — " << B.age << "\n\n";
	}
}

