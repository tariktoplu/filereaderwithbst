#include "BST.hpp"
BST::BST(const BST &copyItem)
{
    root = nullptr;       // Yeni ağacın kökü başlangıçta boş
    size = copyItem.size; // Kopyalanacak ağacın boyutunu aktar

    // Yardımcı bir fonksiyonla diğer ağacın düğümlerini kopyala
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

    // Yeni bir düğüm oluştur ve sol/sağ alt ağaçları kopyala
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
        subNode->level = level; // Düğüm seviyesini ayarla
    }
    else if (newItem < subNode->data)
        SearchAndAdd(subNode->left, newItem, level + 1); // Sol alt ağaç için seviye artır
    else if (newItem > subNode->data)
        SearchAndAdd(subNode->right, newItem, level + 1); // Sağ alt ağaç için seviye artır
    else
        return;
}
int BST::hesaplaToplam(Node *root)
{

    if (root == nullptr)
    {
        return 0; // Boş düğümün katkısı yoktur
    }

    // Sol çocuk için değer hesaplama
    int solDeger = hesaplaToplam(root->left) * 2;

    // Sağ çocuk için değer hesaplama
    int sagDeger = hesaplaToplam(root->right);

    // ASCII değeri alınarak toplam hesaplanır
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
        if (DeleteNode(subNode)) // DeleteNode başarılı bir şekilde düğümü sildiyse
        {
            size--; // Düğüm silindiğinde boyutu azalt
            return true;
        }
        return false; // Silme işlemi başarısızsa
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

    // Sol ve sağ alt ağaçları aynalayın
    mirror(root->left);
    mirror(root->right);

    // Sol ve sağ alt ağaçların yerlerini değiştirin
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void BST::mirror()
{
    mirror(root); // Root ile başla
}
void BST::enqueueLevelOrder(Queue &q)
{
    if (root == nullptr)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    Queue tempQueue;
    tempQueue.enqueue(root); // Root düğümle başla

    while (!tempQueue.isEmpty())
    {
        Node *current = tempQueue.dequeue();

        // Mevcut düğümü verilen kuyruğa ekle
        q.enqueue(current);

        // Çocukları sırayla geçici kuyruğa ekle
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
void BST::inorder(Node *subNode)
{
    if (subNode != NULL)
    {
        inorder(subNode->left);
        cout << subNode->data << " ";
        inorder(subNode->right);
    }
}
void BST::preorder(Node *subNode)
{
    if (subNode != NULL)
    {
        cout << subNode->data << " ";
        preorder(subNode->left);
        preorder(subNode->right);
    }
}
void BST::postorder(Node *subNode)
{
    if (subNode != NULL)
    {
        postorder(subNode->left);
        postorder(subNode->right);
        cout << subNode->data << " ";
    }
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
int BST::returnLevel(Node *subNode, int level)
{
}

bool BST::Search(Node *subNode, const char &item)
{
    if (subNode == NULL)
        return false;
    if (subNode->data == item)
        return true;
    if (item < subNode->data)
        return Search(subNode->left, item);
    else
        return Search(subNode->right, item);
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
void BST::inorder()
{
    inorder(root);
}
void BST::preorder()
{
    preorder(root);
}
void BST::postorder()
{
    postorder(root);
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
bool BST::Search(const char &item)
{
    return Search(root, item);
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
void BST::printTree()
{
    system("cls");            // Terminali temizle
    printTreeHelper(root, 0); // Kök düğümden başlayarak yazdır
}

void BST::printTreeHelper(Node *node, int space)
{
    if (node == nullptr)
        return;

    const int spacing = 5; // Her seviye için boşluk miktarı
    space += spacing;

    // Sağ alt ağacı yazdır
    printTreeHelper(node->right, space);

    // Mevcut düğümü yazdır
    for (int i = spacing; i < space; i++)
        cout << " ";
    cout << node->data << endl;

    // Sol alt ağacı yazdır
    printTreeHelper(node->left, space);
}
