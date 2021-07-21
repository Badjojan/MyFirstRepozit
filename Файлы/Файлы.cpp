

#include <iostream>
#include <windows.h>
#include <io.h>

#include <stdio.h>

using namespace std;
wchar_t* convertCharArrayToLPCWSTR(const char* charArray)
{
	wchar_t* wString = new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
	return wString;
}
//Функция, выводящая на экран строку
void RussianMessage(char* str) {
	char message[100];
	//перевод строки из кодировки Windows
	//в кодировку MS DOS
	CharToOem(convertCharArrayToLPCWSTR(str), message);
	cout << message;
}
//Функция копирования файла
bool CopyFile(const char* source, const char* destination) {
	const int size = 65536;
	FILE* src, * dest;
	//Открытие Файла
	if (!(src = fopen(source, "rb"))) {
		throw exception ("No files");
	}
	//Получение дескриптора файла
	int handle = _fileno(src);
	//выделение памяти под буффер
	char* data = new char[size];
	if (!data) {
		return false;
	}
	//Открытие файла, куда будет производиться копирование
	if (!(dest = fopen(destination, "wb"))) {
		delete[]data;
		return false;
	}
	int realsize;
	while (!feof(src)) {
		//Чтение данных из файла
		realsize = fread(data, sizeof(char), size, src);
		
			//Запись данных в файл
			fwrite(data, sizeof(char), realsize, dest);
	}
	//Закрытие файлов
	fclose(src);
	fclose(dest);
	return true;
}

int main()
{
	const char* source = "test_from.txt";
	const char* destination = "test_to.txt";

	try
	{
		CopyFile(source, destination);
	}
	catch (exception& exp)
	{
		cout<<"error in CopyFile-> "<<exp.what()<<endl;
	}
}

