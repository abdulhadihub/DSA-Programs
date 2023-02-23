#include <iostream>

using namespace std;

const int SIZE = 5;

class DoubleEndedCircularQueue
{
public:
    int f;
    int r;
    int arr[SIZE];

    DoubleEndedCircularQueue()
    {
        f = -1;
        r = -1;
    }

    void insertAtFront(int val)
    {
        if ((f == 0 && r == SIZE - 1) || (f == r + 1))
        {
            cout << "overflow" << endl;
            return;
        }
        else if (f == -1 && r == -1)
        {
            f = r = 0;
            arr[f] = val;
        }
        else if (f == 0 && r != SIZE - 1)
        {
            f = SIZE - 1;
            arr[f] = val;
        }
        else
        {
            f--;
            arr[f] = val;
        }
        cout << arr[f] << " inserted at front" << endl
             << endl;
    }

    void deleteFromRear()
    {
        if (f == -1 && r == -1)
        {
            cout << "underflow" << endl;
            return;
        }
        else if (r == 0)
        {
            r = SIZE - 1;
        }
        else if (f == r)
        {
            f = r = -1;
        }
        else
        {
            r--;
        }
    }

    void enQueue(int val)
    {
        if ((f == 0 && r == SIZE - 1) || (f == r + 1))
        {
            cout << "overflow" << endl;
            return;
        }
        else if (f == -1 && r == -1)
        {
            f = r = 0;
            arr[r] = val;
        }
        else if (f != 0 && r == SIZE - 1)
        {
            r = 0;
            arr[r] = val;
        }
        else
        {
            r++;
            arr[r] = val;
        }
        cout << val << " inserted at rear" << endl
             << endl;
    }

    void deQueue()
    {
        if (f == -1 && r == -1)
        {
            cout << "Underflow" << endl;
            return;
        }
        else if (f == r)
        {
            f = r = -1;
        }
        else if (f == SIZE - 1)
        {
            f = 0;
        }
        else
        {
            f++;
        }
    }

    void displayQueue()
    {
        int front = f;
        int rear = r;

        int f = front;
        int r = rear;
        if (f == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        if (f <= r)
        {
            while (f <= r)
            {
                cout << arr[f] << " ";
                f++;
            }
        }
        else
        {
            while (f <= SIZE - 1)
            {
                cout << arr[f] << " ";
                f++;
            }
            f = 0;
            while (f <= r)
            {
                cout << arr[f] << " ";
                f++;
            }
        }
        cout << endl;
    }
};

int main()
{
    DoubleEndedCircularQueue queue1;
    DoubleEndedCircularQueue queue2;

    queue1.deQueue();
    queue1.insertAtFront(2);
    queue1.insertAtFront(3);
    queue1.insertAtFront(4);
    queue1.enQueue(8);
    queue1.enQueue(19);
    queue1.enQueue(29);
    queue1.deQueue();
    queue1.deleteFromRear();
    queue1.displayQueue();

    queue2.deleteFromRear();
    queue2.insertAtFront(78);
    queue2.insertAtFront(7);
    queue2.displayQueue();

    return 0;
}