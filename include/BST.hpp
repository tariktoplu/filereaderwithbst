/**
 * @file                 BST.hpp
 * @description          BST yapısı için gerekli fonksiyonlar ve değişkenler tanımlandı
 * @course               2A
 * @assignment           2
 * @date                 08.12.2024
 * @author               Tarık Toplu tarikttoplu@gmail.com
 */
#ifndef BST_HPP
#define BST_HPP

#include "BSTNode.hpp"

#include "queue.hpp"
using namespace std;

class BST
{
private:
    Node *root;
    int size;

    void SearchAndAdd(Node *&, const char &, int);
    bool SearchAndDelete(Node *&, const char &);
    bool DeleteNode(Node *&);
    void PrintLevel(Node *, int);

public:
    int Height(Node *);
    BST();
    BST(const BST &);
    Node *CopyTree(Node *);
    void mirror(Node *root);
    int hesaplaToplam(Node *);
    int getLeftSum(Node *);
    void mirror();
    int getRightSum(Node *);
    int getLeftSum();
    int getRightSum();
    bool isEmpty() const;
    void Add(const char &);
    void Delete(const char &);

    void levelorder();
    int Height();
    void Clear();
    ~BST();
    Node *getRoot() const;
    void enqueueLevelOrder(Queue &);
};

#endif