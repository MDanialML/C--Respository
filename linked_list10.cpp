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
        cout <<"Memory is freedup for value :"<<value<<endl;
    }
};
//insert element
void insertElement(Node* &head,Node* &tail,int d)
{
    if(head == NULL)
    {
        Node* obj  = new Node(d);
        head = obj;
        tail = obj;
    }
    else
    {
        Node* obj = new Node(d);
        obj->next = head;
        head = obj;
    }
    
}

//print element
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout <<temp->data<<"->";
        temp = temp->next;
    }cout<<endl;
}

Node* floyedCycle(Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if(fast == slow)
        {
            cout<<"Loop found on "<<fast->data<<endl;
            return fast;
        }
    }
    return NULL;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertElement(head,tail,80);
    insertElement(head,tail,70);
    insertElement(head,tail,60);
    insertElement(head,tail,50);
    insertElement(head,tail,40);
    insertElement(head,tail,30);
    
    // print(head);
    tail->next = head->next->next;
    cout <<"Tail next data is equal to "<<tail->next->data<<endl;
    if(floyedCycle(head) == NULL)
    {
        cout<<"Loop not exist"<<endl;
    }
    else
    {
        cout <<"Loop exist.!"<<endl;
    }
    
    return 0;
}