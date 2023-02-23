#include <iostream>

using namespace std;

int top = -1;
const int MAX = 20;
char stack[MAX];

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
{
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
{
    if (isStackEmpty())
    {
        cout << "Stack Underflow" << endl;
        return 'X';
    }
    else
    {
        char val = stack[top];
        top--;
        cout << "Popped " << val << " ";
        return val;
    }
}

void printStack()
{
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << endl;
    }
}

int main()
{
    char symbols[] = "A+(B*C-(D/E^F)*G)*H";
    string postfix = "";
    char val;

    for (int i = 0; i < (sizeof(symbols) / sizeof(char)); i++)
    {
        if (symbols[i] == '+' || symbols[i] == '-' || symbols[i] == '/' || symbols[i] == '*' || symbols[i] == '^')
        {
            if (isStackEmpty())
            {
                push(symbols[i]);
            }
            else
            {
                val = pop();
            }
        }
        else if (symbols[i] == '{' || symbols[i] == '(' || symbols[i] == '[')
        {
            push(symbols[i]);
        }
        else
        {
            postfix += symbols[i];
        }
    }

    return 0;
}