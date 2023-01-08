#ifndef TISSUE_HPP
#define TISSUE_HPP

#include "Cell.hpp"
#include "Radix.hpp"

class Tissue
{
public:
	Tissue();
	~Tissue();

	void InitializeCellObject(int);
	void InsetIntoTissue(int,int);
	int GetMidElement();
	void SortElementsInTissue();

	Cell* cell;

	int* CellsInTissue;
	int LineSize;
};
#endif // !TISSUE_HPP
