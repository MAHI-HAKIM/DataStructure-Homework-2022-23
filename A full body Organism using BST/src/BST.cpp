/** 
* @file         BST.cpp
* @description  Contains Function To Add into BST and Check Balance of BST
* @course       Veri yapilari 1c
* @assignment   2. Odev
* @date         23/12/2022
* @author       Mahi Abdulhakim Mohammed -> mahi.mohammed@ogr.sakarya.edu.tr
*/

#include "BST.hpp"

BST::BST()
{
    ElementSize = 0;
    Root = nullptr;
}
BST::~BST()
{
    DestroyTree();
}
void BST::DestroyTree(Node* Active)
{
    if (Active)
    {

        DestroyTree(Active->Lchild);
        DestroyTree(Active->Rchild);
        delete Active;
        ElementSize--;
    }
}
void BST::DestroyTree()
{
    return DestroyTree(Root);
}

void BST::Insert(int ToBeInserted)
{
    if (Root == 0)
    {
            Root = new Node(ToBeInserted);
            ElementSize++;        
    }
    else
    {
        Insert(ToBeInserted, Root);
        ElementSize++;
    }
}
void BST::Insert(int Data, Node* ActiveNode)
{
    if (ActiveNode->Data > Data)
    {
        if (ActiveNode->Lchild)
            Insert(Data, ActiveNode->Lchild);
        else
            ActiveNode->Lchild = new Node(Data);
    }
    else if (ActiveNode->Data < Data)
    {
        if (ActiveNode->Rchild)
            Insert(Data, ActiveNode->Rchild);
        else
            ActiveNode->Rchild = new Node(Data);
    }
    else if (ActiveNode->Data == Data)
    {
        if (ActiveNode->Lchild)
            Insert(Data, ActiveNode->Lchild);
        else
            ActiveNode->Lchild = new Node(Data);
    }
    else
        return;
}

int BST::Height()
{
    return Height(Root);
}
int BST::Height(Node* root)
{
    if (root == NULL) return 0; // Height of 0.

    // Check if left is balanaced
    int leftChildHeight = Height(root->Lchild);
    if (leftChildHeight == -1) return -1; // Not Balanced

    // Check if right is balanaced
    int rightChildHeight = Height(root->Rchild);
    if (rightChildHeight == -1) return -1; // Not Balanced

    // Check if current node is balanced
    int heightDifference = leftChildHeight - rightChildHeight;

    if (abs(heightDifference) > 1)
        return -1; // not balanaced
    else
        return max(leftChildHeight, rightChildHeight) + 1; // Return Height
}
bool BST::IsBalanced()
{
    return IsBalanced(Root);
}
bool BST::IsBalanced(Node* root)
{
    if (Height(root) == -1)
    {
        cout << "#";
        return false;
    }
    else
    {
        cout << " ";
        return true;
    }
}