#include "BST.hpp"
BST::BST(const BST &copyItem)
{
    root = nullptr;
    size = copyItem.size;

    root = CopyTree(copyItem.root);
}
Node *BST::getRoot() const
{
    return root;
}
Node *BST::CopyTree(Node *subNode)
{
    if (subNode == nullptr)
        return nullptr;

    Node *newNode = new Node(subNode->data);
    newNode->left = CopyTree(subNode->left);
    newNode->right = CopyTree(subNode->right);

    return newNode;
}
void BST::SearchAndAdd(Node *&subNode, const char &newItem, int level)
{
    if (subNode == NULL)
    {
        subNode = new Node(newItem);
        subNode->level = level;
    }
    else if (newItem < subNode->data)
        SearchAndAdd(subNode->left, newItem, level + 1);
    else if (newItem > subNode->data)
        SearchAndAdd(subNode->right, newItem, level + 1);
    else
        return;
}
int BST::hesaplaToplam(Node *root)
{

    if (root == nullptr)
    {
        return 0;
    }

    int solDeger = hesaplaToplam(root->left) * 2;

    int sagDeger = hesaplaToplam(root->right);

    return (int)root->data + solDeger + sagDeger;
}
int BST::getLeftSum(Node *subNode)
{
    if (subNode == nullptr)
        return 0;
    return getLeftSum(subNode->left) + getLeftSum(subNode->right) + subNode->data;
}

int BST::getRightSum(Node *subNode)
{
    if (subNode == nullptr)
        return 0;
    return getRightSum(subNode->left) + getRightSum(subNode->right) + subNode->data;
}

int BST::getLeftSum()
{
    return getLeftSum(root);
}

int BST::getRightSum()
{
    return getRightSum(root);
}
bool BST::SearchAndDelete(Node *&subNode, const char &data)
{
    if (subNode == NULL)
        return false;
    if (subNode->data == data)
    {
        if (DeleteNode(subNode))
        {
            size--;
            return true;
        }
        return false;
    }
    else if (data < subNode->data)
        return SearchAndDelete(subNode->left, data);
    else
        return SearchAndDelete(subNode->right, data);
}
void BST::mirror(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    mirror(root->left);
    mirror(root->right);

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void BST::mirror()
{
    mirror(root);
}
void BST::enqueueLevelOrder(Queue &q)
{
    if (root == nullptr)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    Queue tempQueue;
    tempQueue.enqueue(root);

    while (!tempQueue.isEmpty())
    {
        Node *current = tempQueue.dequeue();

        q.enqueue(current);

        if (current->left != nullptr)
        {
            tempQueue.enqueue(current->left);
        }

        if (current->right != nullptr)
        {
            tempQueue.enqueue(current->right);
        }
    }
}

bool BST::DeleteNode(Node *&subNode)
{
    Node *DelNode = subNode;

    if (subNode->right == NULL)
        subNode = subNode->left;
    else if (subNode->left == NULL)
        subNode = subNode->right;
    else
    {
        DelNode = subNode->left;
        Node *parent = subNode;
        while (DelNode->right != NULL)
        {
            parent = DelNode;
            DelNode = DelNode->right;
        }
        subNode->data = DelNode->data;
        if (parent == subNode)
            subNode->left = DelNode->left;
        else
            parent->right = DelNode->left;
    }
    delete DelNode;
    return true;
}
int BST::Height(Node *subNode)
{
    if (subNode == NULL)
        return -1;
    return 1 + max(Height(subNode->left), Height(subNode->right));
}
void BST::PrintLevel(Node *subNode, int level)
{
    if (subNode == NULL)
        return;
    if (level == 0)
        cout << subNode->data << " ";
    else
    {
        PrintLevel(subNode->left, level - 1);
        PrintLevel(subNode->right, level - 1);
    }
}
BST::BST()
{
    root = NULL;
}
bool BST::isEmpty() const
{
    return root == NULL;
}
void BST::Add(const char &newItem)
{
    SearchAndAdd(root, newItem, 0);
    size++;
}
void BST::Delete(const char &data)
{
    if (SearchAndDelete(root, data) == false)
        throw "Item not found.";
}
void BST::levelorder()
{
    int h = Height();
    for (int level = 0; level <= h; level++)
    {
        PrintLevel(root, level);
    }
}
int BST::Height()
{
    return Height(root);
}
void BST::Clear()
{
    while (!isEmpty())
        DeleteNode(root);
}
BST::~BST()
{
    Clear();
}