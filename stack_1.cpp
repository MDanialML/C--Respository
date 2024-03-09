#include <iostream>
#include <stack>
using namespace std;
//stack implementation
class Stack{
    public:
    //propertise
    int *arr;
    int size;
    int top;
    //initialize
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    //push method
    void push(int element)
    {
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else
        {
            cout<<"Stack overflow "<<endl;
        }
    }

    //pop method
    void pop(){
        if (top >= 0){
            top--;
        }
        else{
            cout <<"Stack is empty"<<top<<endl;
        }
    }

    //peek method
    int peek(){
        if(top >= 0)
        {
            cout<<"peek element is : "<<arr[top];
        }else
        {
            cout<<"stack is empty:  "<<endl;
        }
    }
    //is empty
    bool isEmpty()
    {
        if(top >= 0){
            return true;
        }
        else
        {
            return false;
        }
        
    }
};

int main()
{
    /*
    stack<int> d;
    d.push(3);
    d.push(4);
    d.pop();
    cout<<d.top()<<endl;
    if(d.empty())
    {
        cout <<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
    */
   //stack implementation using array

   Stack st(4);
   if(st.isEmpty()){
    cout<<"stack is not empty"<<endl;
   }
   else
   {
    cout <<"stack is empty"<<endl;
   }
   cout<<"Peek:"<<st.peek()<<endl;
   st.pop();
   st.push(67);
   st.push(45);
   st.push(60);
   st.push(34);
   st.push(100);
   st.peek();

    return 0;
}