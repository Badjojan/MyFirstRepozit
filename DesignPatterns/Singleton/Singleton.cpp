#include<iostream>
#include<fstream>
#include<time.h>
#include "Logger.h"

using namespace std;



int main() {
	// получаем доступ к объекту логирования
	Logger* pLogger = Logger::GetInstance();
	// записываем данные о логировании
	pLogger->PutMessage("This is first");
	pLogger->PutMessage("This is second");

	return 0;
}