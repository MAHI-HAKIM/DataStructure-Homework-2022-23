/**
* @file         RowList.cpp
* @description  Implemention Of how to Make a row List
* @course       Veri yapilari 1C
* @assignment   1. Odev
* @date         27/11/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/

#include "RowList.hpp"
#include "RowNode.hpp"
#include "ManagerList.hpp"

ManagerList *MNG = new ManagerList();

RowList::RowList(RowNode * Node , double Average)
{
	this->Header = Node;
}

//Creates the Rowlists
RowNode* RowList::MakeRowList(int data)
{
	RowNode* _New = new RowNode(data);

	if (Header == NULL)
	{
		Header = _New;
	}
	else
	{
		RowNode* temp = Header;

		while (temp->Next != 0)
		{
			temp = temp->Next;
		}

		temp->Next = _New;
		_New->Prev = temp;
		_New->Next = NULL;
	}

	return Header;
}

//Brings adress at Index
RowNode* RowList::AdressAt(int Index)
{
	RowNode* temp = Header;

	int Counter = 0;

	while (Index >= 0 && temp != 0)
	{
		if (Counter == Index)
		{
			return temp;
		}
		temp = temp->Next;

		Counter++;
	}
	return 0;
}

//Get aviale data inside a single Row
int RowList::GetNumData(int Index)
{
	RowNode* temp;

	if (Index >= 0)
	{
		temp = AdressAt(Index);
		return temp->Num;
	}
  return 0;
}

//Prints RowList
void RowList::PrintRowList(int x, int y)
{
	int yIndex = y;


	for (RowNode* itr = Header; itr != NULL; itr = itr->Next)
	{
		if (itr->Prev == NULL)
		{
			MNG->gotoxy(x, ++yIndex);
			cout << "^^^^^^^^^^" << endl;
		}
		MNG->gotoxy(x, ++yIndex);
		cout << "|" << itr << "|\n";
		MNG->gotoxy(x, ++yIndex);
		cout << "----------" << endl;
		MNG->gotoxy(x, ++yIndex);
		cout << "|" << setw(8) << itr->Num << "|" << endl;
		MNG->gotoxy(x, ++yIndex);
		cout << "----------" << endl;
		MNG->gotoxy(x, ++yIndex);
		cout << "|" << setw(8) << itr->Next << "|\n";
		MNG->gotoxy(x, ++yIndex);
		cout << "----------" << endl;
	}

}

//Delete the Number At that index
void RowList::DeleteTheNode(int Index)
{
	RowNode* Current = Header;

	if (Index >= 0)
	{
		for (int i = 0; i < Index; i++)
		{
			if (!Current)
				break;
			Current = Current->Next;
		}

		if (!Current) throw "No Element to be found at this Current Node";

		if (Current->Prev)
			Current->Prev->Next = Current->Next;

		else
			Header = Current->Next;

		if (Current->Next)
			Current->Next->Prev = Current->Prev;

		delete Current;
	}

}

//Counts How Many elements are there inside a Single row
int RowList::CountNodeAmount()
{
	int len = 0;

	RowNode* temp = Header;

	while (temp != NULL)
	{
		temp = temp->Next;
		len++;
	}

	return len;
}

RowList::~RowList()
{
	//NOTE : this Destructor is Called inside ManagerList to Delete Every Elements line by line

	RowNode* CurrNOde = Header;
	RowNode* NextNode = NULL;

	while (CurrNOde != NULL)
	{
		//saves the link to the Next Node
		NextNode = CurrNOde->Next;
		//Delete The Current Node
		delete CurrNOde;
		//Assign Current To the Next Node
		CurrNOde = NextNode;

	}
   	
}