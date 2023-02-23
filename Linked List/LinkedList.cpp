#include<iostream>

using namespace std;

class LinkedList{
    public:
    struct node{
        int info;
        node* next;
};

node *List = NULL; // header pointer

void insertLinkedList(int val){ // insertion at beginning
    node* p;
    if(List == NULL){
        p = new node;
        p ->info=val;
        p->next = NULL;
        List = p;
    }
    else{
        p = new node;
        p-> info = val;
        p -> next = List;
        List = p;
    }
    cout<<"Inserted "<<val<<endl;
}

int deleteLinkedList(){ // deletion at beginning
    if(List == NULL){
        cout<<"No node to delete in linked list"<<endl;
        return 404;
    }
    else{
        node *p;
        p = List;
        List = p->next;
        int x = p->info;
        delete(p);
        cout<<"Deleted "<<x<<endl;
        return x;
    }
}

void peek(){
    if(List == NULL){
        cout<<"No node to display in linked list"<<endl;
        return;
    }
    else{
        cout<< List->info<<endl;
    }
}

void displayLinkedList(){ // display linked list
    if(List == NULL){
        cout<<"No node to print"<<endl;
        return;
    }

    node*p;
    p = List;
    cout<<"Linked List Contains:"<<endl;

    while(p != NULL){
        cout<<p->info<<" ";
        p = p-> next;
    }
    cout<<endl<<endl;
}
};

int main(){
   
    LinkedList list1;
    int userInput;
    int num;

   do{
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Print"<<endl;
        cout<<"4. Return"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter choice: "<<endl;
        cin>>userInput;

        switch(userInput){
        case 1:
            cout<<"Enter number: "<<endl;
            cin>>num;
            list1.insertLinkedList(num);
            break;
        case 2:
            list1.deleteLinkedList();
            break;
        case 3:
            list1.displayLinkedList();
            break;
        case 4:
            list1.peek();
            break;
        case 5:
            break;
        default:
        cout<<"Invalid Choice"<<endl;
            break;
        }
        cout<<endl;

    }while(userInput != 5);

    return 0;
}