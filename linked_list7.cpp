#include <iostream>
using namespace std;

//Node template
class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

//print nodes of link list
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<< temp->data<<"->";
        temp= temp->next;
    }cout<<endl;
}

//insert node
void insertAtHead(Node* &head,int value)
{
    if(head == NULL)
    {
        Node* obj = new Node(value);
        head = obj;
    }
    else
    {
        Node* obj = new Node(value);
        obj->next = head;
        head = obj;
    }
    
}
// Node* head = NULL;
// class InsertData{
//     public:
//     void insert(int value)
//     {
//         Node* newNode = new Node(value);
//         if(head == NULL)
//         {
//             head = newNode;
//         }
//         else{
//             newNode->next = head;
//             head = newNode;
//         }

//     }
// };


//reverse the node
// Node* reverseLinklist(Node* &head)
// {
//     //base case
//     if (head == NULL || head -> next == NULL)
//     {
//         return;
//     }
//     reverseLinklist(head -> next);
//     head -> next -> next = head;
//     head -> next = NULL;
//     cout<<"Reached botton of reverse function"<<endl;
// }

void reversLinkList(Node* &head, Node* previous,Node* current)
{
    //base case
    if (current == NULL)
    {
        head = previous;
        return;
    }
    Node* forward = current->next;
    reversLinkList(head,current,forward);
    current->next = previous;
    // previous = current;
    // return previous;
}

int main()
{
    Node* head = NULL;
    insertAtHead(head,100);
    insertAtHead(head,90);
    insertAtHead(head,80);
    insertAtHead(head,70);
    insertAtHead(head,60);
    insertAtHead(head,50);
    insertAtHead(head,40);
    //print node data
    print(head);

    // reverseLinklist(head);
    Node* previous = NULL;
    Node* current = head;
    cout<<head->data<<endl;
    reversLinkList(head,previous,current);
    print(head);
    return 0;
}