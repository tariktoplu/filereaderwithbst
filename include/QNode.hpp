#ifndef QNODE_HPP
#define QNODE_HPP
#include <iostream>
using namespace std;
#include "BSTNode.hpp"

class QNode
{
public:
    Node *item;
    QNode *next;

    QNode(Node *item, QNode *next = nullptr)
    {
        this->item = item;
        this->next = next;
    }
};

#endif