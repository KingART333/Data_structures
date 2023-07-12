#include <iostream>
#include <queue>
#include <stack>

template<typename T>
struct Node
{
    T value;
    Node<T>* right = nullptr;
    Node<T>* left = nullptr;
    Node<T>(T val) : value(val) {}
};

template<typename T>
class BinaryTree 
{
private:
    bool searchHelper(Node<T>* node, const T& key);
    Node<T>* insertHelper(Node<T>* current, Node<T>* node);
    void destroyTree(Node<T>* node);
    Node<T>* deletDeepest(Node<T>* root, Node<T>* d_node);

public:
    Node<T>* root;

    BinaryTree();
    ~BinaryTree();

    void preorderIterative(Node<T>* node);
    void inorderIterative(Node<T>* node);
    void postorderIterative(Node<T>* node);
    void levelorderTraversal(Node<T>* node);

    Node<T>* deletion(Node<T>* root, const T& key);
    Node<T>* deepestRightmost(Node<T>* node);

    bool search(const T& key);
    bool insert(const T& value);

    int count(Node<T>* node);
    int height(Node<T>* node);

    void preorderRecursive(Node<T>* node);
    void inorderRecursive(Node<T>* node);
    void postorderRecursive(Node<T>* node);
};