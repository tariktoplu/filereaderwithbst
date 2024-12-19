/**
 * @file                 Queue.cpp
 * @description          Queue yapısı için gerekli fonksiyonların içeriği yazıldı
 * @course               2A
 * @assignment           2
 * @date                 08.12.2024
 * @author               Tarık Toplu tarikttoplu@gmail.com
 */
#include "Queue.hpp"

Queue::Queue()
{
    front = back = NULL;
    length = 0;
}

bool Queue::isEmpty() const
{
    return length == 0;
}
Node *Queue::showfront() const
{
    if (isEmpty())
        throw "Queue is Empty"; // Kuyruk boşsa hata fırlat
    return front->item;         // Kuyruğun önündeki öğeyi döndür
}
void Queue::enqueue(Node *item)
{
    QNode *last = new QNode(item);
    if (isEmpty())
        front = back = last;
    else
    {
        back->next = last;
        back = back->next;
    }
    length++;
}

Node *Queue::dequeue()
{
    if (isEmpty())
        throw "Queue is Empty";
    QNode *tmp = front;
    Node *item = front->item;
    front = front->next;
    delete tmp;
    length--;
    return item;
}

void Queue::clear()
{
    while (!isEmpty())
        dequeue();
}

Queue::~Queue()
{
    clear();
}
