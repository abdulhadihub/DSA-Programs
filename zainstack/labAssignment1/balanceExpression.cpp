#include <iostream>
#include <string>
using namespace std;

#define size 100
/// here stack is implemented usinf struct you can also implement it using an array or using a class
struct Stack1
{
    int stackint[size];
    char stackchar[size];
    int top;

} S;
// this function is defined to check whether the stack is empty or not it will further be used in pop function
bool isempty()
{
    if (S.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// this function is used to push char   elements in the stack
void pushChar(char a)
{
    if (S.top >= -1 && S.top < size - 1)
    {
        S.top++;
        S.stackchar[S.top] = a;
    }
    else
    {
        cout << "Stck overflown" << endl;
    }
}
// this function is used to push int elements in the stack
void pushInt(int a)
{
    if (S.top >= -1 && S.top < size - 1)
    {
        S.top++;
        S.stackint[S.top] = a;
    }
    else
    {
        cout << "Stck overflown" << endl;
    }
}

// this function is used to pop the  elements from the stack.isempty is also used here to check whther stack is empty
void pop()
{
    if (isempty())
    {
        cout << "Stack UnderFlown" << endl;
    }
    else
    {
        S.top--;
    }
}
// display function displays the int elements in stackint without poping them
void displayInt()
{
    if (S.top > -1 && S.top < size)
    {
        for (int i = S.top; i > -1; i--)
        {
            cout << S.stackint[i];
        }
    }
    else
    {
        cout << "Stack UnderFlow!!" << endl;
    }
}
// display function displays the char elements in stackchar without poping them
void displayChar()
{
    if (S.top > -1 && S.top < size)
    {
        for (int i = S.top; i > -1; i--)
        {
            cout << S.stackchar[i];
        }
    }
    else
    {
        cout << "Stack UnderFlow!!" << endl;
    }
}
// to check top element on stackchar
void ontopChar()
{
    if (S.top > -1 && S.top < size)
    {
        cout << S.stackchar[S.top];
    }
}
// to check top element on stackint
void ontopInt()
{
    if (S.top > -1 && S.top < size)
    {
        cout << S.stackint[S.top];
    }
}
// it is base conversion function from decimal to binary
void DecToBin(int n)
{
    int rem;
    while (n > 0)
    {
        rem = n % 2;
        n = (n - rem) / 2;
        pushInt(rem);
    }

    displayInt();
}
// this function is used for checking the balance of braces in an expression
void isBalanced(string a)
{

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '{' || a[i] == '(' || a[i] == '[')
        {
            pushChar(a[i]);
        }
        else if (a[i] == '}' || a[i] == ')' || a[i] == ']')
        {
            if (S.stackchar[S.top] == '{' && a[i] == '}')
            {
                pop();
            }
            else if (S.stackchar[S.top] == '(' && a[i] == ')')
            {
                pop();
            }
            else if (S.stackchar[S.top] == '[' && a[i] == ']')
            {
                pop();
            }
        }
        else
        {
            break;
        }
    }
    if (S.top == -1)
    {
        cout << "balanced expression." << endl;
    }
    else
    {
        cout << "unbalanced expression." << endl;
    }
}
// for evaluation these functions are used to check whether the input expression is operand or operator
bool isOperand(char c)
{
    if (c >= '0' && c <= '9')
        return true;

    return false;
}
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
        return true;

    return false;
}
// this is the main evaluation function
int evaluate(string postfix)
{

    int result;
    string val = "";
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperator(postfix[i]))
        {
            int value;
            int a = S.stackint[S.top];
            pop();
            int b = S.stackint[S.top];
            pop();
            if (postfix[i] == '+')
            {
                value = b + a;
            }
            else if (postfix[i] == '-')
            {
                value = b - a;
            }
            else if (postfix[i] == '*')
            {
                value = b * a;
            }
            else if (postfix[i] == '/')
            {
                value = b / a;
            }
            else if (postfix[i] == '%')
            {
                value = b % a;
            }
            else if (postfix[i] == '^')
            {
                value = b ^ a;
            }
            pushInt(value);
        }
        else if (postfix[i] == ' ' || postfix[i] == ',')
        {
            continue;
        }
        else
        {
            while (isOperand(postfix[i]))
            {
                val = val + postfix[i];
                i++;
            }
            int value = (stoi(val));
            pushInt(value);
            val = "";
        }
    }
    result = S.stackint[S.top];
    pop();
    return result;
}
int main()
{

    int n;
    cout << "press 1 for base conversion\n";
    cout << "press 2 for balance symbols\n";
    cout << "press 3 for postfix evaluation\n";
    cin >> n;
    if (n == 1)
    {
        S.top = -1;
        int num;
        cout << "Enter decimal number ";
        cin >> num;
        DecToBin(num);
    }
    else if (n == 2)
    {
        S.top = -1;
        string exp;
        cin.clear();
        cin.ignore();
        cout << "Enter expression = ";
        getline(cin, exp);
        isBalanced(exp);
    }
    else if (n == 3)
    {
        S.top = -1;
        cin.clear();
        cin.ignore();
        string postfix;
        cout << "enter the postfix expression and seperate it with a comma  ";
        getline(cin, postfix);
        int res = evaluate(postfix);
        cout << "the evaluated expression is  " << res << endl;
    }

    return 0;
}