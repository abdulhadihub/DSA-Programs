#include <iostream>
using namespace std;
const int MAX = 101;
struct Stack
{
    int arr[MAX];
    int top;
};
Stack stack1;
bool isEmpty()
{
    if (stack1.top == -1)
    {
        return true;
    }
    return false;
}
void push(int x)
{
    if (stack1.top == MAX - 1)
    {
        cout << "error - stack overflow";
        return;
    }
    stack1.top++;
    stack1.arr[stack1.top] = x;
}
void pop()
{
    if (stack1.top == -1)
    {
        cout << "error - stack underflow";
        return;
    }
    stack1.top--;
}
int toppop()
{
    return stack1.arr[stack1.top];
}
void conversion(int num, int base)
{
    if (num < 0 || base <= 0)// checking whether inputs are correct or not
    {
        cout << "conversion can't be done";
        return;
    }
    while (num > 0)
    {
        push(num % base);// pushing remainders
        num = num / base;//replacing numbers with whole value
    }
    while (!(isEmpty()))// poping values
    {
        cout << toppop() << "  ";
        pop();
    }
    cout << endl;
}

int main()
{
    stack1.top = -1;
    int num, base;
    cout << "enter the number in decimal = ";
    cin >> num;
    cout << "enter the base = ";
    cin >> base;
    conversion(num, base);

    return 0;
}