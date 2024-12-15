#include "../include/LinkedList.hpp"
#include "../include/queue.hpp"
#include <cmath>
#include <iomanip>
/*
bellek sızıntısı var mı bakılacak
yıkıcılar düzenlenecek */

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
void LinkedList::ikincidegerYaz(int deger)
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
    int visibleNodes = std::min(size - startIndex, maxCount); // Gösterilecek düğüm sayısı

    for (int i = 0; i < visibleNodes; i++)
    {
        cizgiYaz();
    }
}
void LinkedList::isaretYaz(int index, int startIndex)
{
    int localIndex = index - startIndex; // Görünüm başlangıcına göre işaret pozisyonu

    // İşaret için boşlukları yazdır
    for (int i = 0; i < localIndex; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << " ";
        }
        cout << "        ";
    }

    // İşaret çizgisi
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
    // Çizgi yazdır
    satirCiz(startIndex, maxCount);
    cout << endl;

    // Başlangıç indeksinden itibaren 10 düğümü yazdır
    for (int i = 0; i < maxCount; i++)
    {
        if (startIndex + i < size)
        {
            ilkdegerYaz(startIndex + i); // Düğümün ilk değerini yazdır
        }
        else
        {
            cout << setw(10) << " "; // Boşluk
        }
    }

    cout << endl;

    // Çizgi yazdır
    satirCiz(startIndex, maxCount);
    cout << endl;

    // Toplamları yazdır
    for (int i = 0; i < maxCount; i++)
    {
        if (startIndex + i < size)
        {
            toplaVeYaz(startIndex + i); // Düğüm toplamını yazdır
        }
        else
        {
            cout << setw(10) << " "; // Boşluk
        }
    }

    cout << endl;

    // Çizgi yazdır
    satirCiz(startIndex, maxCount);
    cout << endl;

    // Üçüncü değerleri yazdır
    for (int i = 0; i < maxCount; i++)
    {
        if (startIndex + i < size)
        {
            ucuncudegerYaz(startIndex + i); // Düğümün üçüncü değerini yazdır
        }
        else
        {
            cout << setw(10) << " "; // Boşluk
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

    int solToplam = tree->getLeftSum() * 2;
    int sagToplam = tree->getRightSum();
    int kokDeger = tree->getRoot()->data;

    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }

    cout << setw(10) << (solToplam + sagToplam + kokDeger);
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
        // İlk düğümü silme
        del = head;
        head = head->next; // Yeni baş düğüm
        if (size == 1)
        {
            last = head;
        }
    }
    else
    {
        // İlgili düğümü bulmak için önceki düğüme kadar ilerle
        ListNode *prv = getNodeAt(index - 1);
        del = prv->next;       // Silinecek düğüm
        prv->next = del->next; // Önceki düğümün bağlantısını güncelle
        if (del == last)
        {
            last = prv;
        }
    }

    // Silinecek düğümün dinamik belleğini temizle
    delete del->tree; // Özel veriyi (örneğin `BST`) temizle
    delete del;       // Düğümü sil

    size--; // Listedeki düğüm sayısını azalt
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

        cout << endl;
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
