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
        cout << " ";
    }
    cout << "..........";
}
void LinkedList::ilkdegerYaz(int deger)
{

    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }

    ListNode *dugum = getNodeAt(deger);

    cout << setw(10) << dugum;
}
void LinkedList::ucuncudegerYaz(int deger)
{

    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }

    ListNode *dugum = getNodeAt(deger);

    cout << setw(10) << dugum->next;
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
            cout << " ";
        }
        cout << "        ";
    }

    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }
    cout << "^^^^^^^^^^";
    cout << endl;
}
void LinkedList::bagliListeYaz(int startIndex)
{
    int maxCount = 10;

    satirCiz(startIndex, maxCount);
    cout << endl;

    for (int i = 0; i < maxCount; i++)
    {
        if (startIndex + i < size)
        {
            ilkdegerYaz(startIndex + i);
        }
        else
        {
            cout << setw(10) << " ";
        }
    }

    cout << endl;

    satirCiz(startIndex, maxCount);
    cout << endl;

    for (int i = 0; i < maxCount; i++)
    {
        if (startIndex + i < size)
        {
            toplaVeYaz(startIndex + i);
        }
        else
        {
            cout << setw(10) << " ";
        }
    }

    cout << endl;

    satirCiz(startIndex, maxCount);
    cout << endl;

    for (int i = 0; i < maxCount; i++)
    {
        if (startIndex + i < size)
        {
            ucuncudegerYaz(startIndex + i);
        }
        else
        {
            cout << setw(10) << " ";
        }
    }

    cout << endl;

    // Çizgi yazdır
    satirCiz(startIndex, maxCount);
    cout << endl;
}
void LinkedList::toplaVeYaz(int index)
{
    ListNode *currentNode = getNodeAt(index);
    BST *tree = currentNode->tree;

    cout << setw(15) << tree->toplam(tree->getRoot()) + tree->getRoot()->data;
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
void LinkedList::agacYaz(int index)
{
    ListNode *currentNode = getNodeAt(index);

    BST *tree = currentNode->tree;

    if (tree->getRoot() == nullptr)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    int height = tree->Height(tree->getRoot());
    Queue q;
    q.enqueue(tree->getRoot());

    for (int level = 0; level <= height; level++)
    {
        int nodesAtCurrentLevel = pow(2, level);
        int spacesBefore = pow(2, height - level + 1) - 1;
        int spacesBetween = pow(2, height - level + 2) - 1;

        // Yazdırma için başlangıç boşluğu
        for (int i = 0; i < spacesBefore; i++)
        {
            cout << " ";
        }

        for (int i = 0; i < nodesAtCurrentLevel; i++)
        {
            if (!q.isEmpty())
            {
                Node *current = q.dequeue();
                if (current != nullptr)
                {

                    cout << current->data;
                    q.enqueue(current->left);
                    q.enqueue(current->right);
                }
                else
                {
                    cout << " ";
                    q.enqueue(nullptr);
                    q.enqueue(nullptr);
                }
            }
            else
            {
                cout << " ";
            }

            // İki düğüm arasındaki boşluk
            if (i < nodesAtCurrentLevel - 1)
            {
                for (int j = 0; j < spacesBetween; j++)
                {
                    cout << " ";
                }
            }
        }
        cout << endl
             << endl
             << endl;
    }
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
