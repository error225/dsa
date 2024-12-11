// #include <bits/stdc++.h>
// using namespace std;

// struct TreeNode
// {
//     int data;
//     TreeNode *left;
//     TreeNode *right;
// };

// class BST{
// public:
//     TreeNode *root;

//     BST(){
//         root = NULL;
//     }

//     void insertNode(int value);
//     void inorderTraversal(TreeNode *node);
//     void preorderTraversal(TreeNode *node);
//     void postorderTraversal(TreeNode *node);
// };
// void BST::insertNode(int value) {
//     TreeNode *newNode = new TreeNode();
//     newNode->data = value;
//     newNode->left = newNode->right = NULL;

//     if (root == NULL) {
//         root = newNode;
//         return;
//     }

//     TreeNode *current = root;
//     TreeNode *parent = NULL;

//     while (current != NULL) {
//         parent = current;
// }

#include <bits/stdc++.h>
using namespace std;

class node{
public: 
    int value;
    node* left;
    node* right;

    node(int val) {
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
public:
    node* root;
    BST(){
        root = NULL;
    }

    node* insertNode(node* root, int value) {

    }

    void insertNode(int value) {
        root = insertNode(root, value);
    }
};