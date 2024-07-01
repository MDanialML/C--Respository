//merge K sorted linkend list to single linkendlist
#include <bits/stdtr1c++.h>
using namespace std;

/*
//linked list node
class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

//insert at head of linked list
void insertIntoLL(Node* &head,vector<int>arr)
{
    if(head == NULL)
    {
        Node* temp = new Node(arr[0]);
        head = temp;
    }
    for (int i =1; i<arr.size();i++)
    {
        Node* prev = head;
        Node* newNode = new Node(arr[i]);
        head = newNode;
        newNode->next = prev;
    }
}

void printLLData(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<endl;
}

void create2DVec(Node* head,vector<int> &vec);
*/

//custom compare for minheap
class compare{
    public:
    bool operator()(list<int>* a, list <int>* b){
        // return a->data > b->data;
    }
};

int main()
{
    //LL2
    // Node* head1 = NULL;
    // vector<int> vecOne ={6,5,4,3,2,1};
    // insertIntoLL(head1,vecOne);
    // printLLData(head1);
    list <int> list1 = {6,5,4,3,2,1};

    //LL1
    // Node* head2 = NULL;
    // vector<int> vectwo ={12,10,9,7};
    // insertIntoLL(head2,vectwo);
    // printLLData(head2);
    list <int> list2 = {12,10,9,7};

    //LL3
    // Node* head3 = NULL;
    // vector<int> vecThree ={17,15,13};
    // insertIntoLL(head3,vecThree);
    // printLLData(list3);
    list<int> list3 = {17,15,13};
    for (list<int>::iterator it = list3.begin(); it != list3.end(); it++)
    {
        cout << *it<<"-";
    }cout<<endl;
    
    vector<list<int>> vecLists;
    vecLists.push_back(list1);
    vecLists.push_back(list2);
    vecLists.push_back(list3);
    for (int i = 0; i < vecLists.size(); i++)
    {
        for (list<int>:: iterator it = vecLists[i].begin(); it != vecLists[i].end();it++)
        {
            cout<< *it<<"->";
        }cout<<endl;
    }


    // vector<Node*<int>> vecList = {head1,head2,head3};

    //creating 2-d vector of linked lists
    // vector<vector <list>> d2_vec = {{head1},{head2},{head3}};
    // vector<int> dataHolder;
    // create2DVec(head1,dataHolder);
    // create2DVec(head2,dataHolder);
    // create2DVec(head3,dataHolder);
    // for(int i = 0; i < dataHolder.size(); i++)
    // {
    //     cout<<dataHolder[i]<<"-";
    // }cout<<endl;
    // Node* finalList = NULL;
    // insertIntoLL(finalList,dataHolder);
    // cout<<"Merged linked List:  "<<endl;
    // printLLData(finalList);
    return 0;
}

// void create2DVec(Node* head, vector<int> &vec)
// {
//     Node* temp = head;
//     while(temp != NULL)
//     {
//         vec.push_back(temp->data);
//         temp = temp->next;
//     }
// }