#include <iostream>
#include <cstring>
using namespace std;

void table_of_hanoi(int n, char beg, char inter, char end)// ttranferring all disk from A to C
{
    if (n == 0)//condition for terminating the function
    {
        return;
    }
    table_of_hanoi(n - 1, beg, end, inter); //recursion
    cout << n << " disk from \"" << beg << "\" to \"" << end << "\"" << endl;
    table_of_hanoi(n - 1, inter, beg, end);
}

int main()
{
    int x;
    cout << "enter number of disks = ";
    cin >> x;
    table_of_hanoi(x, 'A', 'B', 'C'); // 'A', 'B' and 'C' are stacks or name of rods

    return 1;
}