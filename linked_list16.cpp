#include <iostream>
using namespace std;

//Node template
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
    ~Node()
    {
        int value = this->data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Node is deleted: "<<endl;
    }
};


//insert element
class InsertElement{
    public:
    void insert(int val,Node* &head)
    {
        Node* obj = new Node(val);
        if(head == NULL)
        {
            head = obj;
            return;
        }
        else{
            obj->next = head;
            head = obj;
        }
    }
};

//print
void print (Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout <<temp->data<<"-";
        temp = temp->next;
    }cout<<endl;
}

//merge linl lists
void merge(Node* &first,Node* second)
{
    if(first == NULL)
    {
        first = second;
        return;
    }
    Node* current1 = first;
    Node* next1 = current1->next;
    Node* current2 = second;
    Node* next2 = current2->next;
    while(current1 != NULL && current2 != NULL)
    {
        if(current2->data >= current1->data && current2->data <= next1->data)
        {
            current1->next = current2;
            next2 = current2 ->next;
            current2->next = next1;
            //update pointers
            current1 = current2;
            current2 = next2;
        }
        else
        {
            current1 = current1->next;
            next1 = next1->next;
            if(next1 == NULL)
            {
                current1->next = current2;
            }
        }
    }
}


int main()
{
    Node* head = NULL;
    InsertElement first;
    Node* firstHead = head; 
    InsertElement second;
    Node* secondHead = head;
    first.insert(8,firstHead);
    first.insert(6,firstHead);
    first.insert(2,firstHead);
    second.insert(9,secondHead);
    second.insert(7,secondHead);
    second.insert(3,secondHead);
    second.insert(1,secondHead);
    cout<<"First link list"<<endl;
    print(firstHead);
    cout<<"Second link list"<<endl;
    print(secondHead);

    if(firstHead->data < secondHead->data)
    {
        merge(firstHead,secondHead);
        print(firstHead);
    }
    else
    {
        merge(secondHead,firstHead);
        print(firstHead);
    }
    return 0;
}