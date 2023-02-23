#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

class bst
{
public:
    node *root = NULL;

    node *search(int data)
    {
        struct node *current = root;
        printf("Visiting elements: ");

        while (current->data != data)
        {

            if (current != NULL)
            {
                printf("%d ", current->data);

                // go to left tree
                if (current->data > data)
                {
                    current = current->leftChild;
                } // else go to right tree
                else
                {
                    current = current->rightChild;
                }

                // not found
                if (current == NULL)
                {
                    return NULL;
                }
            }
        }

        return current;
    }

    void insert(int data)
    {
        struct node *tempNode = new node;
        struct node *current = new node;
        struct node *parent = new node;

        tempNode->data = data;
        tempNode->leftChild = NULL;
        tempNode->rightChild = NULL;

        // if tree is empty
        if (root == NULL)
        {
            root = tempNode;
        }
        else
        {
            current = root;
            parent = NULL;

            while (1)
            {
                parent = current;

                // go to left of the tree
                if (data < parent->data)
                {
                    current = current->leftChild;
                    // insert to the left

                    if (current == NULL)
                    {
                        parent->leftChild = tempNode;
                        return;
                    }
                } // go to right of the tree
                else
                {
                    current = current->rightChild;

                    // insert to the right
                    if (current == NULL)
                    {
                        parent->rightChild = tempNode;
                        return;
                    }
                }
            }
        }
    }
};

int main()
{
    bst tree;
    tree.insert(50);
    tree.insert(40);
    tree.insert(30);
    tree.insert(65);

    node *found = tree.search(40);
    return 0;
}