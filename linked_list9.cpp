#include <iostream>
#include <map>
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

//detect loop in link list
bool detectLoop(Node* tail)
{
    if (tail == NULL)
    {
        return false;
    }
    map<Node*,bool>visited;
    Node* temp = tail;

    while (temp != NULL)
    {
        if(visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}


int main()
{
    Node* tail = NULL;
    insertElement(tail,5,80);
    insertElement(tail,80,90);
    insertElement(tail,90,100);
    insertElement(tail,100,110);
    insertElement(tail,110,120);
    print(tail);
    if (detectLoop(tail))
    {
        cout <<"Loop exist "<<endl;
    }
    else
    {
        cout <<"No loop exist"<<endl;
    }
    return 0;
}