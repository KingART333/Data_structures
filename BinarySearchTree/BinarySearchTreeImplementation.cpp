#include "BinarySearchTreeImplementation.h"

namespace BinaryTreeNamespace {

    BinaryTree::BinaryTree() : root(nullptr) {}

    BinaryTree::~BinaryTree() {
        destroyTree(root);
    }

    void BinaryTree::destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    void BinaryTree::insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        while (true) {
            if (value < current->value) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }
        }
    }

    bool BinaryTree::search(int value) {
        Node* current = root;
        while (current != nullptr) {
            if (value == current->value)
                return true;
            else if (value < current->value)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }

    int BinaryTree::Height(Node* p) {
        int x, y;
        if (p == nullptr)
            return 0;
        x = Height(p->left);
        y = Height(p->right);
        return x > y ? x + 1 : y + 1;
    }

    Node* BinaryTree::InSucc(Node* p) {
        while (p && p->right != nullptr)
            p = p->right;

        return p;
    }

    Node* BinaryTree::InPre(Node* p) {
        while (p && p->left != nullptr)
            p = p->left;

        return p;
    }

    Node* BinaryTree::Delete(Node* p, int key) {
        Node* q;

        if (p == nullptr)
            return nullptr;
        if (p->left == nullptr && p->right == nullptr) {
            if (p == root)
                root = nullptr;
            delete p;
            return nullptr;
        }

        if (key < p->value)
            p->left = Delete(p->left, key);
        else if (key > p->value)
            p->right = Delete(p->right, key);
        else {
            if (Height(p->left) > Height(p->right)) {
                q = InPre(p->left);
                p->value = q->value;
                p->left = Delete(p->left, q->value);
            } else {
                q = InPre(p->right);
                p->value = q->value;
                p->right = Delete(p->right, q->value);
            }
        }
        return p;
    }

    void BinaryTree::Preorder(Node* p) {
        if (p) {
            std::cout << p->value << " ";
            Preorder(p->left);
            Preorder(p->right);
        }
    }

    void BinaryTree::Inorder(Node* p) {
        if (p) {
            Inorder(p->left);
            std::cout << p->value << " ";
            Inorder(p->right);
        }
    }

    void BinaryTree::Postorder(Node* p) {
        if (p) {
            Postorder(p->left);
            Postorder(p->right);
            std::cout << p->value << " ";
        }
    }
}