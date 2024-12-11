// // Title : Binary Search Tree
// //             Problem Statement : Implement binary search tree and perform following operations : 1. Insert(Handle insertion of duplicate entry) 2. Delete
// //3. Search
// //4. Display tree(Traversal) 5. Display
// //                                 -
// //Depth of tree
// //6. Display
// //                                 -
// //Mirror image
// //7. Display leaf nodes
// //8. Display tree level wise

// #include <iostream>
// using namespace std;

// struct TreeNode
// {
//     int data;
//     TreeNode *left;
//     TreeNode *right;
// };

// class BST
// {
// public:
//     TreeNode *root;

//     BST()
//     {
//         root = NULL;
//     }

//     void insertNode(int value);
//     void inorderTraversal(TreeNode *node);
//     void preorderTraversal(TreeNode *node);
//     void postorderTraversal(TreeNode *node);
//     void deleteNode(int value);
//     void deleteCaseNoOrOneChild(TreeNode *nodeToDelete, TreeNode *parentNode);
//     void deleteCaseTwoChildren();
//     void searchNode(int value);
//     int calculateDepth(TreeNode *node);
//     void printLeafNodes(TreeNode *node);
//     void mirrorTree(TreeNode *node);
// };

// void BST::insertNode(int value)
// {
//     TreeNode *newNode = new TreeNode;
//     newNode->data = value;
//     newNode->left = NULL;
//     newNode->right = NULL;

//     if (root == NULL)
//     {
//         root = newNode;
//     }
//     else{
//         TreeNode *current = root;
//         TreeNode *parent = NULL;

//         while (current != NULL){
//             parent = current;
//             if (value > current->data) current = current->right;
//             else current = current->left;
//         }

//         if (value > parent->data) parent->right = newNode;

//         else parent->left = newNode;
        
//     }
// }

// void BST::deleteCaseNoOrOneChild(TreeNode *nodeToDelete, TreeNode *parentNode)
// {
//     TreeNode *child = NULL;

//     if (nodeToDelete->left == NULL && nodeToDelete->right == NULL)
//     {
//         child = NULL; // No children
//     }
//     else if (nodeToDelete->left != NULL)
//     {
//         child = nodeToDelete->left; // Left child exists
//     }
//     else
//     {
//         child = nodeToDelete->right; // Right child exists
//     }

//     if (parentNode != NULL)
//     {
//         if (nodeToDelete == parentNode->left)
//         {
//             parentNode->left = child;
//         }
//         else
//         {
//             parentNode->right = child;
//         }
//     }
//     else
//     {
//         root = child; // Node to delete is the root
//     }
// }

// void BST::deleteCaseTwoChildren()
// {
//     TreeNode *successor = root->right;
//     TreeNode *successorParent = root;

//     while (successor->left != NULL)
//     {
//         successorParent = successor;
//         successor = successor->left;
//     }

//     deleteCaseNoOrOneChild(successor, successorParent);

//     if (root->left != NULL)
//     {
//         successor->left = root->left;
//     }
//     if (root->right != NULL)
//     {
//         successor->right = root->right;
//     }

//     root = successor;
// }

// void BST::deleteNode(int value)
// {
//     TreeNode *current = root;
//     TreeNode *parent = NULL;

//     while (current != NULL && current->data != value)
//     {
//         parent = current;
//         if (value < current->data)
//         {
//             current = current->left;
//         }
//         else
//         {
//             current = current->right;
//         }
//     }

//     if (current == NULL)
//     {
//         cout << "\n"
//              << value << " not found.";
//         return;
//     }

//     if (current->left != NULL && current->right != NULL)
//     {
//         deleteCaseTwoChildren();
//     }
//     else
//     {
//         deleteCaseNoOrOneChild(current, parent);
//     }

//     delete current;
// }

// void BST::searchNode(int value)
// {
//     TreeNode *current = root;

//     while (current != NULL)
//     {
//         if (current->data == value)
//         {
//             cout << value << " is found.";
//             return;
//         }
//         else if (value < current->data)
//         {
//             current = current->left;
//         }
//         else
//         {
//             current = current->right;
//         }
//     }

//     cout << value << " is not found.";
// }

// int BST::calculateDepth(TreeNode *node)
// {
//     if (node == NULL)
//     {
//         return 0;
//     }

//     int leftDepth = calculateDepth(node->left);
//     int rightDepth = calculateDepth(node->right);

//     return max(leftDepth, rightDepth) + 1;
// }

// void BST::inorderTraversal(TreeNode *node)
// {
//     if (node != NULL)
//     {
//         inorderTraversal(node->left);
//         cout << node->data << " ";
//         inorderTraversal(node->right);
//     }
// }

// void BST::preorderTraversal(TreeNode *node)
// {
//     if (node != NULL)
//     {
//         cout << node->data << " ";
//         preorderTraversal(node->left);
//         preorderTraversal(node->right);
//     }
// }

// void BST::postorderTraversal(TreeNode *node)
// {
//     if (node != NULL)
//     {
//         postorderTraversal(node->left);
//         postorderTraversal(node->right);
//         cout << node->data << " ";
//     }
// }

// void BST::printLeafNodes(TreeNode *node)
// {
//     if (node == NULL)
//     {
//         return;
//     }

//     if (node->left == NULL && node->right == NULL)
//     {
//         cout << node->data << " ";
//         return;
//     }

//     printLeafNodes(node->left);
//     printLeafNodes(node->right);
// }

// void BST::mirrorTree(TreeNode *node)
// {
//     if (node != NULL)
//     {
//         TreeNode *temp = node->left;
//         node->left = node->right;
//         node->right = temp;

//         mirrorTree(node->left);
//         mirrorTree(node->right);
//     }
// }

// int main()
// {
//     BST bst;
//     int choice, value;

//     do
//     {
//         cout << "\n1. Insert Node";
//         cout << "\n2. Traversals";
//         cout << "\n3. Delete Node";
//         cout << "\n4. Search Node";
//         cout << "\n5. Tree Depth";
//         cout << "\n6. Print Leaf Nodes";
//         cout << "\n7. Mirror Tree";
//         cout << "\n8. Exit";
//         cout << "\nEnter your choice: ";
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             cout << "\nEnter value to insert: ";
//             cin >> value;
//             bst.insertNode(value);
//             break;
//         case 2:
//             cout << "\nInorder Traversal: ";
//             bst.inorderTraversal(bst.root);
//             cout << "\nPreorder Traversal: ";
//             bst.preorderTraversal(bst.root);
//             cout << "\nPostorder Traversal: ";
//             bst.postorderTraversal(bst.root);
//             break;
//         case 3:
//             cout << "\nEnter value to delete: ";
//             cin >> value;
//             bst.deleteNode(value);
//             break;
//         case 4:
//             cout << "\nEnter value to search: ";
//             cin >> value;
//             bst.searchNode(value);
//             break;
//         case 5:
//             cout << "\nTree Depth: " << bst.calculateDepth(bst.root);
//             break;
//         case 6:
//             cout << "\nLeaf Nodes: ";
//             bst.printLeafNodes(bst.root);
//             break;
//         case 7:
//             bst.mirrorTree(bst.root);
//             cout << "\nInorder Traversal of Mirrored Tree: ";
//             bst.inorderTraversal(bst.root);
//             break;
//         case 8:
//             cout << "\nExiting...";
//             break;
//         default:
//             cout << "\nInvalid choice!";
//         }
//     } while (choice != 8);

//     return 0;
// }

// #include <iostream>
// using namespace std;

// struct tree
// {
//     int data;
//     tree *left;
//     tree *right;
// };

// class BST
// {
// public:
//     tree *root, *loc, *par, *suc, *parsuc, *ptr, *save;
//     // loc = location, par = parent, suc = successor, parsuc = predecessor

//     BST()
//     {
//         root = NULL;
//     }

//     void createbst(int);
//     void inorder(tree *);
//     void preorder(tree *);
//     void postorder(tree *);
//     void deletenode(int);
//     void casea(tree *, tree *);
//     void caseb();
//     void search(int);
//     int depth(tree *);
//     void printLeafNodes(tree *);
//     void mirror_tree(tree *);
// };

// void BST::createbst(int x)
// {
//     tree *newnode = new tree;
//     newnode->data = x;
//     newnode->left = NULL;
//     newnode->right = NULL;

//     if (root == NULL)
//     {
//         root = newnode;
//     }
//     else
//     {
//         tree *ptr = root;
//         tree *parent = nullptr;

//         while (ptr != NULL)
//         {
//             parent = ptr;
//             if (x > ptr->data)
//             {
//                 ptr = ptr->right;
//             }
//             else
//             {
//                 ptr = ptr->left;
//             }
//         }

//         if (x > parent->data)
//         {
//             parent->right = newnode;
//         }
//         else
//         {
//             parent->left = newnode;
//         }
//     }
// }

// void BST::casea(tree *loc, tree *par)
// {
//     tree *child;

//     if (loc->left == NULL && loc->right == NULL)
//     {
//         child = NULL;
//     }
//     else if (loc->left != NULL)
//     {
//         child = loc->left;
//     }
//     else
//     {
//         child = loc->right;
//     }

//     if (par != NULL)
//     {
//         if (loc == par->left)
//         {
//             par->left = child;
//         }
//         else
//         {
//             par->right = child;
//         }
//     }
//     else
//     {
//         root = child;
//     }
// }

// void BST::caseb()
// {
//     tree *ptr = loc->right;
//     tree *save = loc;

//     while (ptr->left != NULL)
//     {
//         save = ptr;
//         ptr = ptr->left;
//     }

//     suc = ptr;
//     parsuc = save;
//     casea(suc, parsuc);

//     if (par != NULL)
//     {
//         if (loc == par->left)
//         {
//             par->left = suc;
//         }
//         else
//         {
//             par->right = suc;
//         }
//     }
//     else
//     {
//         root = suc;
//     }

//     suc->left = loc->left;
//     suc->right = loc->right;
// }

// void BST::deletenode(int x)
// {
//     loc = root;
//     par = NULL;

//     while (loc != NULL && x != loc->data)
//     {
//         par = loc;
//         if (x < loc->data)
//         {
//             loc = loc->left;
//         }
//         else
//         {
//             loc = loc->right;
//         }
//     }

//     if (loc == NULL)
//     {
//         cout << "\n"
//              << x << " not found.";
//         return;
//     }

//     if (loc->left != NULL && loc->right != NULL)
//     {
//         caseb();
//     }
//     else
//     {
//         casea(loc, par);
//     }

//     delete loc;
// }

// void BST::search(int x)
// {
//     if (root == NULL)
//     {
//         cout << "\nTree is empty";
//         return;
//     }

//     ptr = root;
//     while (ptr != NULL)
//     {
//         if (ptr->data == x)
//         {
//             cout << x << " is found.";
//             return;
//         }
//         else if (x < ptr->data)
//         {
//             ptr = ptr->left;
//         }
//         else
//         {
//             ptr = ptr->right;
//         }
//     }

//     cout << x << " is not found.";
// }

// int BST::depth(tree *ptr)
// {
//     if (ptr == NULL)
//     {
//         return 0;
//     }

//     int lh = depth(ptr->left);
//     int rh = depth(ptr->right);

//     return max(lh, rh) + 1;
// }

// void BST::inorder(tree *ptr)
// {
//     if (ptr != NULL)
//     {
//         inorder(ptr->left);
//         cout << ptr->data << " ";
//         inorder(ptr->right);
//     }
// }

// void BST::preorder(tree *ptr)
// {
//     if (ptr != NULL)
//     {
//         cout << ptr->data << " ";
//         preorder(ptr->left);
//         preorder(ptr->right);
//     }
// }

// void BST::postorder(tree *ptr)
// {
//     if (ptr != NULL)
//     {
//         postorder(ptr->left);
//         postorder(ptr->right);
//         cout << ptr->data << " ";
//     }
// }

// void BST::printLeafNodes(tree *ptr)
// {
//     if (ptr == NULL)
//     {
//         return;
//     }

//     if (ptr->left == NULL && ptr->right == NULL)
//     {
//         cout << ptr->data << " ";
//         return;
//     }

//     printLeafNodes(ptr->left);
//     printLeafNodes(ptr->right);
// }

// void BST::mirror_tree(tree *ptr)
// {
//     if (ptr != NULL)
//     {
//         tree *temp = ptr->left;
//         ptr->left = ptr->right;
//         ptr->right = temp;

//         mirror_tree(ptr->left);
//         mirror_tree(ptr->right);
//     }
// }

// int main()
// {
//     int ch, x, h;
//     BST t;

//     do
//     {
//         cout << "\n1. Insertion into Binary Search Tree";
//         cout << "\n2. Traversals";
//         cout << "\n3. Deletion from Binary Search Tree";
//         cout << "\n4. Search";
//         cout << "\n5. Depth of a Tree";
//         cout << "\n6. Print Leaf Nodes";
//         cout << "\n7. Mirror of Tree";
//         cout << "\n8. Exit";
//         cout << "\nEnter your choice: ";
//         cin >> ch;

//         switch (ch)
//         {
//         case 1:
//             cout << "\nEnter data to insert: ";
//             cin >> x;
//             t.createbst(x);
//             break;
//         case 2:
//             cout << "\nInorder: ";
//             t.inorder(t.root);
//             cout << "\nPreorder: ";
//             t.preorder(t.root);
//             cout << "\nPostorder: ";
//             t.postorder(t.root);
//             break;
//         case 3:
//             cout << "\nEnter data to delete: ";
//             cin >> x;
//             t.deletenode(x);
//             break;
//         case 4:
//             cout << "\nEnter data to search: ";
//             cin >> x;
//             t.search(x);
//             break;
//         case 5:
//             h = t.depth(t.root);
//             cout << "\nDepth of the Tree: " << h;
//             break;
//         case 6:
//             cout << "\nLeaf Nodes: ";
//             t.printLeafNodes(t.root);
//             break;
//         case 7:
//             t.mirror_tree(t.root);
//             cout << "\nInorder display of mirror tree: ";
//             t.inorder(t.root);
//             break;
//         case 8:
//             cout << "\nExiting...";
//             break;
//         default:
//             cout << "\nInvalid choice!";
//         }
//     } while (ch != 8);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == nullptr)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        cout << "Duplicate entry: " << data << " already exists.\n";

    return root;
}

Node *findMin(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int data)
{
    if (root == nullptr)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        // Node with one child or no child
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

bool search(Node *root, int data)
{
    if (root == nullptr)
        return false;
    if (data == root->data)
        return true;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Level order traversal
void levelOrder(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}

int depth(Node *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(depth(root->left), depth(root->right));
}

Node *mirror(Node *root)
{
    if (root == nullptr)
        return nullptr;

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);

    return root;
}

// Display leaf nodes
void displayLeafNodes(Node *root)
{
    if (root)
    {
        if (!root->left && !root->right)
            cout << root->data << " ";
        displayLeafNodes(root->left);
        displayLeafNodes(root->right);
    }
}

int main()
{
    Node *root = nullptr;
    int choice, value;

    do
    {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display (Inorder)\n";
        cout << "5. Display Depth\n6. Display Mirror Image\n";
        cout << "7. Display Leaf Nodes\n8. Display Level-wise\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value))
                cout << value << " is found in the tree.\n";
            else
                cout << value << " is not found in the tree.\n";
            break;

        case 4:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Depth of Tree: " << depth(root) << endl;
            break;

        case 6:
            root = mirror(root);
            cout << "Tree has been mirrored.\n";
            break;

        case 7:
            cout << "Leaf Nodes: ";
            displayLeafNodes(root);
            cout << endl;
            break;

        case 8:
            cout << "Level-wise Display: ";
            levelOrder(root);
            cout << endl;
            break;

        case 9:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
