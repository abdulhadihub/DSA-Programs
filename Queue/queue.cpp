#include <iostream>

using namespace std;

int const SIZE = 4;

struct queue
{
    int f = -1;
    int r = -1;
    int q[SIZE];
};

queue q1;

bool isFull()
{
    if ((q1.r == -1 && q1.f == 0) || (q1.f == q1.r + 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{
    if (q1.f == -1 && q1.r == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enQueue(int val)
{
    if (isFull())
    {
        cout << "Queue is full" << endl;
        return;
    }
    else
    {
        if (q1.r == SIZE - 1 && q1.f != 0)
        {
            q1.r = -1;
            q1.r++;
            q1.q[q1.r] = val;
            if (q1.f == -1)
            {
                q1.f = 0;
            }
        }
    }
}

int deQueue()
{
    int del;
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
    else
    {
        del = q1.q[q1.f];
        q1.f++;
        if (q1.f == SIZE)
        {
            q1.f = 0;
            if (q1.f - 1 == q1.r)
            {
                q1.f = q1.r = -1;
            }
        }
    }
}

int main()
{

    return 0;
}