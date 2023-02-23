#include <iostream>

using namespace std;

const int SIZE = 5;

class Stack
{
public:
    int top;
    int arr[SIZE];

    Stack()
    {
        top = -1;
    }

    // bool isStackFull();
    // bool isStackEmpty();
    // void push(int val);
    // int pop();
    // int peek();
    // void printStack();

    bool isStackFull()
    {
        if (top == SIZE - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

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

    void push(int val)
    {
        if (!isStackFull())
        {
            top++;
            arr[top] = val;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    int pop()
    {
        if (isStackEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 404;
        }
        else
        {
            int stored = arr[top];
            top--;
            return stored;
        }
    }

    int peek()
    {
        if (isStackEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 404;
        }
        else
        {
            int stored = arr[top];
            return stored;
        }
    }

    void printStack()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack stack1;
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(5);
    stack1.printStack();

    return 0;
}