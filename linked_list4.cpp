#include <iostream>
using namespace std;

//link list creation
class Node{
    public:
    int data;
    Node* next;
    Node* previous;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->previous = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "The deleted value is :"<<value<<endl;
    }
};

//insert node in link list
void insertElement(Node* &head,Node* &tail,int position,int data)
{   
    //when heading poiting to null value means link list is empty
    if (head == NULL)
    {
        Node* obj = new Node(data);
        head = obj;
        tail = obj;
        return;
    }
    //inserting element at head
    if(position == 1)
    {
        Node* obj = new Node(data);
        obj->next = head;
        head->previous = obj;
        head = obj;
        return;
    }
    else
    {
        Node* temp = head;
        int count = 1;
        while(count < position-1)
        {
            temp = temp->next;
            count ++;
        }
        //at the end of link list
        if(temp->next == NULL)
        {
            // cout<<"control is in last if::::"<<endl;
            Node* obj = new Node(data);
            temp->next = obj;
            obj->previous = temp;
            tail = obj;
            return;
        }
        else
        {
            Node* obj = new Node(data);
            temp->next->previous = obj;
            obj->next = temp->next;
            obj->previous = temp;
            temp->next = obj;
        }
        
    }
}

//delete specified index
void deleteNode(Node* &head,int position)
{
    if(position == 1)
    {
        Node* temp = head;
        temp->next->previous = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* current = head;
        Node* previous = NULL;
        int count = 1;
        while (count < position)
        {
            previous = current;
            current = current->next;
            count ++;
        }
        previous->next = current->next;
        current->previous = NULL;
        current->next->previous = previous;
        current->next = NULL;
        delete current;

    }
    
}

//print link list nodes
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<",";
        temp = temp->next;
    }cout <<endl;
}

//get length of link list
int getLength(Node* head)
{
    Node* temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
    
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertElement(head,tail,0,100);
    print(head);

    //insert element at position one means head
    insertElement(head,tail,1,80);
    print(head);
    cout << head->data<<endl;
    cout <<tail->data<<endl;
    cout <<"Length of link list : "<<getLength(head)<<endl;

    //insert element at tail of link list
    insertElement(head,tail,3,120);
    print(head);
    cout << head->data<<endl;
    cout <<tail->data<<endl;
    cout <<"Length of link list : "<<getLength(head)<<endl;

     //insert element at any position in link list
    insertElement(head,tail,2,90);
    print(head);
    cout << head->data<<endl;
    cout <<tail->data<<endl;
    cout <<"Length of link list : "<<getLength(head)<<endl;

    deleteNode(head,2);
    return 0;
}