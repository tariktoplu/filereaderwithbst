/**
 * @file                 ListNode.cpp
 * @description          ListNode yapısının kurucusu yazıldı
 * @course               2A
 * @assignment           2
 * @date                 08.12.2024
 * @author               Tarık Toplu tarikttoplu@gmail.com
 */
#include "../include/ListNode.hpp"

// Constructor
ListNode::ListNode(BST *tree, ListNode *next)
{
    this->tree = tree;
    this->next = next;
}
