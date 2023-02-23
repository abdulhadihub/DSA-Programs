#include <iostream>
#include <string>

using namespace std;
const int MAX = 101;
struct Stack // stucture of stack 
{
    int arr[MAX];
    int top;
};
Stack stack1; //global declaration
bool isEmpty() // function to check wheter the stack is empty or not
{
    if (stack1.top == -1)
    {
        return true;
    }
    return false;
}
void push(int x) // function to push value on top of stack
{
    if (stack1.top == MAX - 1)
    {
        cout << "error - stack overflow"<<endl;
        return;
    }
    stack1.top++;
    stack1.arr[stack1.top] = x;
}
void pop() //function to pop or remover value from top of stack note: pop doesnot return anything according to defination
{
    if (isEmpty())
    {
        cout << "error - stack underflow"<<endl;
        return;
    }
    stack1.top--;
}
int toppop()//to return top value of stack
{
    return stack1.arr[stack1.top];
}
bool isOperand(char c)// funtion to verify the character is operand or not
{
    if (c >= '0' && c <= '9')
        return true;

    return false;
}
bool isOperator(char C)// funtion to verify the character is operator or not
{
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '^' || C == '%')
        return true;

    return false;
}
int evaluate(string postfix)
{
    int result;
    string val = "";
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperator(postfix[i]))
        {
            int value;
            int a = toppop();
            pop();
            int b = toppop();
            pop();
            switch (postfix[i]) //performing operation  
            {
            case '+':
            {
                value = b + a;
                break;
            }
            case '-':
            {
                value = b - a;
                break;
            }
            case '*':
            {
                value = b * a;
                break;
            }
            case '/':
            {
                value = b / a;
                break;
            }
            case '%':
            {
                value = b % a;
                break;
            }
            case '^':
            {
                value = b ^ a;
                break;
            }
            default:
                break;
            }
            push(value);
        }
        else if (postfix[i] == ' ' || postfix[i] == ',')
        {
            continue;//seperating with spaces and ','
        }
        else
        {
            while (isOperand(postfix[i]))//loop to get operand whether they are 1 digit or two digit
            {
                val += postfix[i];
                i++;
            }
            int value = stoi(val); // stoi converts string to integer
            push(value);
            val = "";//reusing val variable
        }
    }
    result = toppop();
    pop();
    return result;
}
int main()
{
    stack1.top=-1;
    string postfix;
    cout << "enter the postfix expression (numbers and operators must be seperated by \",\" ) = ";
    getline(cin, postfix);
    int result = evaluate(postfix);
    cout << "result is = " << result << endl;

    return 1;
}