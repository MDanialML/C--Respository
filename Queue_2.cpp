#include<iostream>
using namespace std;

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    CircularQueue(int s)
    {
        this->size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void enqueue(int data)
    {
        if((front == 0 && rear == size - 1) || (rear == (front -1 )%(size-1)))
        {
            cout <<"Queue is full.! "<<endl;
            return;
        }
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else if (rear == size -1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    void dequeue()
    {
        if(front == -1)
        {
            cout <<"Queue is empty!"<<endl;
            return;
        }
        else if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size-1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
};

int main()
{
    CircularQueue cd(3);
    cd.enqueue(10);
    cd.enqueue(30);
    cd.enqueue(40);
    // cd.enqueue(59);
    cd.dequeue();
    cd.dequeue();
    cd.dequeue();
    cd.dequeue();

    return 0;
}