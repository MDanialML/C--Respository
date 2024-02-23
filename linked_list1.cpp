#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this-> data = data;
        this-> next = NULL;
    }
};

//insert at head
void insertAtHead(Node* &Head, int data)
{
    Node* obj2 = new Node(data);
    obj2->next = Head;
    Head = obj2;
}

//inset at the specified index
void insertAtMiddle(Node* &Head,int pos,int data)
{
    int count = 1;
    Node* temp = Head;
    while(count < pos-1)
    {
        count++;
        temp = temp->next;
    }
    Node* nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

//insert element at tail of linked list
void insertAtTail(Node* &Tail,int data)
{
    Node* obj3 = new Node(data);
    Tail -> next = obj3;
    Tail = obj3 -> next;
}

//print element of linked list
void print(Node* &Head)
{
    Node* temp = Head;

    while (temp != NULL)
    {
        cout << temp->data<<",";
        temp = temp->next;
    }
    cout<<endl;
    
}

int main()
{
    Node* obj1 = new Node(10);
    Node* Head = obj1;
    Node* Tail = obj1;
    print(Head);

    //inserting it at start of existing linked list
    insertAtHead(Head,5);
    print(Head);
    
    //insert element at tail of linked list
    insertAtTail(Tail,20);
    print(Head);

    //insert at the middle of linked list
    insertAtMiddle(Head,3,15);
    print(Head);

    return 0;
}