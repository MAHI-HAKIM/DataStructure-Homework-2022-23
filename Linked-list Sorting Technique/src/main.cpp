/**
* @file         Main.cpp
* @description  Contains the Main Function
* @course       Veri yapilari 1C
* @assignment   1. Odev
* @date         27/11/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/


#include "ManagerList.hpp"
#include "RowNode.hpp"

int main()
{
	ManagerList* Mnglist = new ManagerList();

	Mnglist->ReadFile();

	char operation = 0;
	
	
	while(true)
	{
		system("CLS");

		Mnglist->PrintList();

		cin >> operation;

		if (operation == 'z' || operation == 'Z')
		{
			if (Mnglist->Current != 0)
			{
				Mnglist->Current--;
				Mnglist->VariablesControll();
			}		
		}
		else if (operation == 'c' || operation == 'C')
		{
			if (Mnglist->Current < Mnglist->GetNodeAmount() - 1)
			{
				Mnglist->Current++;
				Mnglist->VariablesControll();
			}
			Mnglist->VariablesControll();
		}
		else if (operation == 'a' || operation == 'A')
		{
			if ((Mnglist->Current)-8 >= 0)
			{
				Mnglist->Current -= 8;
				Mnglist->VariablesControll();
			}
		}
		else if (operation == 'd' || operation == 'D')
		{
			if ((Mnglist->Current)+8 < Mnglist->GetNodeAmount() - 1)
			{
				Mnglist->Current += 8;
				Mnglist->VariablesControll();
			}
		}
		else if (operation == 'k' || operation == 'K')
		{
			Mnglist->ShowToBeDeleted(Mnglist->Current);
			cin >> operation;

			if (operation == 'k' || operation == 'K')
			{
				Mnglist->DeleteAtElement();
			}
		}
		else if (operation == 'p' || operation == 'P')
		{
			Mnglist->DeleteTheNode(Mnglist->Current);

		}
		else if (operation == 'q' || operation == 'Q')
		{
			break;
		}
	}

	//Freed the Object Created upon ManagerList
	delete Mnglist;
		return 0;

}
	