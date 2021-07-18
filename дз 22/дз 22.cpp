

#include <iostream>
#include "двухсвязный список.h"

int main()
{
    List list;
    list.Print();
    list.Add(1, 6);
    list.Print();
    list.Add(2, 7);
    list.Add(3, 8);
    list.Print();
    list.Add(1, 6);
    list.Print();
    list.Add(3, 9);
    list.Print();
    list.DelAll();
    list.Print();
    list.AddHead(33);
    list.Add(22, 9);
    list.Del(22);
}

