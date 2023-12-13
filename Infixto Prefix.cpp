/*
Infix to Prefix expression
Ram wants to design software to manage his company "Sunrise Basket". A part of this software design,
he wants to convert the given infix expression to prefix expression. He asked Janu to help on this code.
Janu is ready to help. Ram assured that he will give only five operators (*, /, +, -,^) and he use only single character in infix expression.
Also, Ram requirement is only with integer number and he won�t use any fractional numbers. Help Janu to complete the code.

Example
Input
K*L+M/N
Output
+*KL/MN

Explanation
The input infix expression is converted to a prefix expression using operator precedence.
Input Format
Infix expression as string in first line
Output Format
Prefix expression as shown in sample output

Sample Input
K*L+M/N
Sample Output
+*KL/MN

Sample Input
x^y/(5*z)+2
Sample Output
+/^xy*5z2
*/

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
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >='0' && c <= '9')) {
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
string infixToPrefix(string expr)
{
    reverse(expr.begin(),expr.end());
    for(int i=0;i<expr.length();i++)
    {
        if(expr[i] == '(')
        {
            expr[i]=')';
        }
        else if(expr[i] == ')')
        {
            expr[i]='(';
        }
    }
    string post = infixToPostfix(expr);
    reverse(post.begin(),post.end());
    return post;
}

int main()
{
    string infix_expr;
    cin >> infix_expr;
    string prefix_expr = infixToPrefix(infix_expr);
    cout <<prefix_expr << endl;
    return 0;
}
