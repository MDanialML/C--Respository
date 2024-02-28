#include <iostream>
using namespace std;

//Node template
class Node{
    public:
    int value;
    Node* next;

    //constructor
    Node(int d)
    {
        this->value = d;
        this->next = NULL;
    }
};

//initializing empty 
Node* head = NULL;
class InsertNode{
    public:
    void insert(int value)
    {
        Node* newNode = new Node(value);
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
};

//print linklist nodes
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout <<temp->value<<"->";
        temp = temp->next;
    }cout <<endl;
} 

//get middle node
Node* getMiddle(Node* head){
    //base case
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    if(head -> next -> next == NULL)
    {
        return head -> next;
    }
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL)
    {
        fast = fast -> next;
        if(fast -> next != NULL)
        {
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;
}

int main()
{
    InsertNode l1;
    l1.insert(70);
    l1.insert(60);
    l1.insert(50);
    l1.insert(40);
    l1.insert(30);
    l1.insert(20);
    l1.insert(10);
    print(head);
    Node* middle = getMiddle(head);
    cout <<"Middle node of link list is : "<<middle->value<<endl;
    return 0;
}