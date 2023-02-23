#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class BST
{
private:
    node *root;

public:
    BST()
    {
        root = NULL;
    }
    node *getRoot()
    {
        return root;
    }
    void insert(int);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    node *search(node *, int);
    node *findMin(node *);
    node *findMax(node *);
    node *deleteNode(node *, int);
};

// Insert function
void BST::insert(int d)
{
    node *t = new node;
    node *parent;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    // is this a new tree?
    if (root == NULL)
        root = t;
    else
    {
        // Note: ALL insertions are as leaf nodes
        node *curr;
        curr = root;
        // Find the Node's parent
        while (curr)
        {
            parent = curr;
            if (t->data > curr->data)
                curr = curr->right;
            else
                curr = curr->left;
        }

        if (t->data < parent->data)
            parent->left = t;
        else
            parent->right = t;
    }
}

// Inorder traversal
void BST::inorder(node *p)
{
    if (p != NULL)
    {
        if (p->left)
            inorder(p->left);
        cout << p->data << " ";
        if (p->right)
            inorder(p->right);
    }
    else
        return;
}

// Preorder traversal
void BST::preorder(node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        if (p->left)
            preorder(p->left);
        if (p->right)
            preorder(p->right);
    }
    else
        return;
}

// Postorder traversal

void BST::postorder(node *p)
{
    if (p != NULL)
    {
        if (p->left)
            postorder(p->left);
        if (p->right)
            postorder(p->right);
        cout << p->data << " ";
    }
    else
        return;
}

// Search the tree for a node
node *BST::search(node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    else if (p->data == key)
    {
        return p;
    }
    else if (key < p->data)
    {
        return search(p->left, key);
    }
    else
    {
        return search(p->right, key);
    }
}

// Find the node with the minimum key
node *BST::findMin(node *p)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (p->left)
        return findMin(p->left);
    else
        return p;
}

// Find the node with the maximum key

node *BST::findMax(node *p)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (p->right)
        return findMax(p->right);
    else
        return p;
}

// Delete a node from the tree
node *BST::deleteNode(node *p, int key)
{
    node *curr;
    node *parent;
    bool isLeft;
    curr = root;
    parent = NULL;
    // Search for the node - Set its parent
    while (curr->data != key)
    {
        parent = curr;
        if (key > curr->data)
        {
            isLeft = false;
            curr = curr->right;
        }
        else
        {
            isLeft = true;
            curr = curr->left;
        }
        if (curr == NULL)
            return NULL;
    }
    // If i am here that means we have found the node
    // Case 1:  No child
    if (curr->left == NULL && curr->right == NULL)
    {
        if (curr == root) // tree has only root node
            root = NULL;
        if (isLeft == true)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    // Case 2 : One child
    else if (curr->right == NULL)
    {
        if (curr == root)
            root = curr->left;
        else if (isLeft)
            parent->left = curr->left;
        else
            parent->right = curr->left;
    }
    else if (curr->left == NULL)
    {
        if (curr == root)
            root = curr->right;
        else if (isLeft)
            parent->left = curr->right;
        else
            parent->right = curr->right;
    }
    else if (curr->left && curr->right)
    {
        // get successor of the node to be deleted (current)
        node *successor = findMin(curr->right);
        // connect parent of current to successor instead
        if (curr == root)
            root = successor;
        else if (isLeft)
            parent->left = successor;
        else
            parent->right = successor;
        // connect successor to current's left child
        successor->left = curr->left;
    }
    return curr;
}

int main()
{
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Print Nodes in Inorder
    cout << "Inorder Traversal: ";
    bst.inorder(bst.getRoot());
    cout << endl;

    // Print Nodes in Preorder
    cout << "Preorder Traversal: ";
    bst.preorder(bst.getRoot());
    cout << endl;

    // Print Nodes in Postorder
    cout << "Postorder Traversal: ";
    bst.postorder(bst.getRoot());
    cout << endl;

    // Search for node 40
    if (bst.search(bst.getRoot(), 40) != NULL)
        cout << "Element 40 found in the tree" << endl;
}
