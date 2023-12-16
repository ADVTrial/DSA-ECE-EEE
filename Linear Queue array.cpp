/*Linear Queue - Array Implementation*/
#include<iostream>
using namespace std;
#define size 5
int queue[size];
int front=-1;
int rear=-1;
bool isEmpty()
{
    return (front==-1 && rear==-1);
}
bool isFull()
{
    return (rear==size-1);
}
void enqueue(int value)
{
    if(isFull())
    {
        cout<<"Queue is full. Cannot enqueue more elements"<<endl;
        return;
    }
    else if(isEmpty())
    {
        front=rear=0;
    }
    else
    {
        rear++;
    }
        queue[rear]=value;
}
void dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is empty. Cannot dequeue elements"<<endl;
        return;
    }
    else if(front==rear)//Single Node Deletion
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}
int getFront() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return queue[front];
}
void print()
{
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    for(int i=front;i<=rear;i++)
    {
        cout<<queue[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int element;
    for(int i=0;i<5;i++)
    {
        cin>>element;
        enqueue(element);
    }
    print();
    dequeue();
    dequeue();
    cout<<getFront()<<endl;
    print();
    for(int i=1;i<=3;i++)
    {
        dequeue();
    }
    print();
}
