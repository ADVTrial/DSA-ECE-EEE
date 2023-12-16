/*Queue ADT - Linked List Implementation*/
#include <iostream>
using namespace std;

// Node structure for the queue
struct Node {
    int data;
    Node* next;
};

Node* front=NULL;
Node* rear=NULL;

bool isEmpty() {
    return (front == NULL && rear == NULL);
}

void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty()) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue elements." << endl;
        return;
    }
    Node* temp = front;
    //cout << "Dequeued " << front->data << " from the queue." << endl;
    if (front == rear) {//Single Node Deletion
        front = rear = NULL;
    }
    else {
        front = front->next;
    }
    delete temp;
}

int getFront() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return front->data;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    Node* temp = front;
    cout << "Queue elements are: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void print()
{
    cout<<front->data<<endl;
    cout<<rear->data<<endl;
}

int main() {
    int n, element;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>element;
        enqueue(element);
    }
    print();
    dequeue();
    print();
/*
int choice,element;
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Get Front\n4. Display\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> element;
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                cout << "Front element: " << getFront() << endl;
                break;
            case 4:
                display();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);
*/
    return 0;
}
