#include <iostream>
using namespace std;

const int SIZE = 10;

class Stack
{
public:
    int top;
    int arr[SIZE];

    Stack()
    {
        top = -1;
    }

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

void selectionSort(int arr[], int n)
{
    int minj;
    int minx;
    for (int i = 0; i < n - 1; i++)
    {
        minj = i;
        minx = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < minx)
            {
                minj = j;
                minx = arr[j];
            }
        }
        arr[minj] = arr[i];
        arr[i] = minx;
    }
}

class HeapTree
{
public:
    const int maxSize = 20;
    int arr[20];
    int n = 0;
    Stack stack1;

    void insert(int val)
    {
        if (n < maxSize)
        {
            arr[n] = val;
            n++;
            // selectionSort(arr, n);
        }
    }

    void swapNum(int &a, int &b)
    {
        int t = a;
        a = b;
        b = t;
    }

    void heapify(int arr[], int n, int root)
    {
        int largest = root;
        int l = 2 * root + 1;
        int r = 2 * root + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != root)
        {
            swapNum(arr[root], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }

        for (int i = n - 1; i >= 0; i--)
        { // simulated deletion
            stack1.push(arr[0]);
            swapNum(arr[0], arr[i]);
            heapify(arr, i, 0); // shift down to run heapify on reduced array
        }
    }

    void printArray(int arr[], int n)
    {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main()
{
    HeapTree heap1;
    heap1.insert(12);
    heap1.insert(11);
    heap1.insert(13);
    heap1.insert(5);
    heap1.insert(6);
    heap1.insert(7);
    heap1.insert(4);
    heap1.heapSort(heap1.arr, heap1.n);
    cout << "Heap Tree is \n";
    for (int i = 0; i < heap1.n; i++)
    {
        cout << heap1.stack1.pop() << " ";
    }
}
