#include <iostream>
using namespace std;

//Doubly linked list template
class Node{
    public:
    int data;
    Node* next;
    Node* previous;

    //constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->previous = NULL;
    }

};

//traverse nodes
void print(Node* head)
{
    while (head != NULL)
    {
        cout<<head->data<<"-";
        head = head->next;
    }
    cout<<endl;
}

//get len of linked list
int getLen(Node* head)
{
    int count = 0;
    while(head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}

//insert at head
void insertAtStart(Node* &head,int d)
{
    Node* obj = new Node(d);
    obj->next = head;
    head->previous = obj;
    head = obj;
}

//insert at tail
void insertAtTail(Node* &tail,int d)
{
    Node* obj = new Node(d);
    tail->next = obj;
    obj->previous = tail;
    tail = obj;
}

//insert at position
void insertAtpos(Node* &head,Node* &tail,int pos,int d)
{
    //if head is empty
    if (head == NULL)
    {
        Node* obj = new Node(d);
        head = obj;
    }
    //if position is 1
    if (pos == 1)
    {
        insertAtStart(head,d);
        return;
    }
    int count = 1;
    Node* temp = head;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    //if position is end of linked list
    if(temp->next == NULL)
    {
        insertAtTail(tail,d);
        return;
    }
    else{
        Node* obj = new Node(d);
        obj->next = temp->next;
        obj->previous = temp;
        temp->next = obj;
        temp->next->previous = obj;
        
    }
}


int main()
{
    Node* obj1 = new Node(70);
    Node* head = obj1;
    Node* tail = obj1;
    print(head);
    cout <<"Length of linked list is : "<<getLen(head)<<endl;

    insertAtStart(head,60);
    print(head);
    cout << head->data<<endl;
    cout <<head->previous<<endl;

    insertAtTail(tail,80);
    print(head);
    cout << tail->data<<endl;

    insertAtpos(head,tail,2,3333);
    print(head);

    insertAtpos(head,tail,1,9999);
    print(head);
    cout<< getLen(head)<<endl;

    insertAtpos(head,tail,5,8888);
    print(head);

    insertAtpos(head,tail,7,8888);
    print(head);
    return 0;
}