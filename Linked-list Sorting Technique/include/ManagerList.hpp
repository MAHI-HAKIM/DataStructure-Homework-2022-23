#ifndef MANAGERLIST_HPP
#define MANAGERLIST_HPP
#include "ManagerNode.hpp"
#include "RowNode.hpp"

class ManagerList
{
public:

	ManagerList();
	~ManagerList();

	//Read and Add Funcitons
	void ReadFile();
	void VariablesControll();
	int GetNodeAmount();
	int Current;
	double Calc_Avg(double, int);
	void DeleteAtElement();
	void CalculateAvg(int);
	void DeleteManagerNode(ManagerNode*);
	void DeleteTheNode(int);


	//Display Functions
	void printRowListAtIndex(int, int);
	void PrintList();
	void PrintAdress(ManagerNode*);
	void PrintPrev(ManagerNode*);
	void PrintAvg(ManagerNode*);
	void PrintNext(ManagerNode*);
	void MakeLine(int);
	void gotoxy(int x, int y);
	void ShowToBeDeleted(int);

private:
	ManagerNode* AddToListAccordingly(RowList* Head, double Average);
	ManagerNode* BringManagerAdress(int Index);
	ManagerNode* Mn_Head;
	RowNode* RowListHeader;

	int Size;
	int Offset;
	int FinalOffSet;
	int RandomNode;
	int NodePerPage;
	double Average;
};

#endif // !ManagerList


