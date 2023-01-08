#ifndef MANAGERNODE_HPP 
#define MANAGERNODE_HPP

#include "RowList.hpp"

class ManagerNode
{

public:
	double AVRG;
	ManagerNode(RowList* list , double Avg);
	RowList* List;
	ManagerNode* Prev;
	ManagerNode* Next;

};

#endif // !managernode_hpp

