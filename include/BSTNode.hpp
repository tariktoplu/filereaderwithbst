/**
 * @file                 BSTNode.hpp
 * @description          BST düğümü için gerekli düğüm ve değişkenler tanımlandı
 * @course               2A
 * @assignment           2
 * @date                 08.12.2024
 * @author               Tarık Toplu tarikttoplu@gmail.com
 */
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

    Node(const char &dt, Node *lf = NULL, Node *rg = NULL, int level = 0);
};

#endif
