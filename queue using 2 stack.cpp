/*Queue Using Two Stacks*/
#include<bits/stdc++.h>
using namespace std;
stack<int> s1,s2;
void enqueue(int x)
{
    s1.push(x);
}
void dequeue()
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s2.pop();
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}
void frontElement()
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    cout<<s2.top()<<endl;
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                int val;
                cin>>val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                frontElement();
                break;
        }
    }
    return 0;
}
