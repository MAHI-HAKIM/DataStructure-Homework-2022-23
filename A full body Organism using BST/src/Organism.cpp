/** 
* @file         Organism.cpp
* @description  A to build and Print a full Operated Organism
* @course       Veri yapilari 1c
* @assignment   2. Odev
* @date         23/12/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/

#include"Organism.hpp"

Organism::Organism()
{
	this->SystemsInOrganism = nullptr;
	this->SystemSize = 0;
}
Organism::~Organism()
{
	delete[] SystemsInOrganism;
}
void Organism::PerformMutation(System* system,int systemsize)
{
	this->SystemSize = systemsize;

	SystemsInOrganism = new System[SystemSize];

	for (int i = 0; i < SystemSize; i++)
	{
		SystemsInOrganism[i] = system[i];
	}
}
void Organism::PrintOrganism()
{
	cout << setw(30) << "ORGANISM\n " << endl;

	for (int i = 0; i < SystemSize ; i++)
	{
		SystemsInOrganism[i].print();
		cout << endl;
	}
}