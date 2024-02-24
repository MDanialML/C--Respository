#include <iostream>
using namespace std;
//node template
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout <<"Memory is free for data : "<<value<<endl;
    }
};

//delete specified element
void deleteElement(Node* &head,int pos)
{
    //for first element
    if (pos == 1)
    {
        Node* temp = head;
        head = head->next;
        //now delete element
        temp->next = NULL;
        delete temp;

    }
    else
    {
        //delete any middle or last element
        Node* current = head;
        Node* previous = NULL;
        int count = 1;
        while(count < pos)
        {
            previous = current;
            current = current->next;
            count ++;
        }
        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
    
}

//insert element at head
void insertAtHead(Node* &head,int value)
{
    Node* obj = new Node(value);
    obj->next = head;
    head = obj;
}

//insert element at end
void insertAtend(Node* &tail,int value)
{
    Node* obj2 = new Node(value);
    tail->next = obj2;
    tail = tail->next;
}

//insert an element at specified position
void insertAtPos(Node* &head,Node* &tail,int pos,int value)
{
    if(pos == 1) //inserting value at start of linked list
    {
        insertAtHead(head,value);
        return;
    }
    int count = 1;
    Node* temp = head;
    //reaching at specified position
    while(count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    //inserting element at end
    if(temp->next == NULL)
    {
        insertAtend(tail,value);
    }
    Node* obj2 = new Node(value);
    obj2->next = temp->next;
    temp->next = obj2;
}


//function to traverse and print element of linked list
void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data<<",";
        temp = temp->next;
    }cout <<endl;
}


int main()
{
    Node* node1 = new Node(15);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    cout<<"Head is at   "<<head->data<<endl;
    cout<<"Tail is at   "<<tail->data<<endl;

    //insert element at head
    insertAtHead(head,10);
    print(head);
    cout<<"Head is at   "<<head->data<<endl;
    cout<<"Tail is at   "<<tail->data<<endl;

     //insert element at head
    insertAtHead(head,5);
    print(head);
    cout<<"Head is at   "<<head->data<<endl;
    cout<<"Tail is at   "<<tail->data<<endl;

    //insert at tail of linked list
    insertAtend(tail,20);
    print(head);
    cout<<"Head is at   "<<head->data<<endl;
    cout<<"Tail is at   "<<tail->data<<endl;

    //insert at tail of linked list
    insertAtend(tail,25);
    print(head);
    cout<<"Head is at   "<<head->data<<endl;
    cout<<"Tail is at   "<<tail->data<<endl;

    //insert at specified position
    insertAtPos(head,tail,4,80);
    print(head);
    cout<<"Head is at   "<<head->data<<endl;
    cout<<"Tail is at   "<<tail->data<<endl;

    //insert at specified position
    insertAtPos(head,tail,5,90);
    print(head);
    cout<<"Head is at   "<<head->data<<endl;
    cout<<"Tail is at   "<<tail->data<<endl;

    //insert at specified position
    insertAtPos(head,tail,1,2);
    print(head);
    cout<<"Head is at   "<<head->data<<endl;
    cout<<"Tail is at   "<<tail->data<<endl;


     //insert at end of linked list
    insertAtPos(head,tail,9,100);
    print(head);
    cout<<"Head is at   "<<head->data<<endl;
    cout<<"Tail is at   "<<tail->data<<endl;

    //delete specified element
    deleteElement(head,4);
    print(head);
    return 0;
}