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
    Queue()
    {
        front = back = NULL;
        length = 0;
    }
    int getSize()
    {
        return length;
    }

    int count() const
    {
        return length;
    }

    bool isEmpty() const
    {
        return length == 0;
    }

    void enqueue(Node *item)
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

    Node *dequeue()
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

    void clear()
    {
        while (!isEmpty())
            dequeue();
    }

    ~Queue()
    {
        clear();
    }
};

#endif