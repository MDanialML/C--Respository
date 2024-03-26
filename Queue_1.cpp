#include <iostream>
using namespace std;

//custom queue implementation using array
class Queue{
    int *arr;
    int Qfront;
    int rear;
    int size;
    public:
    Queue(int size)
    {
        arr = new int[size];
        Qfront = 0;
        rear = 0;
        this->size = size;
    }
    //check for  empty or not
    bool isEmpty()
    {
        if(Qfront == rear)
        {
            return true;
        }
        else{
            return true;
        }
    }

    void enqueue(int data)
    {
        //if full
        if(rear == size)
        {
            cout<<"Queue OverFlow"<<endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        //if empty
        if(Qfront == rear)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else
        {
            int value = arr[Qfront];
            Qfront = -1;
            Qfront++;
            if(Qfront == rear)
            {
                Qfront = 0;
                rear = 0;
            }
            return value;
        }
    }
    int front()
    {
        if(Qfront == rear)
        {
            return -1;
        }
        else
        {
            return arr[Qfront];
        }
        
    }
};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    // q.enqueue(6);
    if(q.isEmpty())
    {
        cout<<"Queue is empty.!"<<endl;
    }else
    {
        cout<<"Queue is not empty!"<<endl;
    }
    int front = q.front();
    cout <<"Front element of queue is:   "<<front<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}