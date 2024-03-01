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
        cout<<"memory freedup for value :"<<value<<endl;
    }
};

//insert value into link list
void insertValue(Node* &head,Node* &tail,int d)
{
    if(head == NULL)
    {
        Node* obj = new Node(d);
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

//print
void print(Node* head)
{
    cout <<endl;
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

//cycle detection
Node* detectCycle(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

//get starting point of loop
Node* getStartingPoint(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node* intersectionPoint = detectCycle(head);
    cout<<"point of intersection is "<<intersectionPoint<<endl;
    Node* slow = head;
    while(slow != intersectionPoint)
    {
        slow = slow->next;
        intersectionPoint = intersectionPoint->next;
    }
    return slow;
}

void removeLoop(Node* head)
{
    if(head == NULL)
    {
        return;
    }
    Node* startNode = getStartingPoint(head);
    Node* temp = startNode;
    while (temp->next != startNode)
    {
        temp = temp->next;
    }
    cout<<"LOOP REMOVED, LAST NODE IS "<<temp->data<<endl;
    temp->next = NULL;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertValue(head,tail,80);
    insertValue(head,tail,70);
    insertValue(head,tail,60);
    insertValue(head,tail,50);
    insertValue(head,tail,40);
    insertValue(head,tail,30);
    print(head);
    tail->next = head->next->next;
    if(detectCycle(head) != NULL)
    {
        cout<<"LOOP EXIST"<<endl;
        cout<<"The point of first meet  :"<<detectCycle(head)->data<<endl;
    }
    else
    {
        cout <<"NO LOOP EXIST"<<endl;
    }
    cout<<"starting point of LOOP   :   "<<getStartingPoint(head)->data<<endl;
    removeLoop(head);
    print(head);

    return 0;
}