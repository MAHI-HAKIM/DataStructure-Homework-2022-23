#ifndef CONTROL_HPP
#define CONTROL_HPP
#include "TestProgram.hpp"
#include "Organism.hpp"
class Control
{
public:
	Control(Organism* , int);
	~Control();
	void PerformMutation();
	void PrintinControl();
private:
	int SystemSize;
	Organism* OrganismInControl;
};
#endif // !CONTROL_HPP
