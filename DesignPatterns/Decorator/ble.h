#pragma once
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "CDecorator.h"
using namespace std;

class ble :
	public Decorator
{
public:
	ble(CollectionItem*);
	virtual ~ble();
private:
	int count=5;
public:
	

	void Show() const;
};