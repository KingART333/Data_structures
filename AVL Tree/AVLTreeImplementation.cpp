#include "AVLTreeImplementation.h"
#include <iostream>

using namespace std;

AVL::AVL()
{
    root = nullptr;
}

int AVL::NodeHeight(Node* p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int AVL::BalanceFactor(Node* p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

Node* AVL::LLRotation(Node* p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    // Update height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    // Update root
    if (root == p)
    {
        root = pl;
    }
    return pl;
}

Node* AVL::RRRotation(Node* p)
{
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    // Update root
    if (root == p)
    {
        root = pr;
    }
    return pr;
}

Node* AVL::LRRotation(Node* p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    // Update height
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    // Update root
    if (p == root)
    {
        root = plr;
    }
    return plr;
}

Node* AVL::RLRotation(Node* p)
{
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    // Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    // Update root
    if (root == p)
    {
        root = prl;
    }
    return prl;
}

Node* AVL::rInsert(Node* p, int key)
{
    Node* t;
    if (p == nullptr) 
    {
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        t->height = 1;  // Starting height from 1 onwards instead of 0
        return t;
    }

    if (key < p->data)
    {
        p->lchild = rInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = rInsert(p->rchild, key);
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        return RLRotation(p);
    }

    return p;
}

Node* AVL::deleteNode(Node* p, int key) 
{
    if (p == nullptr) 
    {
        return nullptr;
    }

    if (key < p->data) 
    {
        p->lchild = deleteNode(p->lchild, key);
    }
    else if (key > p->data) 
    {
        p->rchild = deleteNode(p->rchild, key);
    }
    else 
    {
        // Node to be deleted found

        // Node with no child or only one child
        if (p->lchild == nullptr) 
        {
            Node* temp = p->rchild;
            delete p;
            return temp;
        }
        else if (p->rchild == nullptr) 
        {
            Node* temp = p->lchild;
            delete p;
            return temp;
        }
        else 
        {
            // Node with two children
            Node* temp = p->rchild;
            while (temp->lchild != nullptr) 
            {
                temp = temp->lchild;
            }
            p->data = temp->data;
            p->rchild = deleteNode(p->rchild, temp->data);
        }
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) 
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) 
    {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) 
    {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) 
    {
        return RLRotation(p);
    }

    return p;
}

void AVL::Inorder(Node* p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void AVL::Inorder()
{
    Inorder(root);
}

Node* AVL::getRoot()
{
    return root;
}




int main()
{
    // LR Rotation
    AVL tlr;
    tlr.root = tlr.rInsert(tlr.root, 50);
    tlr.root = tlr.rInsert(tlr.root, 10);
    tlr.root = tlr.rInsert(tlr.root, 20);

    tlr.Inorder();
    cout << endl;
    cout << tlr.getRoot()->data << endl;

    // RL Rotation
    AVL trl;
    trl.root = trl.rInsert(trl.root, 20);
    trl.root = trl.rInsert(trl.root, 50);
    trl.root = trl.rInsert(trl.root, 30);

    trl.Inorder();
    cout << endl;
    cout << trl.getRoot()->data << endl;

    return 0;
}


