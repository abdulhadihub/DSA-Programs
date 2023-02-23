#include <iostream>
using namespace std;

int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int binarySearch(int array[], int start, int end, int key)
{
    if (start <= end)
    {
        int mid = (start + (end - start) / 2); // mid location of the list
        if (array[mid] == key)
            return mid;
        if (array[mid] > key)
            return binarySearch(array, start, mid - 1, key);
        return binarySearch(array, mid + 1, end, key);
    }
    return -1;
}

void display(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void insertionSort(int *array, int size)
{
    int key, j;

    for (int i = 1; i < size; i++)
    {
        key = array[i]; // take value
        j = i;

        while (j > 0 && array[j - 1] > key)
        {
            array[j] = array[j - 1];
            j--;
        }

        array[j] = key; // insert in right place
    }
}

void swapping(int &a, int &b)
{ // swap the content of a and b
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void selectionSort(int *array, int size)
{
    int i, j, imin;

    for (i = 0; i < size - 1; i++)
    {
        imin = i; // get index of minimum data
        for (j = i + 1; j < size; j++)
            if (array[j] < array[imin])
                imin = j;
        // placing in correct position
        swap(array[i], array[imin]);
    }
}

int partition(int *array, int lower, int upper)
{
    // Hoare partitioning technique to find correct location for pivot
    int pivot, start, end;
    pivot = array[lower]; // first element as pivot
    start = lower;
    end = upper;

    while (start < end)
    {
        while (array[start] <= pivot && start < end)
        {
            start++; // start pointer moves to right
        }

        while (array[end] > pivot)
        {
            end--; // end pointer moves to left
        }

        if (start < end)
        {
            swap(array[start], array[end]); // swap smaller and bigger element
        }
    }

    array[lower] = array[end];
    array[end] = pivot;
    return end;
}

void quickSort(int *array, int left, int right)
{
    int q;

    if (left < right)
    {
        q = partition(array, left, right);
        quickSort(array, left, q - 1);  // sort left sub-array
        quickSort(array, q + 1, right); // sort right sub-array
    }
}

void merge(int *array, int l, int m, int r)
{
    int i, j, k, nl, nr;
    // size of left and right sub-arrays
    nl = m - l + 1;
    nr = r - m;
    int larr[nl], rarr[nr];

    // fill left and right sub-arrays
    for (i = 0; i < nl; i++)
        larr[i] = array[l + i];
    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    // marge temp arrays to real array

    while (i < nl && j < nr)
    {
        if (larr[i] <= rarr[j])
        {
            array[k] = larr[i];
            i++;
        }
        else
        {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }

    while (i < nl)
    { // extra element in left array
        array[k] = larr[i];
        i++;
        k++;
    }

    while (j < nr)
    { // extra element in right array
        array[k] = rarr[j];
        j++;
        k++;
    }
}

void mergeSort(int *array, int l, int r)
{
    int m;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        // Sort first and second arrays
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

int main()
{

    return 0;
}