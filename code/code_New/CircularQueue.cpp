#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int front, rear;
    int size;
    int *queue;

public:
    CircularQueue(int n)
    {
        size = n;
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    ~CircularQueue()
    {
        delete[] queue;
    }
    void enqueue(int value)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is Full! Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % size;

        queue[rear] = value;
        cout << value << " enqueued to the queue." << endl;
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is Empty! Cannot dequeue." << endl;
            return;
        }
        cout << queue[front] << " dequeued from the queue." << endl;
        if (front == rear)
        { // Queue becomes empty
            front = rear = -1;
        }
        else
            front = (front + 1) % size;
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true)
        {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    int n, choice, value;
    cout << "Enter the size of the circular queue: ";
    cin >> n;

    CircularQueue cq(n);

    do
    {
        cout << "\n--- Circular Queue Operations ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            cq.enqueue(value);
            break;

        case 2:
            cq.dequeue();
            break;

        case 3:
            cq.display();
            break;

        case 4:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
