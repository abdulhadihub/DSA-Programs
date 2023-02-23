#include <iostream>

using namespace std;

class CircularLinkedList
{
public:
    struct node
    {
        int info;
        node *next;
    };

    node *List = NULL; // header pointer

    void insertAtFront(int val)
    { // insertion at beginning
        node *p;
        node *q;
        if (List == NULL)
        {
            p = new node;
            p->info = val;
            List = p;
            p->next = List;
        }
        else
        {
            q = List;
            while (q->next != List)
            {
                q = q->next;
            }
            p = new node;
            p->info = val;
            p->next = List;
            List = p;
            q->next = List;
        }
        cout << "Inserted " << val << " at front" << endl;
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
            node *q;
            p = List;
            q = List;
            int x;
            while (q->next != List)
            {
                q = q->next;
            }
            List = p->next;
            q->next = List;
            x = p->info;
            delete (p);
            cout << "Deleted " << x << " at front" << endl;
            return x;
        }
    }

    void peek()
    {
        if (List == NULL)
        {
            cout << "No node to display in linked list" << endl;
            return;
        }
        else
        {
            cout << List->info << endl;
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

        do
        {
            cout << p->info << " ";
            p = p->next;
        } while (p != List);

        cout << endl
             << endl;
    }

    void insertAtEnd(int val)
    {
        node *p;
        node *q;

        if (List == NULL)
        {
            p = new node;
            p->info = val;
            List = p;
            p->next = List;
        }
        else
        {
            q = List;
            while (q->next != List)
            {
                q = q->next;
            }
            p = new node;
            p->info = val;
            q->next = p;
            p->next = List;
        }
        cout << "Inserted " << val << " at end" << endl;
    }

    int deleteAtEnd()
    {
        node *p;
        node *q;
        p = List;
        q = List;
        int x;

        if (List == NULL)
        {
            cout << "No node to delete" << endl;
            return 404;
        }
        else if (p->next == List)
        {
            x = p->info;
            delete (p);
            cout << "Deleted " << x << " at end" << endl;
            List = NULL;
            return x;
        }
        else
        {
            while (q->next != List)
            {
                p = q;
                q = q->next;
            }
            p->next = List;
            x = q->info;
            delete (q);
            cout << "Deleted " << x << " at end" << endl;
            return x;
        }
    }

    void insertAtPoint(int point, int val)
    {
        node *p;
        node *q;
        q = List;
        if (List == NULL)
        {
            p = new node;
            p->info = val;
            p->next = NULL;
            List = p;
        }
        else
        {
            do
            {
                if (q->info == point)
                {
                    p = new node;
                    p->info = val;
                    p->next = q->next;
                    q->next = p;
                    cout << "Inserted " << val << endl;
                }
                q = q->next;
            } while (q->next != List);
        }
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
            do
            {
                if (p->info == point)
                {
                    q->next = p->next;
                    x = p->info;
                    delete (p);
                    cout << "Deleted " << x << endl;
                    // return x;
                }
                else
                {
                    q = p;
                    p = p->next;
                }
            } while (p->next != List);
        }
    }

    int countNodes()
    {
        if (List == NULL)
        {
            return 0;
        }

        node *p;
        int nodes = 0;
        p = List;

        do
        {
            nodes++;
            p = p->next;
        } while (p != List);
        cout << "Total number of nodes in list are: " << nodes << endl;
        return nodes;
    }

    void searchList(int val)
    {
        if (List == NULL)
        {
            return;
        }

        node *p;
        node *q;
        p = List;
        q = List;

        int node = 0;
        bool flag = false;

        do
        {
            if (p->info == val)
            {
                cout << "Value is at node: " << node + 1 << endl;
                flag = true;
            }
            q = p;
            p = p->next;
            node++;
        } while (p != List);

        if (!flag)
        {
            cout << "Value is not in linked list" << endl;
        }
    }

    void sortList(int input)
    {

        if (List == NULL)
        {
            return;
        }

        int temp;
        node *q;
        node *p;
        p = List;
        q = p->next;
        if (input == 1)
        {
            cout << "List sorted in Ascending" << endl;
            while (p->next != List)
            {
                while (q != List)
                {
                    if (q->info < p->info)
                    {
                        temp = q->info;
                        q->info = p->info;
                        p->info = temp;
                    }
                    q = q->next;
                }
                p = p->next;
                q = p->next;
            }
        }
        else
        {
            cout << "List sorted in Descending" << endl;
            while (p->next != List)
            {
                while (q != List)
                {
                    if (q->info > p->info)
                    {
                        temp = q->info;
                        q->info = p->info;
                        p->info = temp;
                    }
                    q = q->next;
                }
                p = p->next;
                q = p->next;
            }
        }
    }

    void mergeLists(node *List2)
    {
        node *p = List;
        node *q = List2;

        while (p->next != List)
        {
            p = p->next;
        }
        p->next = List2;

        while (q->next != List2)
        {
            q = q->next;
        }
        q->next = List;
    }
};

// **********************************************************************************************************************
// **********************************************************************************************************************
// **********************************************************************************************************************
// **********************************************************************************************************************
// **********************************************************************************************************************

class LinkedList
{
public:
    struct node
    {
        int info;
        node *next;
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
            List = p;
        }
        else
        {
            p = new node;
            p->info = val;
            p->next = List;
            List = p;
        }
        cout << "Inserted " << val << " at front" << endl;
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
            cout << "Deleted " << x << " at front" << endl;
            return x;
        }
    }

    void peek()
    {
        if (List == NULL)
        {
            cout << "No node to display in linked list" << endl;
            return;
        }
        else
        {
            cout << List->info << endl;
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

    void insertAtEnd(int val)
    {
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
            node *q;
            q = List;
            while (q->next != NULL)
            {
                q = q->next;
            }
            p = new node;
            p->info = val;
            p->next = NULL;
            q->next = p;
        }
        cout << "Inserted " << val << " at end" << endl;
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
            cout << "Deleted " << x << " at end" << endl;
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
            cout << "Deleted " << x << " at end" << endl;
            return x;
        }
        delete (p);
        cout << "Deleted " << x << " at end" << endl;
        return x;
    }

    void insertAtPoint(int point, int val)
    {
        node *p;
        node *q;
        q = List;
        if (List == NULL)
        {
            p = new node;
            p->info = val;
            p->next = NULL;
            List = p;
        }
        else
        {
            while (q->next != NULL)
            {
                if (q->info == point)
                {
                    p = new node;
                    p->info = val;
                    p->next = q->next;
                    q->next = p;
                    cout << "Inserted " << val << endl;
                }
                q = q->next;
            }
        }
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
            while (p->next != NULL)
            {
                if (p->info == point)
                {
                    q->next = p->next;
                    x = p->info;
                    delete (p);
                    cout << "Deleted " << x << endl;
                    // return x;
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
        cout << "Total number of nodes in list are: " << nodes << endl;
        return nodes;
    }

    void searchList(int val)
    {
        node *p;
        node *q;
        p = List;
        q = List;

        int node = 0;
        bool flag = false;

        while (p != NULL)
        {
            if (p->info == val)
            {
                cout << "Value is at node: " << node + 1 << endl;
                flag = true;
            }
            q = p;
            p = p->next;
            node++;
        }
        if (!flag)
        {
            cout << "Value is not in linked list" << endl;
        }
    }

    void sortList(int input)
    {
        int temp;
        node *q;
        node *p;
        p = List;
        q = p->next;
        if (input == 1)
        {
            cout << "List sorted in Ascending" << endl;
            while (p->next != NULL)
            {
                while (q != NULL)
                {
                    if (q->info < p->info)
                    {
                        temp = q->info;
                        q->info = p->info;
                        p->info = temp;
                    }
                    q = q->next;
                }
                p = p->next;
                q = p->next;
            }
        }
        else
        {
            cout << "List sorted in Descending" << endl;
            while (p->next != NULL)
            {
                while (q != NULL)
                {
                    if (q->info > p->info)
                    {
                        temp = q->info;
                        q->info = p->info;
                        p->info = temp;
                    }
                    q = q->next;
                }
                p = p->next;
                q = p->next;
            }
        }
    }

    void mergeLists(node *List2)
    {
        node *p = List;

        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = List2;
    }
};

int main()
{

    CircularLinkedList list1;
    int userInput;
    int num;
    int point;

    // LinkedList list2;
    // list2.insertAtEnd(6);
    // list2.insertAtEnd(7);
    // list2.insertAtEnd(8);

    do
    {
        cout << "1. Insert at Front" << endl;
        cout << "2. Delete at Front" << endl;
        cout << "3. Insert at End" << endl;
        cout << "4. Delete at End" << endl;
        cout << "5. Insert at specific point" << endl;
        cout << "6. Delete at specific point" << endl;
        cout << "7. Count total nodes in list" << endl;
        cout << "8. Search list for specific value" << endl;
        cout << "9. Sort List in ascending Order" << endl;
        cout << "10. Merge List" << endl;
        cout << "11. Display List" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter choice: " << endl;
        cin >> userInput;

        switch (userInput)
        {
        case 1:
            cout << "Enter number: " << endl;
            cin >> num;
            list1.insertAtFront(num);
            list1.displayLinkedList();
            break;
        case 2:
            list1.deleteAtFront();
            list1.displayLinkedList();
            break;
        case 3:
            cout << "Enter number: " << endl;
            cin >> num;
            list1.insertAtEnd(num);
            list1.displayLinkedList();
            break;
        case 4:
            list1.deleteAtEnd();
            list1.displayLinkedList();
            break;
        case 5:
            cout << "Enter point to insert at: " << endl;
            cin >> point;
            cout << "Enter number to insert: " << endl;
            cin >> num;
            list1.insertAtPoint(point, num);
            list1.displayLinkedList();
            break;
        case 6:
            cout << "Enter point to Delete at: " << endl;
            cin >> point;
            list1.deleteAtPoint(point);
            list1.displayLinkedList();
            break;
        case 7:
            list1.countNodes();
            break;
        case 8:
            cout << "Enter value to search for: " << endl;
            cin >> num;
            list1.searchList(num);
            break;
        case 9:
            cout << "Enter 1 for Ascending\nEnter 2 for Descending\nEnter choice: ";
            cin >> num;
            list1.sortList(num);
            list1.displayLinkedList();
            break;
        case 10:
            /*
            cout<<"List 1"<<endl;
            list1.displayLinkedList();
            cout<<"List 2"<<endl;
            list2.displayLinkedList();
            list1.mergeLists(list2.List);
            cout<<"Lists Merged"<<endl;
            list1.displayLinkedList();
            */
            break;
        case 11:
            list1.displayLinkedList();
            break;
        case 12:
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
        cout << endl;

    } while (userInput != 12);

    return 0;
}
