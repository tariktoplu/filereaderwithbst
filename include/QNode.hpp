/**
 * @file                 QNode.hpp
 * @description          Queue yapısı için gerekli düğüm tanımlanıp veri olarak BST düğümü tutuldu
 * @course               2A
 * @assignment           2
 * @date                 08.12.2024
 * @author               Tarık Toplu tarikttoplu@gmail.com
 */
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

    QNode(Node *item, QNode *next = nullptr);
};

#endif // QNODE_HPP