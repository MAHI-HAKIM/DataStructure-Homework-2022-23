/**
* @file         Rowlist.cpp
* @description  ManagerNode class Implementaion
* @course       Veri yapilari 1C
* @assignment   1. Odev
* @date         27/11/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/

#include "ManagerNode.hpp"

ManagerNode::ManagerNode(RowList* list , double Avg )
{
	this->List = list;
	this->AVRG = Avg;
	Next = NULL;
	Prev = NULL;
}