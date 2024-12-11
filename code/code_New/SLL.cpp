#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList{
public:

    Node *head;
    SinglyLinkedList(){
        head = nullptr;
    }

    void insertAtBeginning(int value){
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value){
        Node *newNode = new Node(value);
        if (head == nullptr){
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    void insertAtPosition(int value, int position)
    {
        if (position < 1 || (position > countNodes() + 1))
        {
            cout << "Invalid position!" << endl;
            return;
        }
        if (position == 1)
        {
            insertAtBeginning(value);
            return;
        }
        Node *newNode = new Node(value);
        Node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFirst()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int position)
    {
        if (position < 1 || position > countNodes())
        {
            cout << "Invalid position!" << endl;
            return;
        }
        if (position == 1)
        {
            deleteFirst();
            return;
        }
        Node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool search(int value)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int countNodes()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main()
{
    SinglyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtPosition(25, 3);

    cout << "List after insertions: ";
    list.display();

    list.deleteFirst();
    cout << "List after deleting first node: ";
    list.display();

    list.deleteLast();
    cout << "List after deleting last node: ";
    list.display();

    list.deleteAtPosition(2);
    cout << "List after deleting node at position 2: ";
    list.display();

    cout << "Searching for 25: " << (list.search(25) ? "Found" : "Not Found") << endl;
    cout << "Searching for 30: " << (list.search(30) ? "Found" : "Not Found") << endl;

    cout << "Number of nodes: " << list.countNodes() << endl;

    return 0;
}
