


#ifndef ROWLIST_HPP
#define ROWLIST_HPP

#include "RowNode.hpp"

class RowList
{
private:
	RowNode* Header;
	RowNode* AdressAt(int);

public:

	RowList(RowNode* Node, double Average);
	~RowList();
	RowNode* MakeRowList(int);
	int GetNumData(int);
	int CountNodeAmount();
	void PrintRowList(int, int);
	void DeleteTheNode(int);

};

#endif // ! DOUBLYLINKEDLIST_HPP 



