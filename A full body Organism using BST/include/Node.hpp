#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include<iomanip>
using namespace std;

class Node
{
public:
    Node(int Data);
    int Data;
    Node* Lchild;
    Node* Rchild;
    int HeightLevel;
};

#endif // !BSTNODE_HPP
