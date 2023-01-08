/**
* @file         RowNode.cpp
* @description  Implemantation of RowNOde Class
* @course       Veri yapilari 1C
* @assignment   1. Odev
* @date         27/11/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/

#include "RowNode.hpp"

RowNode::RowNode(int Data)
{
	this->Num = Data;
	Next = NULL;
	Prev = NULL;

}