#include <iostream>
using namespace std;

//K queues implementation
class KQueues{
    public:
    //decalration of an array in which K-Queues will be implemented
    //requirment for implementation of K-Queues in single array 
    int *arr;
    int *front; //declared an array for keeping front element index of each K-Queue
    int *rear; //declared an array for keeping rear element index of each K-Queue
    int *next; //declared next array size of original array for keeping the next free slot of original array
    int freeSpot; //declared a variable to keep the index of freespot in original array

    //Constructor
    KQueues(int n, int k)
    {
        arr = new int[n]; //base array 
        front = new int[k]; //front array 
        rear = new int[k]; //rear array
        next = new int[n]; //next array
        freeSpot = 0; //intial freeSpot in base array is at index 0

        //front array intialized to -1
        for (int i = 0; i < k;i++)
        {
            front[i] = -1;
        }

        //rear array intialized to -1
        for (int i = 0; i < k;i++)
        {
            rear[i] = -1;
        }
        //next array intialized to next free index of base array
        for(int i =0; i < n;i++)
        {
            next[i] = i+1;
        }
        next[n-1] = -1; //no next free space available at the end base array
    }

    //push/Enqueue 
    void enQueue(int data, int q_num)
    {
        //check for overflow 
        if(freeSpot == -1)
        {
            cout <<"Base array is full, Overflow Condition"<<endl;
            return;
        }

        //find index of free spot where data to be inserted
        int index = freeSpot;
        //update freeSpot with next free spot index of base array
        freeSpot = next[index];

        //check whether we are inserting first element in specified Queue number
        //this should be dealt speratly because we intialized each front to -1
        if(front[q_num -1] == -1)
        {
            front[q_num-1] = index;
        }
        else
        {
            next[rear[q_num-1]] = index;//link to previous element of specified queue
        }
        next[index] = -1; //specified index in base array is not free
        rear[q_num-1] = index; //update rear with current insertion index
        arr[index] = data; //insert data at index in base array
    }

    //Dequeue
    int Dequeue(int q_num)
    {
        //Check for underflow condition
        if(front[q_num -1] == -1)
        {
            cout<<"Queue is empty, No element present"<<endl;
            return -1;
        }
        //find index of front that should b deleted
        int index = front[q_num - 1];

        //relocate the front to next element of that queue
        front[q_num-1] = next[index];

        //manage free slots in base array
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index]; //returing poped element
    }
};

int main()
{
    KQueues kque(6,3);
    cout<<endl;
    cout<<"Enque elements to K number of queues"<<endl;
    cout<<endl;
    kque.enQueue(2,1);
    kque.enQueue(6,2);
    kque.enQueue(8,2);
    kque.enQueue(12,3);
    kque.enQueue(7,1);
    kque.enQueue(43,1);
    kque.enQueue(99,1);
    cout << endl;
    cout<<"Dequeue elements from 2nd Queue"<<endl;
    cout<<endl;
    cout <<kque.Dequeue(2)<<endl;
    cout <<kque.Dequeue(2)<<endl;
    cout <<kque.Dequeue(2)<<endl;

    return 0;
}