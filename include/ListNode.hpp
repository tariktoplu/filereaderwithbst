#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include "BST.hpp"

class ListNode
{
public:
    BST *tree;
    ListNode *next;

    // Constructor
    ListNode(BST *tree = nullptr, ListNode *next = NULL);
};

#endif // LISTNODE_HPP
