/** 
* @file         System.cpp
* @description  Contain Organs and Check if they are Balance
* @course       Veri yapilari 1c
* @assignment   2. Odev
* @date         23/12/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/

#include "System.hpp"

System::System()
{
	OrgansInSystem = new Organ[100];
}
System::~System()
{
	delete[] OrgansInSystem;
}
void System::InsertOrganIntoSystem(Organ *Ogr)
{
	for (int i = 0; i < 100; i++)
	{
		OrgansInSystem[i] = Ogr[i];
	}
}
void System::print()
{
		for (int i = 0; i < 100; i++)
		{
			OrgansInSystem[i].trees->IsBalanced();
		}
}