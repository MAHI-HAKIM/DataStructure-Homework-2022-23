#ifndef ORGANISM_HPP
#define ORGANISM_HPP

#include"System.hpp"

class Organism
{
public:
	Organism();
	~Organism();
	System* SystemsInOrganism;
	void PerformMutation(System* , int);
	void PrintOrganism();
private:
	int SystemSize;
};

#endif //!ORGANISM_HPP