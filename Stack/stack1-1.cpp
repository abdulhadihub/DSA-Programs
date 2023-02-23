#include <iostream>

using namespace std;

const int SIZE = 4;

struct Stack
{
    int top = -1;
    int arr[SIZE];
};

bool isStackFull(Stack s)
{
    if (s.top == SIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isStackEmpty(Stack s)
{
    if (s.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(Stack s, int val)
{
    if (!isStackFull(s))
    {
        s.top++;
        s.arr[s.top] = val;
    }
    else
    {
        cout << "Stack overflow" << endl;
    }
}

int pop(Stack s)
{
    if (isStackEmpty(s))
    {
        cout << "Stack Underflow" << endl;
        return 404;
    }
    else
    {
        int stored = s.arr[s.top];
        s.top--;
        return stored;
    }
}

void printStack(Stack s)
{
    for (int i = 0; i <= s.top; i++)
    {
        cout << s.arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Stack stack1;
    push(stack1, 2);
    push(stack1, 3);
    push(stack1, 4);
    push(stack1, 5);
    push(stack1, 5);
    printStack(stack1);

    cout << "hello world";

    return 0;
}