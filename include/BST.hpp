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
    void inorder(Node *);

    void preorder(Node *);
    void postorder(Node *);

    void PrintLevel(Node *, int);
    bool Search(Node *subNode, const char &);

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
    void inorder();
    void preorder();
    void postorder();
    void levelorder();
    int returnLevel(Node *, int);
    int Height();
    bool Search(const char &);
    void printTree();
    void printTreeHelper(Node *, int);
    void Clear();
    ~BST();
    Node *getRoot() const;
    void enqueueLevelOrder(Queue &);
};

#endif