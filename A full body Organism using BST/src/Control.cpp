/** 
* @file         Control.cpp
* @description  Contains Function To Check If Cell Should Mutate
* @course       Veri yapilari 1c
* @assignment   2. Odev
* @date         23/12/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/

#include "Control.hpp"

Control::Control(Organism * organism , int systemsize)
{
	this->SystemSize = systemsize;
	this->OrganismInControl = organism;
}
Control::~Control()
{
	delete OrganismInControl;
}

void Control::PerformMutation()
{
	for (int i = 0; i < SystemSize; i++)
	{
		for (int h = 0; h < 100; h++)
		{
			if (OrganismInControl->SystemsInOrganism[i].OrgansInSystem[h].trees->Root->Data % 50 == 0)
			{
				for (int t = 0; t < 20; t++)
				{
					for (int l = 0; l < OrganismInControl->SystemsInOrganism[i].OrgansInSystem[h].TissueInOrgan[t].LineSize; l++)
					{
						int* newarray = OrganismInControl->SystemsInOrganism[i].OrgansInSystem[h].TissueInOrgan->CellsInTissue;
					    if (OrganismInControl->SystemsInOrganism[i].OrgansInSystem[h].TissueInOrgan[t].CellsInTissue[l] % 2 == 0)
					    {
							int ToBeDividend = OrganismInControl->SystemsInOrganism[i].OrgansInSystem[h].TissueInOrgan[t].CellsInTissue[l];
							OrganismInControl->SystemsInOrganism[i].OrgansInSystem[h].TissueInOrgan[t].CellsInTissue[l] = ToBeDividend / 2;
					    }
					}
					OrganismInControl->SystemsInOrganism[i].OrgansInSystem[h].TissueInOrgan[t].SortElementsInTissue();
					OrganismInControl->SystemsInOrganism[i].OrgansInSystem[h].trees->Insert(OrganismInControl->SystemsInOrganism[i].OrgansInSystem[h].TissueInOrgan[t].GetMidElement());
				}
			}
		
		}
	}
}

void Control::PrintinControl()
{
	cout << setw(40) << "ORGANISM-(MUTATED FORM)\n " << endl;

	for (int i = 0; i < SystemSize; i++)
	{
		OrganismInControl->SystemsInOrganism[i].print();
		cout << endl;
	}
}