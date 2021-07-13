#include "arrayTemp.h"

template<typename T>
inline ArrayTemp<T>::ArrayTemp(int size)
{
	try
	{
		if (size < 0 || size>1000000000)
			throw invalid_argument("bad argument size: should be>=0 and <1000000000");
		this->mass = new T[size];
		this->size = size;
	}
	catch (exception& exp)
	{
		cout << exp.what() << endl;
	}
}

template<typename T>
void ArrayTemp<T>::Insert(T value, int index)
{
	try
	{
		if (index < 0 || index >= this->size)
			throw out_of_range("index <0 or >size of mass");
		T* helpMass = new T [this->size + 1];
		int i = 0;
		for (; i < index; i++)
		{
			helpMass[i] = this->mass[i];
		}
			helpMass[i++] = value;
			for (; i < this->size; i++)
			{
				helpMass[i] = this->mass[i];
			}
			delete[]this->mass;
			this->mass = helpMass;
			this->size++;
	}
	catch (exception& exp)
			{
				cout << "Input error :" << exp.what() << endl;
			}
}

template<typename T>
T ArrayTemp<T>::Remove(int index)
{
	try
	{
		if (index < 0 || index >= this->size)
			throw out_of_range("index <0 or >size of mass");
		T* helpMass = new T[this->size - 1];
		int i = 0;
		for (; i < index; i++)
		{
			helpMass[i] = this->mass[i];
		}
		i++;
		for (; i < this->size-1; i++)
		{
			helpMass[i] = this->mass[i+1];
		}
		T help= this->mass[index];
		delete[]this->mass;
		this->mass = helpMass;
		this->size--;
		return help;
	}
	catch (exception& exp)
	{
		cout << "Remore error :" << exp.what() << endl;
		throw;
	}
	
}
//template<typename T>
//ostream& operator<<(ostream& out, ArrayTemp<T>& arr)
//{
//	try
//	{
//		if (arr.mass == NULL)
//			throw invalid_argument("null mass argument");
//		for (int i = 0; i < arr.size; i++)
//		{
//
//			out << arr[i]<<"\t";
//		}
//		out << endl;
//	}
//
//	catch (exception& exp)
//	{
//		cout << "Input error :" << exp.what() << endl;
//	}
//}