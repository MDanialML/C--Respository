//stack implementation using link list
#include <iostream>
using namespace std;
//node template
class Node{
    public:
    int data;
    Node* link;

    //constructor
    Node(int val)
    {
        this->data = val;
        this->link = NULL;
    }
    //destructor
    ~Node()
    {
        int element = this->data;
        if(link != NULL)
        {
            delete link;
            link = NULL;
        }
        cout <<"Deleted this node : "<<element<<endl;
    }
};
class Stack{
    public:
    Node* top = NULL;
    void push(int val)
    {   
        Node* obj = new Node(val);
        if(top == NULL)
        {
        top = obj;
        }else
        {
            obj->link = top;
            top = obj;
        }
    }
    //pop
    void pop(){
        if(top == NULL)
        {
            cout<<"Stack under flow"<<endl;
        }
        else{
            Node* temp = top;
            top = top -> link;
            temp -> link = NULL;
            delete temp;
        }
    }
    
    //check peek
    int peek()
    {
        if(top == NULL)
        {
            cout<<"list is empty"<<endl;
            return -1;
        }
        else{
            return top->data;
        }
    }
    //check stack is empty or not
    int isEmpty()
    {
        if(top == NULL)
        {
            return false;
        }
        else{
            return true;
        }
    }
};

int main()
{
    Stack s;
    s.push(20);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    return 0;
}