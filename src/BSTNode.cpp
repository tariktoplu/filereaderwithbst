#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include <iostream>
#include <cmath>

class BSTNode
{
public:
    char data;
    BSTNode *left;
    BSTNode *right;
    int level;

    BSTNode(const char &dt, BSTNode *lf = NULL, BSTNode *rg = NULL, int level = 0)
    {
        data = dt;
        left = lf;
        right = rg;
        level = level;
    }
};

#endif
