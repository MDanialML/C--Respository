#include <iostream>
using namespace std;

//node template
class Node{
    public:
    int data;
    Node* next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout <<"Memory is freedup for value:    "<<value<<endl;
    }
};
//head pointer
Node* head = NULL;
class InsertElement{
    public:
    void insert(int data)
    {
        Node* obj = new Node(data);
        if(head == NULL)
        {
            head = obj;
        }
        else
        {
            obj->next = head;
            head = obj;
        }
    }
};
//print 
void print(Node* head)
{
    while(head != NULL)
    {
        cout <<head->data<<"-";
        head = head->next;
    }
    cout<<endl;
}

void insertAtTail(Node* &head,Node* data)
{
    head->next = data;
    head = data;
}

//sort linked list
void sortLinkList(Node* &head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* current = head;
    //create separate list for 0 1 and 2
    while(current != NULL)
    {
        int value = current->data;
        if(value == 0)
        {
            insertAtTail(zeroTail,current);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail,current);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail,current);
        }
        current = current->next;
    }

    //merge lists
    //one list is empty
    if(oneHead->next != NULL)
    {
        zeroTail->next = oneHead ->next;
    }
    else
    {
        zeroTail ->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;

    zeroHead->next =NULL;
    oneHead->next =NULL;
    twoHead->next = NULL;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
}

int main()
{
    InsertElement obj;
    obj.insert(2);
    obj.insert(1);
    obj.insert(0);
    obj.insert(2);
    obj.insert(0);
    obj.insert(1);
    obj.insert(1);
    obj.insert(0);
    obj.insert(1);
    obj.insert(2);
    print(head);
    
    //sort zero and ones
    sortLinkList(head);
    print(head);
    return 0;
}