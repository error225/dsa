// Title : Threaded Binary Tree
// Problem Statement : Implement In -order Threaded Binary Tree and traverse it in In - order and Pre - order.
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    bool isThreaded;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    newNode->isThreaded = false;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if (!root)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data){
        if (root->isThreaded)
        {
            root->isThreaded = false;
            root->right = insert(nullptr, data);
        }
        else  root->right = insert(root->right, data);
    }
    return root;
}

void createThreads(Node *root, Node *&prev)
{
    if (!root)
        return;

    createThreads(root->left, prev);

    if (prev && !prev->right)
    {
        prev->right = root;
        prev->isThreaded = true;
    }
    prev = root;

    createThreads(root->right, prev);
}

void inorder(Node *root)
{
    Node *current = root;
    while (current && current->left)
        current = current->left;

    while (current)
    {
        cout << current->data << " ";
        if (current->isThreaded)
            current = current->right;
        else
        {
            current = current->right;
            while (current && current->left)
                current = current->left;
        }
    }
}

void preorder(Node *root)
{
    Node *current = root;
    while (current)
    {
        cout << current->data << " ";
        if (current->left)
            current = current->left;
        else
        {
            while (current && current->isThreaded)
                current = current->right;
            if (current)
                current = current->right;
        }
    }
}

int main()
{
    Node *root = nullptr;

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    Node *prev = nullptr;
    createThreads(root, prev);

    cout << "In-order Traversal: ";
    inorder(root);
    cout << "\nPre-order Traversal: ";
    preorder(root);

    return 0;
}
