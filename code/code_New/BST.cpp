
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
