/**
 * @file                 ListNode.hpp
 * @description          Tek yönlü bağlı liste için gerekli olan düğüm yazıldı, BST tutabilmesi için BST* türüne ayarlandı
 * @course               2A
 * @assignment           2
 * @date                 08.12.2024
 * @author               Tarık Toplu tarikttoplu@gmail.com
 */
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
