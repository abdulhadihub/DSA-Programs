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
    char symbols[] = "[[{[]}]]";
    int i = 0;
    for (int i = 0; i < (sizeof(symbols) / sizeof(char)); i++)
    {
        if (symbols[i] == '{' || symbols[i] == '(' || symbols[i] == '[')
        {
            cout << "Pushed " << symbols[i] << endl;
            push(symbols[i]);
        }
        else if (symbols[i] == '}' || symbols[i] == ')' || symbols[i] == ']')
        {
            if (isStackEmpty())
            {
                cout << "Error" << endl;
            }
            else
            {
                if (pop() == symbols[i] - 2)
                {
                    cout << "Compared with " << symbols[i] << endl;
                    cout << "Balanced" << endl;
                }
                else
                {
                    cout << "Compared with " << symbols[i] << endl;
                    cout << "Unbalanced Expression" << endl;
                    break;
                }
            }
        }
    }

    if (!isStackEmpty())
    {
        cout << "Stack is not empty - Unbalanced Expression" << endl;
    }

    return 0;
}