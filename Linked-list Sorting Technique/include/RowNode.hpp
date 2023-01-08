#ifndef ROWNODE_HPP
#define ROWNODE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class RowNode
{
public:
	RowNode(int data);
	int Num;
	RowNode* Prev;
	RowNode* Next;
};

#endif // !NODE_HPP
