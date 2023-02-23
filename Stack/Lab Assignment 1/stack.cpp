#include <iostream>

using namespace std;

int top = -1;
const int MAX = 5;
int stack[MAX]; // CHANGE DATA TYPE

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

void push(int val) // CHANGE DATA TYPE
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

int pop() // CHANGE DATA TYPE
{
    if (isStackEmpty())
    {
        cout << "Stack Underflow" << endl;
        return 0;
    }
    else
    {
        int val = stack[top]; // CHANGE DATA TYPE
        top--;
        // cout << "Popped " << val << endl;
        return val;
    }
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
    push(2);
    push(3);
    push(4);
    push(5);
    push(5);
    printStack();
    return 0;
}