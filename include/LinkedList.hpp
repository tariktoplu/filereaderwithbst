/**
 * @file                 LinkedList.hpp
 * @description          Tek yönlü bağlı liste yapısı için gerekli fonksiyonlar ve değişkenler tanımlandı
 * @course               2A
 * @assignment           2
 * @date                 08.12.2024
 * @author               Tarık Toplu tarikttoplu@gmail.com
 */
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "ListNode.hpp"

static const int GENISLIK = 100;
static const int YUKSEKLIK = 20;
class LinkedList
{
private:
    ListNode *head;
    ListNode *last;
    int size;

    void cizgiYaz();
    void ilkdegerYaz(int);
    void ucuncudegerYaz(int);
    void satirCiz(int, int);
    void toplaVeYaz(int);

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
