/** 
* @file         Node.cpp
* @description  Single Linked List Node to Use for Creating BST
* @course       Veri yapilari 1c
* @assignment   2. Odev
* @date         23/12/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/


#include "Node.hpp"

Node::Node(int Data)
{
    this->Data = Data;
    Lchild = Rchild = NULL;
    HeightLevel = 0;
}