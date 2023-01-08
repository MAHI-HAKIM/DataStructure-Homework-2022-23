#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#include "TestProgram.hpp"

class System
{
public:
	Organ* OrgansInSystem;
	System();
	~System();
	void InsertOrganIntoSystem(Organ*);
	void print();
};
#endif // !SYSTEM_HPP
