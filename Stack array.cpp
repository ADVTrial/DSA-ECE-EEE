/*Stack ADT - Array Implementation*/
#include<iostream>
#define SIZE 5
using namespace std;
int stack[SIZE];
int top=-1;
int IsFull()
{
    if(top==SIZE-1)
        return 1;
    else 
        return 0;
}
int IsEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(int value)
{
    if(IsFull())
    {
        cout<<"Stack is Full, Cannot Push"<<endl;
        return;
    }
    top++;
    stack[top] = value;
}
void pop()
{
    if(IsEmpty())
    {
        cout<<"Stack is Empty, Cannot Pop"<<endl;
        return;
    }
    cout<<"Popped element is "<<stack[top]<<endl;;
    top--;
}
void peek()
{
    cout<<"The Peek/top element is "<<stack[top]<<endl;
}
void print()
{
    cout<<"Stack Elements\n";
    for(int i=top;i>=0;i--)
    {
        cout<<stack[i]<<endl;
    }
}
int main()
{
    int n,val;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        push(val);
    }
    print();
    pop();
    pop();
    peek();
    print();
    return 0;
}
/*
INPUT
7
90
1
234
89
23
33
55
*/

