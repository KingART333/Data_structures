#include "BinaryTreeImplementation.h"

template<typename T>
BinaryTree<T>::BinaryTree() : root(nullptr)
{
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
    destroyTree(root);
}

template<typename T>
void BinaryTree<T>::preorderIterative(Node<T>* node)
{
    if (node == nullptr)
        return;

    std::stack<Node<T>*> stk;
    stk.push(node);

    while (!stk.empty())
    {
        Node<T>* current = stk.top();
        stk.pop();
        std::cout << current->value << " ";

        if (current->right)
            stk.push(current->right);

        if (current->left)
            stk.push(current->left);
    }
}

template<typename T>
void BinaryTree<T>::inorderIterative(Node<T>* node)
{
    if (node == nullptr)
        return;

    std::stack<Node<T>*> stk;
    Node<T>* current = node;

    while (current != nullptr || !stk.empty())
    {
        while (current != nullptr)
        {
            stk.push(current);
            current = current->left;
        }

        current = stk.top();
        stk.pop();
        std::cout << current->value << " ";

        current = current->right;
    }
}

template<typename T>
void BinaryTree<T>::postorderIterative(Node<T>* node)
{
    if (node == nullptr)
        return;

    std::stack<Node<T>*> stk;
    Node<T>* current = node;
    Node<T>* prev = nullptr;

    do
    {
        while (current != nullptr)
        {
            stk.push(current);
            current = current->left;
        }

        while (current == nullptr && !stk.empty())
        {
            current = stk.top();

            if (current->right == nullptr || current->right == prev)
            {
                std::cout << current->value << " ";
                stk.pop();
                prev = current;
                current = nullptr;
            }
            else
            {
                current = current->right;
            }
        }
    } while (!stk.empty());
}

template<typename T>
void BinaryTree<T>::levelorderTraversal(Node<T>* node) 
{
    if (node == nullptr)
        return;

    std::queue<Node<T>*> queue;
    queue.push(node);

    while (!queue.empty()) 
    {
        Node<T>* current = queue.front();
        queue.pop();
        std::cout << current->value << " ";

        if (current->left)
            queue.push(current->left);
        if (current->right)
            queue.push(current->right);
    }
}

template<typename T>
Node<T>* BinaryTree<T>::deepestRightmost(Node<T>* node)
{
    if (node == nullptr)
        return nullptr;

    std::queue<Node<T>*> q;
    q.push(node);
    Node<T>* deepestRight = nullptr;

    while (!q.empty()) 
    {
        Node<T>* current = q.front();
        q.pop();

        if (current->right == nullptr && current->left == nullptr) 
        {
            deepestRight = current;
        }

        if (current->left != nullptr) 
        {
            q.push(current->left);
        }
        if (current->right != nullptr) 
        {
            q.push(current->right);
        }
    }
    return deepestRight;
}

template<typename T>
Node<T>* BinaryTree<T>::deletDeepest(Node<T>* root, Node<T>* d_node)
{
    if (root == nullptr)
        return nullptr;

    std::queue<Node<T>*> q;
    q.push(root);
    Node<T>* temp = nullptr;
    Node<T>* deepestRightmostNode = nullptr;

    while (!q.empty()) 
    {
        temp = q.front();
        q.pop();

        if (temp == d_node) 
        {
            deepestRightmostNode = temp;
        }

        if (temp->right) 
        {
            if (temp->right == d_node) 
            {
                temp->right = nullptr;
                delete d_node;
                return root;
            }
            else
                q.push(temp->right);
        }

        if (temp->left) 
        {
            if (temp->left == d_node) 
            {
                temp->left = nullptr;
                delete d_node;
                return root;
            }
            else
                q.push(temp->left);
        }
    }

    if (deepestRightmostNode != nullptr) 
    {
        deepestRightmostNode->value = temp->value;
        delete temp;
    }

    return root;
}

template<typename T>
Node<T>* BinaryTree<T>::deletion(Node<T>* root, const T& key)
{
    if (root == nullptr)
        return nullptr;

    if (root->left == nullptr && root->right == nullptr) 
    {
        if (root->value == key)
        {
            delete root;
            return nullptr;
        }
        else
            return root;
    }

    std::queue<Node<T>*> q;
    q.push(root);
    Node<T>* temp = nullptr;
    Node<T>* key_node = nullptr;

    while (!q.empty()) 
    {
        temp = q.front();
        q.pop();

        if (temp->value == key)
            key_node = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    if (key_node != nullptr) 
    {
        deletDeepest(root, temp);
        key_node->value = temp->value;
    }
    return root;
}

template<typename T>
void BinaryTree<T>::destroyTree(Node<T>* node)
{
    if (node != nullptr)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

template<typename T>
bool BinaryTree<T>::searchHelper(Node<T>* node, const T& key) 
{
    if (node == nullptr)
        return false;
    if (node->value == key)
        return true;
    return searchHelper(node->left, key) || searchHelper(node->right, key);
}

template<typename T>
bool BinaryTree<T>::search(const T& key) 
{
    if (searchHelper(root, key)) 
    {
        std::cout << "Key " << key << " found!" << std::endl;
        return true;
    }
    else 
    {
        std::cout << "Key " << key << " not found." << std::endl;
        return false;
    }
}

template<typename T>
Node<T>* BinaryTree<T>::insertHelper(Node<T>* current, Node<T>* node)
{
    if (current == nullptr)
        return node;

    std::queue<Node<T>*> q;
    q.push(current);

    while (!q.empty())
    {
        Node<T>* temp = q.front();
        q.pop();

        if (temp->left == nullptr)
        {
            temp->left = node;
            return current;
        }
        else if (temp->right == nullptr)
        {
            temp->right = node;
            return current;
        }
        else
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }

    return current;
}

template<typename T>
bool BinaryTree<T>::insert(const T& value)
{
    Node<T>* node = new Node<T>(value);
    root = insertHelper(root, node);
    return true;
}

template<typename T>
int BinaryTree<T>::count(Node<T> *node)
{
    if (node)
        return count(node->left) + count(node->right) + 1;
    return 0;
}

template<typename T>
int BinaryTree<T>::height(Node<T>* node)
{
    if (!node)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return std::max(leftHeight, rightHeight) + 1;
}

template<typename T>
void BinaryTree<T>::preorderRecursive(Node<T>* node)
{
    if (node)
    {
        std::cout << node->value << " ";
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }
}

template<typename T>
void BinaryTree<T>::inorderRecursive(Node<T>* node)
{
    if (node)
    {
        inorderRecursive(node->left);
        std::cout << node->value << " ";
        inorderRecursive(node->right);
    }
}

template<typename T>
void BinaryTree<T>::postorderRecursive(Node<T>* node)
{
    if (node)
    {
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        std::cout << node->value << " ";
    }
}