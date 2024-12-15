#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "ListNode.hpp"
/* linkedList temel kodlar bitti */

class LinkedList
{
private:
    ListNode *head;
    ListNode *last;
    int size;

    void cizgiYaz();
    void ilkdegerYaz(int);
    void ikincidegerYaz(int);
    void ucuncudegerYaz(int);
    void satirCiz(int, int);
    void toplaVeYaz(int);
    void boslukYaz(int);
    void agacCizgiYaz(int);

public:
    LinkedList();
    ~LinkedList();

    void addNode(const BST &);
    bool isEmpty();
    void clear();
    void removeAt(int);
    int Size();
    ListNode *getNodeAt(int);
    void agacYaz(int);
    void bagliListeYaz(int);
    void isaretYaz(int, int);
};

#endif // LINKEDLIST_HPP
