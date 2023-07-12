class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
    int height;
};

class AVL
{
public:
    Node* root;

    AVL();
    int NodeHeight(Node* p);
    int BalanceFactor(Node* p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);
    Node* rInsert(Node* p, int key);
    Node* deleteNode(Node* p, int key);
    void Inorder(Node* p);
    void Inorder();
    Node* getRoot();
};