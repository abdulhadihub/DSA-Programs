#include <iostream>

using namespace std;

const int MAX = 20;
int top = -1;
char stack[MAX]; // CHANGE DATA TYPE

bool isStackEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isStackFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char val)
{ // CHANGE DATA TYPE
    if (isStackFull())
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

char pop()
{ // CHANGE DATA TYPE
    if (isStackEmpty())
    {
        cout << "Stack Underflow" << endl;
        return 0;
    }
    else
    {
        char val = stack[top]; // CHANGE DATA TYPE
        top--;
        cout << "popped " << val << endl;
        return val;
    }
}

char popShow()
{
    char val = stack[top]; // CHANGE DATA TYPE
    return val;
}

void printStack()
{
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    char infix[] = "A+(B*C-(D/E^F)*G)*H";
    string postfix = "";
    char val2;
    char val;

    for (int i = 0; i < (sizeof(infix) / sizeof(char)); i++)
    {
        switch (infix[i])
        {
        case '(':
            push(infix[i]);
            break;
        case ')':
            val = popShow();
            if (val != ')' - 1)
            {
                postfix += pop();
            }
            break;
        case '^':
            if (stack[top] == '^')
            {
                cout << "hello" << endl;
                postfix += pop();
            }
            push(infix[i]);
            break;
        case '*':
            if (stack[top] == '^' || stack[top] == '/' || stack[top] == '*')
            {
                cout << "hello" << endl;
                postfix += pop();
            }
            push(infix[i]);
            break;
        case '/':
            if (stack[top] == '^' || stack[top] == '/' || stack[top] == '*')
            {
                postfix += pop();
            }
            push(infix[i]);
            break;
        case '+':
            if (stack[top] == '^' || stack[top] == '/' || stack[top] == '*' || stack[top] == '+' || stack[top] == '-')
            {
                postfix += pop();
            }
            push(infix[i]);
            break;
        case '-':
            if (stack[top] == '^' || stack[top] == '/' || stack[top] == '*' || stack[top] == '+' || stack[top] == '-')
            {
                postfix += pop();
            }
            push(infix[i]);
            break;
        default:
            postfix += infix[i];
        }
    }
    while (!isStackEmpty())
    {
        postfix += pop();
    }

    cout << postfix << endl;

    return 0;
}