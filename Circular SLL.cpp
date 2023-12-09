/*Circular Singly Linked List*/
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head=NULL;
Node *tail=NULL;
void insertAtBeginning()
{
    int value;
    cin>>value;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if(head==NULL)//List is Empty so create List
    {
        tail=newNode;
        head = newNode;
        tail->next = head;
    }
    else
    {
        newNode->next=head;
        head=newNode;
        tail->next=head;
    }

}
void insertAtEnd()
{
    int value;
    cin>>value;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if(head==NULL)//List is empty so create the list
    {
        tail=newNode;
        head = newNode;
        tail->next = head;
    }
    else
    {
        tail->next=newNode;
        newNode->next=head;
        tail=newNode;
    }
}
void insertAtMiddle()
{
    int pos;
    cin>>pos;
    if(pos==1)
    {
        insertAtBeginning();
        return;
    }
    int value;
    cin>>value;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    Node *temp = head;
    Node *prev = head;
    while(--pos)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next=newNode;
    newNode->next = temp;
    if(temp==head && prev==tail)
    {
        tail=newNode;
    }
}
void deleteFirst()
{
    if(head == NULL)
    {
        cout<<"List is Empty, can't Delete\n";
    }
    else
    {
        if(head==tail)//Single Node to be deleted, then List becomes empty
        {
            delete head;
            head=NULL;
            tail=NULL;
        }
        else
        {
            Node *temp=head;
            head=head->next;
            tail->next=head;
            delete temp;
        }

    }
}
void deleteEnd()
{
    if(head == NULL)
    {
        cout<<"List is Empty, Can't Delete\n";
    }
    else if(head==tail)//Single node to be deleted,List becomes empty
    {
        delete(head);
        head=NULL;
        tail=NULL;
    }
    else
    {
        Node *curr=head;
        Node *prev=head;
        while (curr->next != head)
        {
            prev = curr;
            curr = curr->next;
        }
        tail=prev;
        tail->next=head;
        delete(curr);
    }
}
void deleteMiddle()
{
    int pos;
    cin>>pos;
    Node *temp=head;
    Node *prev=head;
    while(--pos)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    if(temp==tail)
    {
        tail=prev;
    }
    delete(temp);
}
void print()
{
    if( head==NULL && tail==NULL)
    {
        cout<<"List is Empty"<<endl;
        return;
    }
    Node *temp = head;
    while(temp!=tail)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<tail->data;
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
    insertAtMiddle();
    print();
    insertAtMiddle();
    print();
    insertAtEnd();
    print();
    insertAtEnd();
    print();
    deleteMiddle();
    print();
    deleteMiddle();
    print();
    deleteFirst();
    print();
    deleteFirst();
    print();
    deleteEnd();
    print();
    deleteEnd();
    print();
    deleteEnd();
    print();
    deleteFirst();
    print();
    deleteFirst();
    print();
    return 0;
}
/*INPUT
4
10 20 30 40
2 50
5 60
70
80
3
5
*/

