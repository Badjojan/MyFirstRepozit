#pragma once
#include <iostream>

using namespace std;

template<typename T>
class ArrayTemp
{
private:
	T* mass=NULL;
	int size=0;
public:
	ArrayTemp(int = 0);
	friend ostream& operator <<(ostream& out, ArrayTemp& arr)
	{
		try
		{
			if (arr.mass == NULL)
				throw invalid_argument("null mass argument");
			for (int i = 0; i < arr.size; i++)
			{

				out << arr.mass[i] << "\t";
			}
			out << endl;
		}

		catch (exception& exp)
		{
			cout << "Input error :" << exp.what() << endl;
		}
	}
	void Insert(T value, int index=0);
	T Remove(int index);
};

