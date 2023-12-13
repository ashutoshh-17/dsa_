#include<stdlib.h>
#include<iostream>
#include<string.h>
#define max 30
using namespace std;
struct node
{
    char data;
    struct node* next;
};
class stack
{
    node* top;
    char x;
public:
    stack()
    {
        top = NULL;
    }
    int empty() //STACK IS EMPTY!!!
    {
        if (top == NULL)
        {
            return(1);
        }
        else
        {
            return(0);
        }
    }
    void push(char x)
    {
        node* p;
        p = new node;
        p->data = x;
        p->next = top;
        top = p;
    }
    char pop()
    {
        if (!empty())
        {
            node* p;
            p = new node;
            p = top;
            top = top->next;
            x = p->data;
            delete p;
            return(x);
        }
        else
        {
            return(0);
        }
    }
    char pop1()
    {
        if (!empty())
        {
            node* p;
            p = new node;
            p = top;
            x = p->data;
            return(x);
        }
        else
        {
            return(0);
        }
    }
};
int precedence(char x);
void infix_to_prefix(char infix[], char prefix[]);
int main()
{
    char infix[30], prefix[30];
                cout << "\nEnter the infix expression::" << endl;
                cin >> infix;
            infix_to_prefix(infix, prefix);
            cout << "\nPrefix expression is " << prefix << endl;
    return 0;
}

void infix_to_prefix(char infix[], char prefix[])
{
    stack s;
    node* top;
    char x;
    int i, j;
    char token;
    j = 0;
    for (i = 0; infix[i] != '\0'; i++)
    {
        token = infix[i];
        if (isalnum(token))
        {
            prefix[j++] = token;
        }
        else if (token == ')')
        {
            s.push(')');
        }
        else if (token == '(')
        {
            while ((x = s.pop()) != ')')
            {
                prefix[j++] = x;
            }
        }
        else
        {
            x = s.pop1();
            while (precedence(token) > precedence(x) && !s.empty())
            {
                x = s.pop();
                prefix[j++] = x;
            }
            s.push(token);
        }
}
while (!s.empty())
    {
        x = s.pop();
        prefix[j++] = x;
    }
    for (int i = 0; i < j / 2; i++) {
            char temp = prefix[i];
            prefix[i] = prefix[j - i - 1];
            prefix[j - i - 1] = temp;
    prefix[j] = '\0';
}
}
int precedence(char x)
{
    if (x == '(')
    {
        return(0);
    }
    if (x == '+' || x == '-')
    {
        return(1);
    }
    if (x == '*' || x == '/' || x == '%')
    {
        return(2);
    }
    return(3);
}

int evaluate(char x, int op1, int op2)
{
    if (x == '+')
        return(op1 + op2);
    if (x == '-')
        return(op1 - op2);
    if (x == '*')
        return(op1 * op2);
    if (x == '/')
        return(op1 / op2);
    if (x == '%')
        return(op1 % op2);
}