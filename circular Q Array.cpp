/*CIRCULAR QUEUE - Array Implementation*/
#include <iostream>
using namespace std;

#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1 && rear == -1);
}

bool isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue more elements." << endl;
        return;
    }
    else if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = value;
    cout << "Enqueued " << value << " to the queue." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue elements." << endl;
        return;
    }
    else if (front == rear) {
        cout << "Dequeued " << queue[front] << " from the queue." << endl;
        front = rear = -1;
    }
    else {
        cout << "Dequeued " << queue[front] << " from the queue." << endl;
        front = (front + 1) % MAX_SIZE;
    }
}

int getFront() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return queue[front];
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue elements are: ";
    int i = front;
    while (i != rear) {
        cout << queue[i] << " ";
        i = (i + 1) % MAX_SIZE;
    }
    cout << queue[rear] << endl;
}

int main() {
    int choice, element;
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

    return 0;
}
