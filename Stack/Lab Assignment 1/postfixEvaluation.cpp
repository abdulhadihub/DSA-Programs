#include <iostream>
#include <cmath>

using namespace std;

int top = -1;
const int MAX = 20;
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
    char postfix[] = "623+-382/+*2^3+";
    // char postfix[] = "562+*124/-";
    int result, num1, num2;

    for (int i = 0; i < (sizeof(postfix) / sizeof(char)) - 1; i++)
    {
        if (!(postfix[i] == '^' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '+' || postfix[i] == '-'))
        {
            cout << "Pushing: " << postfix[i] << endl;
            push(postfix[i]);
            printStack();
        }
        else
        {
            switch (postfix[i])
            {
            case '^':
                num2 = pop();
                num1 = pop();
                result = pow(num1, num1);
                cout << num1 << postfix[i] << num2 << " = " << result << endl;
                push(result);
                break;

            case '*':
                num2 = pop();
                num1 = pop();
                result = num1 * num2;
                cout << num1 << postfix[i] << num2 << " = " << result << endl;
                push(result);
                break;

            case '/':
                num2 = pop();
                num1 = pop();
                result = num1 / num2;
                cout << num1 << postfix[i] << num2 << " = " << result << endl;
                push(result);
                break;

            case '+':
                num2 = pop();
                num1 = pop();
                result = num1 + num2;
                cout << num1 << postfix[i] << num2 << " = " << result << endl;
                push(result);
                break;

            case '-':
                num2 = pop();
                num1 = pop();
                result = num1 - num2;
                cout << num1 << postfix[i] << num2 << " = " << result << endl;
                push(result);
                break;

            default:
                cout << "Error" << endl;
            }
        }
    }

    if (top != 0)
    {
        cout << "Stack must contain only one element. ERROR!" << endl;
        printStack();
        cout << "Result of postfix Expression is: " << result << endl;
    }
    else
    {
        cout << "Result of postfix Expression is: " << result << endl;
    }

    return 0;
}