#include "ble.h"

ble::ble(CollectionItem* item) :Decorator(item)
{

}

ble::~ble()
{
}



void ble::Show() const
{
	item->Show();
	cout << "count of ble ="<<count << endl;
}
