/*Length of longest balanced parenthesis*/
#include<iostream>
#include<cstring>
#define SIZE 100
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
    if(!IsEmpty())
        top--;
}
int findmaxlen(string s)
{
    int maxLength = 0;
    push(-1);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            push(i); // Push index onto the stack for '('
        }
        else
        {
            pop();
            if(IsEmpty()) // Remove the top '(' from stack for ')'
                push(i);
            else
                maxLength = max(maxLength, i - stack[top]);
        }
    }
    return maxLength;
}
int main()
{
    char val[100];
    cin>>val;
    int len=findmaxlen(val);
    cout<<len;
    return 0;
}
/*
()()))() - 4
)()()( - 4
((()()()())) - 12
*/

