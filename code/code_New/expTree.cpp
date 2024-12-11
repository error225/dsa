
#include <iostream>
#include <stack>
#include <cctype> 
using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;
};

Node *createNode(char data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node *constructExpressionTree(const string &postfix)
{
    stack<Node *> st;

    for (char ch : postfix)
    {
        if (isalnum(ch))
        {
            st.push(createNode(ch));
        }
        else
        {
            Node *newNode = createNode(ch);
            newNode->right = st.top();
            st.pop();
            newNode->left = st.top();
            st.pop();
            st.push(newNode);
        }
    }

    return st.top(); 
}

void inorderRecursive(Node *root)
{
    if (root)
    {
        inorderRecursive(root->left);
        cout << root->data << " ";
        inorderRecursive(root->right);
    }
}

void preorderRecursive(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void postorderRecursive(Node *root)
{
    if (root)
    {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout << root->data << " ";
    }
}

void inorderNonRecursive(Node *root)
{
    stack<Node *> st;
    Node *current = root;

    while (current != nullptr || !st.empty())
    {
        while (current != nullptr)
        {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

void preorderNonRecursive(Node *root)
{
    if (!root)
        return;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *current = st.top();
        st.pop();
        cout << current->data << " ";

        if (current->right)
            st.push(current->right);
        if (current->left)
            st.push(current->left);
    }
}

void postorderNonRecursive(Node *root)
{
    if (!root)
        return;

    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        Node *current = st1.top();
        st1.pop();
        st2.push(current);

        if (current->left)
            st1.push(current->left);
        if (current->right)
            st1.push(current->right);
    }

    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main()
{
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    Node *root = constructExpressionTree(postfix);

    cout << "\nRecursive Traversals:\n";
    cout << "In-order: ";
    inorderRecursive(root);
    cout << "\nPre-order: ";
    preorderRecursive(root);
    cout << "\nPost-order: ";
    postorderRecursive(root);

    cout << "\n\nNon-Recursive Traversals:\n";
    cout << "In-order: ";
    inorderNonRecursive(root);
    cout << "\nPre-order: ";
    preorderNonRecursive(root);
    cout << "\nPost-order: ";
    postorderNonRecursive(root);

    return 0;
}
