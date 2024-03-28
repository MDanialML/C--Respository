#include <iostream>
using namespace std;

//Doubly ended Queue implementation
class DoublyQueue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    //constructor for intialization
    DoublyQueue(int s)
    {
        this->size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    //push front
    void pushFront(int d)
    {
        //if queue is full
        if((front == 0 && rear == size-1) || (rear == (front - 1)%(size -1)))
        {
            cout <<"Queue is full!"<<endl;
            return;
        }
        else if (front == -1)//for first element
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0) //maintain circular nature
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = d;
    }
    //pop front
    void popFront()
    {
        //if queue is empty
        if(front == -1)
        {
            cout<<"Queue is Empty!"<<endl;
            return;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front = size -1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    //push back
    void pushBack(int d)
    {
        //if queue is full
        if((front == 0 && rear == size - 1) || (rear == (front - 1)%(size - 1)))
        {
            cout <<"Queue is full.!"<<endl;
            return;
        }
        //for first insertion
        else if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == size - 1 && front != 0)//maintain cyclic nature
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = d;
    }
    //pop back
    void popBack()
    {
        //if queue is empty
        if(front == -1)
        {
            cout <<"Queue is empty!"<<endl;
            return;
        }
        else if (front == rear)//for single element
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = size -1; //maintain cyclic nature
        }
        else
        {
            rear--;
        }
    }

    //empty
    bool isEmpty()
    {
        if(front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //full
    void isFull()
    {
        if((front == 0 && rear == size - 1) || (!front == 0 && rear == (front -1 )%(size -1)))
        {
            cout <<"Queue is Full"<<endl;
        }
        else
        {
            cout <<"Not full yet"<<endl;
        }
        
    }
    //front
    void qFront()
    {
        if(isEmpty())
        {
            cout <<-1<<endl;
        }
        else
        {
            cout <<"Front:  "<<arr[front]<<endl;
        }
        
    }
    //back
    void qRear()
    {
        if(isEmpty())
        {
            cout <<-1<<endl;
        }
        else
        {
            cout <<"Rear:   "<<arr[rear]<<endl;
        }
    }
};


int main()
{
    DoublyQueue dq(5);
    dq.pushFront(10);
    dq.pushFront(5);
    dq.pushBack(50);
    dq.pushBack(100);
    dq.pushBack(110);
    dq.qFront();
    dq.qRear();
    dq.isFull();
    return 0;
}