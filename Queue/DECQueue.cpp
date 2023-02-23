#include <iostream>

using namespace std;

const int SIZE = 5;

struct doubleEndedCircularQueue
{
    int f = -1;
    int r = -1;
    int arr[SIZE];
};

doubleEndedCircularQueue Queue1;

void insertAtFront(doubleEndedCircularQueue Queue, int val)
{
    if ((Queue.f == 0 && Queue.r == SIZE - 1) || (Queue.f == Queue.r + 1))
    {
        cout << "overflow" << endl;
        return;
    }
    else if (Queue.f == -1 && Queue.r == -1)
    {
        Queue.f = Queue.r = 0;
        Queue.arr[Queue.f] = val;
    }
    else if (Queue.f == 0 && Queue.r != SIZE - 1)
    {
        Queue.f = SIZE - 1;
        Queue.arr[Queue.f] = val;
    }
    else
    {
        Queue.f--;
        Queue.arr[Queue.f] = val;
    }
    cout << Queue.arr[Queue.f] << " inserted at front" << endl
         << endl;
}

void deleteFromRear(doubleEndedCircularQueue Queue)
{
    if (Queue.f == -1 && Queue.r == -1)
    {
        cout << "underflow" << endl;
        return;
    }
    else if (Queue.r == 0)
    {
        Queue.r = SIZE - 1;
    }
    else if (Queue.f == Queue.r)
    {
        Queue.f = Queue.r = -1;
    }
    else
    {
        Queue.r--;
    }
}

void enQueue(doubleEndedCircularQueue Queue, int val)
{
    if ((Queue.f == 0 && Queue.r == SIZE - 1) || (Queue.f == Queue.r + 1))
    {
        cout << "overflow" << endl;
        return;
    }
    else if (Queue.f == -1 && Queue.r == -1)
    {
        Queue.f = Queue.r = 0;
        Queue.arr[Queue.r] = val;
    }
    else if (Queue.f != 0 && Queue.r == SIZE - 1)
    {
        Queue.r = 0;
        Queue.arr[Queue.r] = val;
    }
    else
    {
        Queue.r++;
        Queue.arr[Queue.r] = val;
    }
    cout << val << " inserted at rear" << endl
         << endl;
}

void deQueue(doubleEndedCircularQueue Queue)
{
    if (Queue.f == -1 && Queue.r == -1)
    {
        cout << "Underflow" << endl;
        return;
    }
    else if (Queue.f == Queue.r)
    {
        Queue.f = Queue.r = -1;
    }
    else if (Queue.f == SIZE - 1)
    {
        Queue.f = 0;
    }
    else
    {
        Queue.f++;
    }
}

void displayQueue(doubleEndedCircularQueue Queue)
{
    int f = Queue.f;
    int r = Queue.r;
    if (f == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    if (f <= r)
    {
        while (f <= r)
        {
            cout << Queue.arr[f] << " ";
            f++;
        }
    }
    else
    {
        while (f <= SIZE - 1)
        {
            cout << Queue.arr[f] << " ";
            f++;
        }
        f = 0;
        while (f <= r)
        {
            cout << Queue.arr[f] << " ";
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
        cout << "2. Insert at Rear" << endl;
        cout << "3. Delete from Rear" << endl;
        cout << "4. Delete from Front" << endl;
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
            insertAtFront(Queue1, num);
            break;
        case 2:
            cout << "Enter number: " << endl;
            cin >> num;
            enQueue(Queue1, num);
            cout << num << " inserted at rear" << endl
                 << endl;
            break;
        case 3:
            deleteFromRear(Queue1);
            break;
        case 4:
            deQueue(Queue1);
            break;
        case 5:
            displayQueue(Queue1);
            cout << endl;
            break;
        case 6:
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
            break;
        }

    } while (userInput != 6);
    return 0;
}
