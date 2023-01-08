/** 
* @file         Organ.cpp
* @description  Organ that Contains a BST 
* @course       Veri yapilari 1c
* @assignment   2. Odev
* @date         23/12/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/


#include "Organ.hpp"

Organ::Organ()
{
    TissueInOrgan = new Tissue[20];
    trees = new BST();
}

Organ::~Organ()
{
    delete trees;
    delete[]TissueInOrgan;
}

void Organ::InitializeTissue(Tissue* tissue)
{
    for (int i = 0; i < 20; i++)
    {
        TissueInOrgan[i] = tissue[i];
    }
}