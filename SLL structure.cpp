/*Linked List Representation of List ADT*/
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head=NULL;
void insertAtBeginning()
{
    int value;
    cin>>value;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
void print()
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        insertAtBeginning();
    }
    print();
    return 0;
}
