/**
 * @file                 BSTNode.cpp
 * @description          BST düğümü için gerekli düğüm ve değişkenler tanımlandı
 * @course               2A
 * @assignment           2
 * @date                 08.12.2024
 * @author               Tarık Toplu tarikttoplu@gmail.com
 */

#include "../include/BSTNode.hpp"

// Node sınıfının constructor'ı
Node::Node(const char &dt, Node *lf, Node *rg, int level)
{
    data = dt;
    left = lf;
    right = rg;
    this->level = level;
}
