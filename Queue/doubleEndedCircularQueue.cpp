#include <iostream>

using namespace std;

const int SIZE = 5;

struct deQ
{
    int f = -1;
    int r = -1;
    int q[SIZE];
};

deQ q;

void insertAtFront(int val)
{
    if ((q.f == 0 && q.r == SIZE - 1) || (q.f == q.r + 1))
    {
        cout << "overflow" << endl;
        return;
    }
    else if (q.f == -1 && q.r == -1)
    {
        q.f = q.r = 0;
        q.q[q.f] = val;
    }
    else if (q.f == 0 && q.r != SIZE - 1)
    {
        q.f = SIZE - 1;
        q.q[q.f] = val;
    }
    else
    {
        q.f--;
        q.q[q.f] = val;
    }
    cout << val << " inserted at front" << endl
         << endl;
}

void deleteFromRear()
{
    if (q.f == -1 && q.r == -1)
    {
        cout << "underflow" << endl;
        return;
    }
    else if (q.r == 0)
    {
        q.r = SIZE - 1;
    }
    else if (q.f == q.r)
    {
        q.f = q.r = -1;
    }
    else
    {
        q.r--;
    }
}

void enQueue(int val)
{
    if ((q.f == 0 && q.r == SIZE - 1) || (q.f == q.r + 1))
    {
        cout << "overflow" << endl;
        return;
    }
    else if (q.f == -1 && q.r == -1)
    {
        q.f = q.r = 0;
        q.q[q.r] = val;
    }
    else if (q.f != 0 && q.r == SIZE - 1)
    {
        q.r = 0;
        q.q[q.r] = val;
    }
    else
    {
        q.r++;
        q.q[q.r] = val;
    }
    cout << val << " inserted at rear" << endl
         << endl;
}

void deQueue()
{
    if (q.f == -1 && q.r == -1)
    {
        cout << "Underflow" << endl;
        return;
    }
    else if (q.f == q.r)
    {
        q.f = q.r = -1;
    }
    else if (q.f == SIZE - 1)
    {
        q.f = 0;
    }
    else
    {
        q.f++;
    }
}

void displayQueue()
{
    int f = q.f;
    int r = q.r;
    if (f == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    if (f <= r)
    {
        while (f <= r)
        {
            cout << q.q[f] << " ";
            f++;
        }
    }
    else
    {
        while (f <= SIZE - 1)
        {
            cout << q.q[f] << " ";
            f++;
        }
        f = 0;
        while (f <= r)
        {
            cout << q.q[f] << " ";
            f++;
        }
    }
    cout << endl;
}

int main()
{
    int userInput;
    int num;

    do
    {
        cout << "1. Insert at Front" << endl;
        cout << "2. Enqueue" << endl;
        cout << "3. Delete from Rear" << endl;
        cout << "4. Dequeue" << endl;
        cout << "5. Print Queue" << endl;
        cout << "6. Exit" << endl
             << endl;
        cout << "Enter choice: " << endl;
        cin >> userInput;

        switch (userInput)
        {
        case 1:
            cout << "Enter number: " << endl;
            cin >> num;
            insertAtFront(num);
            break;
        case 2:
            cout << "Enter number: " << endl;
            cin >> num;
            enQueue(num);
            break;
        case 3:
            deleteFromRear();
            break;
        case 4:
            deQueue();
            break;
        case 5:
            displayQueue();
            cout << endl;
            break;
        case 6:
            break;
        default:
            break;
        }

    } while (userInput != 6);
    return 0;
}