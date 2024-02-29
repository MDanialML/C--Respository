#include <iostream>
using namespace std;

//Node template
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
        cout <<"Memory freed for node "<< value;
    }
};

//insert element
void insertElement(Node* &tail,int value,int d)
{
    if(tail == NULL)
    {
        Node* obj = new Node(d);
        tail = obj;
        obj->next = obj;
    }
    else
    {
        Node* current = tail;
        while(current->data != value)
        {
            current = current->next;
        }
        //create new node
        Node* newNode = new Node(d);
        newNode->next = current->next;
        current->next = newNode;
    }
    
}
//print linked list
void print(Node* tail)
{
    Node* temp = tail;
    cout<<endl;
    do{
        cout <<tail->data<<"->";
        tail = tail->next;
    } while (tail != temp);
    cout <<endl;
}
//delete any node
void deleteNode(Node* &tail,int value)
{
    if(tail == NULL)
    {
        cout<<"Link list is empty, please check again"<<endl;
        return;
    }
    {
        Node* previous = tail;
        Node* current = previous -> next;
        while (current->data != value)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        if(tail == current)
        {
            tail = previous;
        }
        current->next = NULL;
        delete current;
    }
}

//check if link list is circular or not
bool isCircularLink(Node* tail)
{
    if(tail == NULL)
    {
        return false;
    }
    Node* temp = tail->next;
    while(temp != NULL && temp != tail)
    {
        temp = temp->next;
    }
    if(temp == tail)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main()
{
    Node* tail = NULL;
    insertElement(tail,5,80);
    insertElement(tail,80,90);
    insertElement(tail,90,100);
    insertElement(tail,100,110);
    insertElement(tail,110,120);
    // insertElement(tail,0,70);
    print(tail);
    deleteNode(tail,90);
    print(tail);
    if(isCircularLink(tail))
    {
        cout <<"Link List is circular"<<endl;
    }
    else
    {
        cout <<"Link list is not circular"<<endl;
    }
    
    return 0;
}