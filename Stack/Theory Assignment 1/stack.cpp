#include <iostream>

using namespace std;

const int MAX = 5;
int top1 = -1;
int stack1[MAX]; // CHANGE DATA TYPE

int top2 = -1;
int stack2[MAX]; // CHANGE DATA TYPE

int top3 = -1;
int stack3[MAX]; // CHANGE DATA TYPE

bool isStackEmpty(int top)
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

bool isStackFull(int top)
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

void push(int stack[], int top, int val) // CHANGE DATA TYPE
{
    if (isStackFull(top))
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

int pop(int stack[], int top) // CHANGE DATA TYPE
{
    if (isStackEmpty(top))
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

void printStack(int stack[], int top)
{
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    push(stack1, top1, 5);
    push(stack1, top1, 5);
    push(stack1, top1, 5);
    cout << pop(stack1, top1) << endl;
    printStack(stack1, top1);

    push(stack2, top2, 2);
    push(stack2, top2, 2);
    push(stack2, top2, 2);
    cout << pop(stack2, top2) << endl;
    printStack(stack2, top2);

    push(stack3, top3, 3);
    push(stack3, top3, 3);
    push(stack3, top3, 3);
    cout << pop(stack3, top3) << endl;
    printStack(stack3, top3);

    return 0;
}