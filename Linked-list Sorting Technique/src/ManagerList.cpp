/**
* @file         Managerlist.cpp
* @description  Manage all implementaiont inside Mangerlist
* @course       Veri yapilari 1C
* @assignment   1. Odev
* @date         27/11/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/

#include "ManagerList.hpp"
#include <windows.h>

ManagerList::ManagerList()
{
	Mn_Head = NULL;
	RowListHeader = NULL;
	Size = 0;
	RandomNode = 0;
	Current = 0;
	NodePerPage = 8;
	Average = 0;
	Offset = 0;
	FinalOffSet = 0;
}

#pragma region READ AND ADD FUNCTIONS

void ManagerList::ReadFile()
{
	RowList* RW;
	string line;	//To read line by line
	ifstream file; //Read file

	file.open("veriler.txt");

	while (getline(file, line))
	{
		double Total{ 0 };
		if (line.empty()) continue;  // If there is an empty line it will pass it 

		stringstream stream(line); // To read Number one by one
		int chunk; // To store the numbers

		int j{ 0 }; // To count Numbers of element in a row to calculate the average

		RW = new RowList(RowListHeader, Average);

		//RW->Header = NULL;  //The Header Gets Nulled every new line starts to be read

		while (stream >> chunk)  // Reading the row Numbers inside a line
		{
			Total += chunk;
			RW->MakeRowList(chunk);
			j++;
		}
		AddToListAccordingly(RW, Calc_Avg(Total, j));
	}

}

ManagerNode* ManagerList::AddToListAccordingly(RowList* Head, double Average)
{
	ManagerNode* temp; //Create  a Temp ManagerNode to Iterate
	ManagerNode* _New = new ManagerNode(Head, Average); // A new Node that Contains the Adress of the Rowlist

	//If the list is Empty
	if (Mn_Head == NULL)
	{
		Mn_Head = _New;
	}
	//If the Node is to be Inserted at the begginig of the list
	else if (Mn_Head->AVRG >= _New->AVRG)
	{
		_New->Next = Mn_Head;
		_New->Next->Prev = _New;
		Mn_Head = _New;
	}
	else // Locate The Node After Which The Node is to be Inserted
	{
		temp = Mn_Head;
		while (temp->Next != NULL && temp->Next->AVRG < _New->AVRG)
		{
			temp = temp->Next;
		}
		_New->Next = temp->Next;

		if (temp->Next != NULL)
			_New->Next->Prev = _New;
		temp->Next = _New;
		_New->Prev = temp;
	}

	Size++;

	return Mn_Head;
}

//Bring the Adress of a Manager Node at that Specific Index
ManagerNode* ManagerList::BringManagerAdress(int Index)
{
	ManagerNode* temp = Mn_Head;

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

//Counts How Many Nodes Are there inside the ManagerList
int ManagerList::GetNodeAmount()
{
	int len = 0;
	ManagerNode* temp = Mn_Head;
	while (temp != NULL)
	{
		temp = temp->Next;
		len++;
	}
	return len;
}

//Calculates the Average of Row after reading file
double ManagerList::Calc_Avg(double Sum, int Size)
{
	Average = Sum / Size;
	return Average;
}

//Calculates Average When some Nodes are Deleted
void ManagerList::CalculateAvg(int Index)
{
	ManagerNode* Node = BringManagerAdress(Index);

	if (Node == NULL)
		return;

	double total = 0.0;
	int cur = Node->List->CountNodeAmount();	

	if (cur <= 0)
	{			
			DeleteManagerNode(Node);
			Size++;
	}
	else
	{
		for (int i = 0; i < cur; i++)
		{
			total += Node->List->GetNumData(i);
		}

		Node->AVRG = total / cur;
		AddToListAccordingly(Node->List, Node->AVRG);
		DeleteManagerNode(Node);
	}
}

//Delete the whole Node
void ManagerList::DeleteTheNode(int Index)
{
	ManagerNode* Node = BringManagerAdress(Index);
	DeleteManagerNode(Node);
}

//Delete ManagerNode when ever we Delete to get updated
void ManagerList::DeleteManagerNode(ManagerNode* Head)
{
	ManagerNode* ND = Head;
	int NodeAmount = GetNodeAmount();

	if (ND != NULL)
	{
		ManagerNode* Prev = ND->Prev;
		ManagerNode* Next = ND->Next;

		if (Next != NULL)
			Next->Prev = Prev;

		if (Prev != NULL )
			Prev->Next = Next;

		else
			Mn_Head = Next;

		delete ND;
	}
}

//Delete and Update
void ManagerList::DeleteAtElement()
{
	BringManagerAdress(this->Current)->List->DeleteTheNode(RandomNode);

	CalculateAvg(this->Current);

}

//Show Element to be Deleted
void ManagerList::ShowToBeDeleted(int Index)
{
	srand(time(NULL));

	int X = ((Current % NodePerPage) * 12) + 10;

	int Amount = BringManagerAdress(Current)->List->CountNodeAmount();
	if (Amount == 0) throw "No Element Found To Be Deleted";
	int random = rand() % Amount;
	RandomNode = random;
	int Y = (random * 6) + 14;

	gotoxy(X, Y);
	cout << "  <----To BE DELETED : Press K if to Delete  : ";
}
#pragma endregion


#pragma region PRINTING DATA FUNCTIONS

//Sets Up PrintRowList
void ManagerList::printRowListAtIndex(int x, int y)
{
	BringManagerAdress(this->Current)->List->PrintRowList(x, y);
}

//Controlls variable Upon changing page
void ManagerList::VariablesControll()
{
	int page = Current / (NodePerPage);
	Offset = NodePerPage * page;

	FinalOffSet = NodePerPage * (page + 1);

	if (FinalOffSet >= GetNodeAmount())
		FinalOffSet = GetNodeAmount();
	
}

//Prints The ManagerNode List
void ManagerList::PrintList()
{
		ManagerNode* node;
		node = BringManagerAdress(Offset);
		
		PrintAdress(node);
		PrintPrev(node);
		PrintAvg(node);
		PrintNext(node);	
		cout << endl;

		printRowListAtIndex((Current % NodePerPage) * 12, 10);
}

//Prints Adress of ManagerNode
void ManagerList::PrintAdress(ManagerNode * MD)
{
	int i;
	int remaining = this->FinalOffSet - this->Offset;
	

	gotoxy(0, 0);
	if (this->Offset == 0)
	{
		cout << " FIRST--> " << setw(83) << "---->" << endl << endl;
	}
	else if (this->FinalOffSet != GetNodeAmount())
	{
		gotoxy(0, 0);
		cout << "<-PREVIOUS" << setw(83) << "---->" << endl << endl;
	}

	if (this->FinalOffSet == GetNodeAmount())
	{
		cout << "<-PREVIOUS";
		gotoxy(remaining * 11, 0);
		cout << "LAST" << endl << endl;
	}

	for (i = 0 ; i < NodePerPage && MD != NULL; i++, MD = MD->Next)
	{			
			cout << " " << MD << "   ";
	}

	cout << endl;
	MakeLine(i);
}

//Prints Previous Adress of ManagerNode
void ManagerList::PrintPrev(ManagerNode* MD)
{
	int  i ;
	for (i = 0; i < NodePerPage && MD != NULL; i++, MD = MD->Next)
	{
		cout << "|" << setw(8) << MD->Prev << "|  ";
	}
	cout << endl;
	MakeLine(i);
}

//Prints Average of ManagerNode
void ManagerList::PrintAvg(ManagerNode* MD)
{
	int i ;

	for (i = 0; i < NodePerPage && MD != NULL; i++, MD = MD->Next)
	{
		cout << "|" << setw(8) << setprecision(3) << MD->AVRG << "|  ";
	}

	cout << endl;
	MakeLine(i);	
}

//Prints Next Adress of ManagerNode
void ManagerList::PrintNext(ManagerNode* MD)
{
	int i;
	for (  i = 0 ;i < NodePerPage && MD != NULL ; i++ , MD = MD->Next)
	{
		cout << "|" << setw(8) << MD->Next << "|  ";
	}
	cout << endl;
	MakeLine(i);
}

//Make Line to separate Datas
void ManagerList::MakeLine(int index)
{
	for (int i = 0; i < index; i++)
		cout << "----------  ";
	cout << endl;
}

//To Manipulate Console Positioning
void ManagerList::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

#pragma endregion

ManagerList::~ManagerList()
{
	ManagerNode* CurrNode = Mn_Head;
	ManagerNode* NextNode = NULL;


	while (CurrNode != NULL)
	{
		//Called From RowList class To delete Every last Element inside EveryRow
		CurrNode->List->~RowList();

		//saves the link to the Next Node
		NextNode = CurrNode->Next;
		//Delete The Current Node
		delete CurrNode;
		//Assign Current To the Next Node
		CurrNode = NextNode;

	}
}



