/**
 * @file                 LinkedList.cpp
 * @description          LinkedListin fonksiyonları yazıldı. Düğüm ve ağaç yazma burada yapılır
 * @course               2A
 * @assignment           2
 * @date                 08.12.2024
 * @author               Tarık Toplu tarikttoplu@gmail.com
 */
#include "../include/LinkedList.hpp"
#include "Queue.cpp"
#include <cmath>
#include <iomanip>
#include <iostream>

/* static const int GENISLIK = 100;
static const int YUKSEKLIK = 20; */

LinkedList::LinkedList() : head(nullptr), last(head), size(0) {}

LinkedList::~LinkedList() { clear(); }

int LinkedList::Size()
{
    return size;
}

void LinkedList::cizgiYaz()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << " ";
    }
    std::cout << "..........";
}

void LinkedList::ilkdegerYaz(int deger)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << " ";
    }

    ListNode *dugum = getNodeAt(deger);
    std::cout << std::setw(10) << dugum;
}

void LinkedList::ucuncudegerYaz(int deger)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << " ";
    }

    ListNode *dugum = getNodeAt(deger);
    std::cout << std::setw(10) << dugum->next;
}

void LinkedList::satirCiz(int startIndex, int maxCount)
{
    int visibleNodes = std::min(size - startIndex, maxCount);

    for (int i = 0; i < visibleNodes; i++)
    {
        cizgiYaz();
    }
}

void LinkedList::isaretYaz(int index, int startIndex)
{
    int localIndex = index - startIndex;

    for (int i = 0; i < localIndex; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            std::cout << " ";
        }
        std::cout << "        ";
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << " ";
    }
    std::cout << "^^^^^^^^^^";
    std::cout << std::endl;
}

void LinkedList::bagliListeYaz(int startIndex)
{
    int maxCount = 10;

    satirCiz(startIndex, maxCount);
    std::cout << std::endl;

    for (int i = 0; i < maxCount; i++)
    {
        if (startIndex + i < size)
        {
            ilkdegerYaz(startIndex + i);
        }
        else
        {
            std::cout << std::setw(10) << " ";
        }
    }

    std::cout << std::endl;

    satirCiz(startIndex, maxCount);
    std::cout << std::endl;

    for (int i = 0; i < maxCount; i++)
    {
        if (startIndex + i < size)
        {
            toplaVeYaz(startIndex + i);
        }
        else
        {
            std::cout << std::setw(10) << " ";
        }
    }

    std::cout << std::endl;

    satirCiz(startIndex, maxCount);
    std::cout << std::endl;

    for (int i = 0; i < maxCount; i++)
    {
        if (startIndex + i < size)
        {
            ucuncudegerYaz(startIndex + i);
        }
        else
        {
            std::cout << std::setw(10) << " ";
        }
    }

    std::cout << std::endl;

    // Çizgi yazdır
    satirCiz(startIndex, maxCount);
    std::cout << std::endl;
}

void LinkedList::toplaVeYaz(int index)
{
    ListNode *currentNode = getNodeAt(index);
    BST *tree = currentNode->tree;

    std::cout << std::setw(15) << tree->toplam(tree->getRoot()) + tree->getRoot()->data;
}

void LinkedList::addNode(const BST &tree)
{
    BST *yeniAgac = new BST(tree);
    ListNode *yeniDugum = new ListNode(yeniAgac);

    if (size == 0)
    {
        head = yeniDugum;
        last = yeniDugum;
    }
    else
    {
        last->next = yeniDugum;
        last = last->next;
    }
    size++;
}

bool LinkedList::isEmpty()
{
    return size == 0;
}

void LinkedList::clear()
{
    while (!isEmpty())
    {
        removeAt(0);
    }
}

void LinkedList::removeAt(int index)
{
    ListNode *del = nullptr;

    if (index == 0)
    {
        del = head;
        head = head->next;
        if (size == 1)
        {
            last = head;
        }
    }
    else
    {
        ListNode *prv = getNodeAt(index - 1);
        del = prv->next;
        prv->next = del->next;
        if (del == last)
        {
            last = prv;
        }
    }

    delete del->tree;
    delete del;

    size--;
}

void ekraniTemizle(char ekran[YUKSEKLIK][GENISLIK])
{
    for (int i = 0; i < YUKSEKLIK; i++)
    {
        for (int j = 0; j < GENISLIK; j++)
        {
            ekran[i][j] = ' ';
        }
    }
}

void ekraniYazdir(char ekran[YUKSEKLIK][GENISLIK])
{
    for (int i = 0; i < YUKSEKLIK; i++)
    {
        for (int j = 0; j < GENISLIK; j++)
        {
            std::cout << ekran[i][j];
        }
        std::cout << std::endl;
    }
}

void dalEkle(char ekran[YUKSEKLIK][GENISLIK], int baslangicSatir, int baslangicSutun, int bitisSatir, int bitisSutun)
{
    int farkSatir = abs(bitisSatir - baslangicSatir);
    int farkSutun = abs(bitisSutun - baslangicSutun);
    int adimSayisi = std::max(farkSatir, farkSutun);

    for (int i = 0; i <= adimSayisi; i++)
    {
        int satir = baslangicSatir + (i * (bitisSatir - baslangicSatir)) / adimSayisi;
        int sutun = baslangicSutun + (i * (bitisSutun - baslangicSutun)) / adimSayisi;
        if (sutun >= 0 && sutun < GENISLIK && satir >= 0 && satir < YUKSEKLIK)
        {
            ekran[satir][sutun] = '-';
        }
    }
}

void agaciCiz(Node *root, char ekran[YUKSEKLIK][GENISLIK], int satir, int sutun, int bosluk)
{
    if (root == nullptr || satir >= YUKSEKLIK || sutun >= GENISLIK || sutun < 0)
    {
        return;
    }

    ekran[satir][sutun] = root->data;

    if (root->left != nullptr)
    {
        dalEkle(ekran, satir + 1, sutun, satir + 3, sutun - bosluk);
        agaciCiz(root->left, ekran, satir + 3, sutun - bosluk, bosluk / 2);
    }

    if (root->right != nullptr)
    {
        dalEkle(ekran, satir + 1, sutun, satir + 3, sutun + bosluk);
        agaciCiz(root->right, ekran, satir + 3, sutun + bosluk, bosluk / 2);
    }
}

void LinkedList::agacYaz(int index)
{
    ListNode *currentNode = getNodeAt(index);
    BST *tree = currentNode->tree;

    if (tree->getRoot() == nullptr)
    {
        std::cout << "Tree is empty." << std::endl;
        return;
    }

    char ekran[YUKSEKLIK][GENISLIK];
    ekraniTemizle(ekran);
    agaciCiz(tree->getRoot(), ekran, 0, GENISLIK / 2, GENISLIK / 4);
    ekraniYazdir(ekran);
}

ListNode *LinkedList::getNodeAt(int index)
{
    if (index < 0 || index >= size)
    {
        throw "Index out of range";
    }

    ListNode *temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp;
}