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
}

//remove duplicates
Node* removeDuplicates(Node* head)
{
    if(head == NULL)
    {
        return head;
    }
    Node* current = head;
    while(current != NULL)
    {   
        
        if((current->next != NULL) && (current -> data == current->next -> data))
        {   
            Node* next_next = current->next->next;
            Node* nodeToDelete = current->next;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
            current->next = next_next;
        }
        else
        {
            current = current->next;
        }
    }
    return head;
}

int main()
{
    InsertElement obj;
    obj.insert(8);
    obj.insert(8);
    obj.insert(6);
    obj.insert(5);
    obj.insert(5);
    obj.insert(3);
    obj.insert(3);
    obj.insert(2);
    obj.insert(2);
    obj.insert(1);
    print(head);

    print(removeDuplicates(head));
    return 0;
}