#include<iostream>
#include<fstream>
#include<time.h>
#include "Logger.h"

using namespace std;



int main() {
	// �������� ������ � ������� �����������
	Logger* pLogger = Logger::GetInstance();
	// ���������� ������ � �����������
	pLogger->PutMessage("This is first");
	pLogger->PutMessage("This is second");

	return 0;
}