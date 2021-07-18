#include "двухсвязный список.h"

List::List()
{
	Head = Tail = 0;
	count = 0;
}

List::~List()
{
	DelAll();
}

void List::AddHead(int n)
{
	try {
		if (n < 0||n>9 )
			throw invalid_argument("Incorrect argument: should be>=1 and <9") ;
		Elem* temp = new Elem;

		temp->prew = 0;

		temp->data = n;

		temp->next = Head;

		if (Head != 0)
			Head->prew = temp;

		if (count == 0)
			Head = Tail = temp;
		else

			Head = temp;
		count++;
		
	}
	catch (exception& exp)
	{
		cout << exp.what() << endl;
	}
}
void List::AddTail(int n)
{
	try {
		if (n < 0 || n>9)
			throw invalid_argument("Incorrect argument: should be>=1 and <9");
		Elem* temp = new Elem;
		

		temp->next = 0;

		temp->data = n;

		temp->prew = Tail;

		if (Tail != 0)
			Tail->next = temp;

		if (count == 0)
			Head = Tail = temp;
		else

			Tail = temp;
		count++;
	}
	catch (exception& exp)
	{
		cout << exp.what() << endl;
	}
}
void List::Add(int pos,int n)
{
	
	try {
		if (n < 0 || n>9)
			throw invalid_argument("Incorrect argument: should be>=1 and <9");
		if (pos<0 || pos>count + 2)
			throw invalid_argument("Incorrect position: should be>=1 and <count+2");
		if (pos == count + 1)
		{


			AddTail(n);
			return;
		}
		else if (pos == 1)
		{


			AddHead(n);
			return;
		}

		int i = 1;

		Elem* Ins = Head;
		while (i < pos)
		{

			Ins = Ins->next;
			i++;
		}

		Elem* PrevIns = Ins->prew;

		Elem* temp = new Elem;
		temp->data = n;

		if (PrevIns != 0 && count != 1)
			PrevIns->next = temp;
		temp->next = Ins;
		temp->prew = PrevIns;
		Ins->prew = temp;
		count++;
	}
	catch (exception& exp)
	{
		cout << exp.what() << endl;
	}
}


void List::Del(int pos)
{
	try {
		if (pos<0 || pos>count)
			throw invalid_argument("Incorrect position: should be>=1 and <");

		int i = 1;
		Elem* Del = Head;
		while (i < pos)
		{
			Del = Del->next;
			i++;
		}

		Elem* PrevDel = Del->prew;

		Elem* AfterDel = Del->next;

		if (PrevDel != 0 && count != 1)
			PrevDel->next = AfterDel;

		if (AfterDel != 0 && count != 1)
			AfterDel->prew = PrevDel;

		if (pos == 1)
			Head = AfterDel;
		if (pos == count)
			Tail = PrevDel;

		delete Del;
		count--;
	}
		catch (exception& exp)
		{
			cout << exp.what() <<count<< endl;
		}
	
}
void List::DelAll()
{
	while (count != 0)
		Del(1);
}

int List::GetCount()
{
	return count;
}

void List::Print()
{
	


		Elem* nov = Head;
		for (int i = 0; i < count; i++) {
			cout << nov->data << " ";
			nov = nov->next;
		}
		cout << endl;
	
}


