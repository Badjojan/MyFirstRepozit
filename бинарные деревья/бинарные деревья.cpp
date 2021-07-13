
#include <iostream>
#include "arrayTemp.h"
#include "arrayTemp.cpp"

int main()
{
    try {
        ArrayTemp<char>myMass(5);

        myMass.Insert(5, 1);
        cout << myMass << endl;
        myMass.Remove(1);
        cout << myMass << endl;
    }
    catch (exception& exp)
    {
        cout << exp.what() << endl;
    }
}


