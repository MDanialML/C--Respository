#include <iostream>
using namespace std;

//creating a node
class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout <<"Memory freedup for value: "<<value<<endl;
    }
};

//node insertion in singly circular link list
void insertNode(Node* &tail,int element,int data)
{
    //link list is empty
    if(tail == NULL)
    {   
        // cout<<"Initial ko bolny do zra"<<endl;
        Node* newNode = new Node(data);
        tail = newNode;
        tail->next = newNode;
    }
    else{
        //for non empty link list
        //assume we found element
        Node* current = tail;
        while(current->data != element)
        {
            current = tail->next;
        }
        Node* newNode = new Node(data);
        newNode->next = current->next;
        current->next = newNode;
        // cout<<"Yahan tk kitni bar ayy"<<endl;
    }
}

//printing nodes
void printNode(Node* tail)
{
    Node* temp = tail;
    do{
        cout << tail->data<<",";
        tail = tail->next;
    }while(tail->next != temp);
    cout <<endl;
}
//delete node 
void deleteNode(Node* &tail,int element)
{
    //empty list
    if(tail == NULL)
    {
        cout <<"Datastructure is empty double check before performing any operation"<<endl;
        return;
    }
    else
    {
        Node* previous = tail;
        Node* current = tail->next;
        while(current->data != element)
        {
            previous = current;
            current = current->next;
        }
        previous->next= current->next;
        current->next = NULL;
        delete current;
    }
    
}

int main()
{
    Node* tail = NULL;
    //insert node
    insertNode(tail,0,10);
    // printNode(tail);

    insertNode(tail,10,20);
    insertNode(tail,20,40);
    // insertNode(tail,4,40);
    // insertNode(tail,9,50);
    printNode(tail);

    // deleteNode(tail,20);
    printNode(tail);
    return 0;
}