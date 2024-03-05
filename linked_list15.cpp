#include <iostream>
using namespace std;

//node template
class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }

    //destructor
    ~Node()
    {
        int value = this->data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout <<"Memory is freedup for node :    "<<value<<endl;
    }
};

//nodes head

class InsertElement{
    public:
    void insert(int val,Node* &head)
    {
        Node* obj = new Node(val);
        if(head == NULL)
        {
            head = obj;
            obj -> next = NULL;
        }
        else{
            obj->next = head;
            head = obj;
        }
    }
};

//print Linked List
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout <<temp->data <<"-";
        temp = temp->next;
    }
    cout <<endl;
}

Node* reverse(Node* head)
{
    Node* previous = NULL;
    Node* current = head;
    Node* next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

//insert at ans tail
void insertAtTail(Node* &head,Node* &tail,int val)
{
    Node* obj = new Node(val);
    if(head == NULL)
    {
        head = obj;
        tail = obj;
        return;
    }
    else
    {
        tail->next = obj;
        tail = obj;
    }
    
}

Node* add(Node* first,Node* second)
{
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    //add 
    while(first != NULL || second != NULL)
    {
        int val1 = 0;
        if(first != NULL)
        {
            val1 = first->data;
        }
        int val2 = 0;
        if(second != NULL)
        {
            val2 = second->data;
        }

        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        insertAtTail(ansHead,ansTail, digit);
        carry = sum / 10;
        if(first != NULL)
        {
            first = first->next;
        }
        if(second != NULL)
        {
            second = second->next;
        }
    }
    cout <<"carry Value"<<carry<<endl;
    cout<<"Inside Add function"<<endl;
    print(ansHead);
    return ansHead;
}

int main()
{   
    Node* head = NULL;
    InsertElement first;
    Node* firstHead = head;
    InsertElement second;
    Node* secondHead = head;
    first.insert(3,firstHead);
    first.insert(8,firstHead);
    first.insert(6,firstHead);
    second.insert(4,secondHead);
    second.insert(9,secondHead);
    second.insert(3,secondHead);
    second.insert(8,secondHead);
    print(firstHead);
    print(secondHead);

    //first step reverse original lists
    firstHead = reverse(firstHead);
    secondHead = reverse(secondHead);
    Node* ans = add(firstHead,secondHead);
    ans = reverse(ans);
    print(ans);
    
    return 0;
}