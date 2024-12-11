#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node(char value)
    {
        data = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    void push(char value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (isEmpty())
            throw runtime_error("Stack underflow");
        Node *temp = top;
        char data = temp->data;
        top = top->next;
        delete temp;
        return data;
    }

    char peek()
    {
        if (isEmpty())
            throw runtime_error("Stack is empty");
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    ~Stack()
    {
        while (!isEmpty())
            pop();
    }
};

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPostfix(const string &infix)
{
    Stack s;
    string postfix;
    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }
            s.pop();
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c))
            {
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty())
    {
        postfix += s.pop();
    }
    return postfix;
}

string infixToPrefix(const string &infix)
{
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());
    for (char &c : reversedInfix)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }
    string postfix = infixToPostfix(reversedInfix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int evaluatePostfix(const string &postfix)
{
    stack<int> s;
    for (char c : postfix)
    {
        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else if (isOperator(c))
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            switch (c)
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                s.push(a / b);
                break;
            case '^':
                s.push(pow(a, b));
                break;
            }
        }
    }
    return s.top();
}

int evaluatePrefix(const string &prefix)
{
    stack<int> s;
    for (auto it = prefix.rbegin(); it != prefix.rend(); ++it)
    {
        char c = *it;
        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else if (isOperator(c))
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            switch (c)
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                s.push(a / b);
                break;
            case '^':
                s.push(pow(a, b));
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    cout << "Evaluation of postfix: " << evaluatePostfix(postfix) << endl;
    cout << "Evaluation of prefix: " << evaluatePrefix(prefix) << endl;

    return 0;
}