/**
 * @file                 QNode.cpp
 * @description          Queue yapısı için gerekli düğüm tanımlanıp veri olarak BST düğümü
 * @course               2A
 * @assignment           2
 * @date                 08.12.2024
 * @author               Tarık Toplu tarikttoplu@gmail.com
 */

#include "QNode.hpp" // Başlık dosyasını dahil ediyoruz

// Constructor implementasyonu
QNode::QNode(Node *item, QNode *next)
{
    this->item = item;
    this->next = next;
}
