/** 
* @file         Tissue.cpp
* @description  Contains Cells DNA Length and Perform Radix Sort
* @course       Veri yapilari 1c
* @assignment   2. Odev
* @date         23/12/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/

#include "Tissue.hpp"

Tissue::Tissue()
{
    this->LineSize = 0;
    this->CellsInTissue = NULL;
    cell = 0;
}
Tissue::~Tissue()
{
    delete[]cell;
    delete[] CellsInTissue;
}

void Tissue::InitializeCellObject(int linesize)
{
    this->LineSize = linesize;
    CellsInTissue = new int[linesize];
    cell = new Cell[LineSize];

}
void Tissue::InsetIntoTissue(int Cells, int itr)
{
    CellsInTissue[itr] = Cells;
    cell[itr].DNA_Length = Cells;
}
void Tissue::SortElementsInTissue()
{

    Radix* rd = new Radix(CellsInTissue, LineSize);

    CellsInTissue = rd->Sort();
}
int Tissue::GetMidElement()
{
    int MidPoint = (LineSize) / 2;
    for (int i = 0; i < LineSize; i++)
    {
        if (i == MidPoint)
        {
            return CellsInTissue[i];
        }
    }
    return -1;
}