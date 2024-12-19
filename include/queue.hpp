/**
 * @file                 Queue.hpp
 * @description          Queue yapısı için gerekli fonksiyonlar ve değişkenler tanımlandı
 * @course               2A
 * @assignment           2
 * @date                 08.12.2024
 * @author               Tarık Toplu tarikttoplu@gmail.com
 */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "QNode.hpp"
#include "BSTNode.hpp"

class Queue
{
private:
    QNode *front;
    QNode *back;
    int length;

public:
    Queue();
    bool isEmpty() const;
    void enqueue(Node *item);
    Node *dequeue();
    void clear();
    Node *showfront() const;
    ~Queue();
};

#endif
