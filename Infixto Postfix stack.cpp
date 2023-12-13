#include <bits/stdc++.h>
using namespace std;

int top=-1;
char st[100];
void push(char ch)
{
    st[++top]=ch;
}
void pop()
{
    top--;
}
int getPrecedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1; // Lower precedence
}

string infixToPostfix(string infix) {
    string postfix;
    for (char c : infix)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
           (c >='0' && c <= '9')) 
        {
            postfix += c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')')
        {
            while (top!=-1 && st[top] != '(')
            {
                postfix += st[top];
                pop();
            }
            pop();
        }
        else
        {
            while (top!=-1 && getPrecedence(c) <= getPrecedence(st[top]))
            {
                postfix += st[top];
                pop();
            }
            push(c);
        }
    }
    while (top!=-1)
    {
        postfix += st[top];
        pop();
    }
    return postfix;
}


int main()
{
    string infix_expr;
    cin >> infix_expr;
    string postfix_expr = infixToPostfix(infix_expr);
    cout <<postfix_expr << endl;
    return 0;
}
