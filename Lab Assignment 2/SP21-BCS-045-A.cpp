// SP21-BCS-045(A)-ABDUL HADI
#include <iostream>

using namespace std;

bool isPrime(int num); // FUNCTION TO FIND PRIME NUMBERS

class LinkedList
{
public:
    struct node
    {
        int info;
        node *next;
    };

    node *List = NULL;

    void insertAtFront(int val)
    { // insertion at beginning
        node *p;
        if (List == NULL)
        {
            p = new node;
            p->info = val;
            p->next = NULL;
            List = p;
        }
        else
        {
            p = new node;
            p->info = val;
            p->next = List;
            List = p;
        }
    }

    int deleteAtFront()
    { // deletion at beginning
        if (List == NULL)
        {
            cout << "No node to delete in linked list" << endl;
            return 404;
        }
        else
        {
            node *p;
            p = List;
            List = p->next;
            int x = p->info;
            delete (p);
            return x;
        }
    }

    void displayLinkedList()
    { // display linked list
        if (List == NULL)
        {
            cout << "No node to print" << endl;
            return;
        }

        node *p;
        p = List;
        cout << "Linked List Contains:" << endl;

        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl
             << endl;
    }

    int deleteAtEnd()
    {
        node *p;
        p = List;
        node *q;
        int x;

        if (List == NULL)
        {
            cout << "No node to delete" << endl;
            return 404;
        }
        else if (p->next == NULL)
        {
            x = p->info;
            delete (p);
            List = NULL;
            return x;
        }
        else
        {
            while (p->next != NULL)
            {
                q = p;
                p = p->next;
            }
            q->next = NULL;
            x = p->info;
            delete (p);
            return x;
        }
        delete (p);
        return x;
    }

    void deleteAtPoint(int point)
    {
        node *p;
        node *q;
        p = List;
        q = List;
        int x;

        if (List == NULL)
        {
            cout << "No node to delete" << endl;
            return;
        }
        else
        {
            while (p != NULL)
            {
                if (p->info == point)
                {
                    q->next = p->next;
                    x = p->info;
                    delete (p);
                    return;
                }
                else
                {
                    q = p;
                    p = p->next;
                }
            }
        }
    }

    int countNodes()
    {
        node *p;
        int nodes = 0;
        p = List;

        while (p != NULL)
        {
            nodes++;
            p = p->next;
        }
        return nodes;
    }

    void primeLinkedList(LinkedList list2) // FUNCTION FOR DELETING PRIME NUMBERS FROM ORIGINAL LIST & INSERTING THEM IN LIST 2
    {
        node *q = List;

        while (q != NULL)
        {
            if (isPrime(q->info))
            {
                list2.insertAtFront(q->info);

                if (q == List)
                {
                    q = q->next;
                    deleteAtFront();
                }
                else if (q->next == NULL)
                {
                    deleteAtEnd();
                    break;
                }
                else
                {
                    int point = q->info;
                    q = q->next;
                    deleteAtPoint(point);
                }
            }
            else
            {
                q = q->next;
            }
        }
        cout << "Prime numbers ";
        list2.displayLinkedList();
    }

    void singleSwap() // SWAP PAIRS OF ELEMENTS OF SINGLE LINKED LIST
    {
        node *p = List;
        node *q = p->next;
        int temp;
        int nodes = countNodes();

        if (nodes % 2 == 0)
        {
            while (true)
            {

                temp = p->info;
                p->info = q->info;
                q->info = temp;
                if (p->next->next == NULL)
                {
                    break;
                }
                p = p->next->next;
                q = p->next;
            }
        }
        else
        {
            while (true)
            {
                if (p->next == NULL)
                {
                    break;
                }
                temp = p->info;
                p->info = q->info;
                q->info = temp;
                p = p->next->next;
                q = p->next;
            }
        }
    }

    void reverseNode() // REVERSES NODE OF LINKED LIST
    {
        node *prev;
        node *current;
        node *next;

        prev = NULL;
        current = List;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        List = prev;
    }
};

class DoublyLinkedList
{
public:
    struct node
    {
        int info;
        node *next;
        node *prev;
    };

    node *List = NULL; // header pointer

    void insertAtFront(int val)
    { // insertion at beginning
        node *p;
        if (List == NULL)
        {
            p = new node;
            p->info = val;
            p->next = NULL;
            p->prev = NULL;
            List = p;
        }
        else
        {
            p = new node;
            p->info = val;
            p->next = List;
            p->prev = NULL;
            (p->next)->prev = p;
            List = p;
        }
    }

    int deleteAtFront()
    { // deletion at beginning
        node *p;
        p = List;
        if (List == NULL)
        {
            return 404;
        }
        else if (p->next == NULL)
        {
            List = NULL;
            int x = p->info;
            delete (p);
            return x;
        }
        else
        {
            List = p->next;
            (p->next)->prev = NULL;
            int x = p->info;
            delete (p);
            return x;
        }
    }

    void displayLinkedList()
    { // display linked list
        if (List == NULL)
        {
            cout << "No node to print" << endl;
            return;
        }

        node *p;
        p = List;
        cout << "Linked List Contains:" << endl;

        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl
             << endl;
    }

    int countNodes()
    {
        node *p;
        int nodes = 0;
        p = List;

        while (p != NULL)
        {
            nodes++;
            p = p->next;
        }
        return nodes;
    }

    void doublySwap() // SWAP PAIRS OF ELEMENTS OF DOUBLY LINKED LIST
    {
        node *p;
        p = List->next;
        int temp;
        int nodes = countNodes();

        if (nodes % 2 == 0)
        {
            while (true)
            {

                temp = p->prev->info;
                p->prev->info = p->info;
                p->info = temp;
                if (p->next == NULL)
                {
                    break;
                }
                p = p->next->next;
            }
        }
        else
        {
            while (true)
            {
                temp = p->prev->info;
                p->prev->info = p->info;
                p->info = temp;
                if (p->next->next == NULL)
                {
                    break;
                }
                p = p->next->next;
            }
        }
    }
};

int main()
{

    LinkedList list1;
    LinkedList list2;
    DoublyLinkedList doublyList1;
    int userInput;
    int num;

    // list1.insertAtFront(2);
    // list1.insertAtFront(7);
    // list1.insertAtFront(9);
    // list1.insertAtFront(13);
    // list1.insertAtFront(6);
    // list1.insertAtFront(17);

    // doublyList1.insertAtFront(2);
    // doublyList1.insertAtFront(7);
    // doublyList1.insertAtFront(9);
    // doublyList1.insertAtFront(13);
    // doublyList1.insertAtFront(6);
    // doublyList1.insertAtFront(17);

    do
    {
        cout << "1. Insert at Front" << endl;
        cout << "2. Swap pair wise elements of SINGLE linked list" << endl;
        cout << "3. Swap pair wise elements of DOUBLY linked list" << endl;
        cout << "4. Reverse of a node of single linked list" << endl;
        cout << "5. Create Prime Number linked list" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: " << endl;
        cin >> userInput;

        switch (userInput)
        {
        case 1:
            cout << "Enter number: " << endl;
            cin >> num;
            list1.insertAtFront(num);
            doublyList1.insertAtFront(num);
            list1.displayLinkedList();
            break;
        case 2:
            cout << "Before operation SINGLE ";
            list1.displayLinkedList();
            cout << "After operation SINGLE ";
            list1.singleSwap();
            list1.displayLinkedList();
            break;
        case 3:
            cout << "Before operation DOUBLY ";
            doublyList1.displayLinkedList();
            cout << "After operation DOUBLY ";
            doublyList1.doublySwap();
            doublyList1.displayLinkedList();
            break;
        case 4:
            cout << "Before operation ";
            list1.displayLinkedList();
            cout << "After operation ";
            list1.reverseNode();
            list1.displayLinkedList();
            break;
        case 5:
            cout << "Before operation ";
            list1.displayLinkedList();
            cout << "After operation ";
            list1.primeLinkedList(list2);
            cout << "Original ";
            list1.displayLinkedList();
            break;
        case 6:
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
        cout << endl;

    } while (userInput != 6);

    return 0;
}

bool isPrime(int num) // FUNCTION TO FIND PRIME NUMBERS
{
    if (num <= 1)
    {
        return false;
    }
    else
    {
        int testNum = 2;

        while (testNum < num)
        {
            if (num % testNum == 0)
            {
                return false;
            }
            else
            {
                testNum++;
            }
        }
        return true;
    }
}
