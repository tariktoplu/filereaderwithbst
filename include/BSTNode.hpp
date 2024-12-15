#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include <iostream>
#include <cmath>

class Node
{
public:
    char data;
    Node *left;
    Node *right;
    int level;

    Node(const char &dt, Node *lf = NULL, Node *rg = NULL, int level = 0)
    {
        data = dt;
        left = lf;
        right = rg;
        level = level;
    }
};

#endif
