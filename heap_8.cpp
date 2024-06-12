//merge k sorted arrays
#include<bits/stdc++.h>
using namespace std;

//node
class Node{
    public:
    int data;
    int row;
    int col;
    //constructor
    Node(int d,int row,int col)
    {
        this->data = d;
        this->row = row;
        this->col = col;
    }
};

//custome compare fucntion for min heap
class Compare{
    public:
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &arr,int k)
{
    //step# 1 create a min heap
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    //step 2 extract first element of each array and push it to min-heap
    for(int i = 0; i < k;i++)
    {
        Node* temp = new Node(arr[i][0],i,0);
        minHeap.push(temp);
    }
    vector<int> ans;
    //step 2 now push the next value into minHeap
    while (minHeap.size() > 0)
    {
        Node* temp = minHeap.top();
        minHeap.pop();
        ans.push_back(temp->data);

        int i = temp->row; //get currently pushed to ans array element row number
        int j = temp->col; //get currently pushed to ans array element col number
        if(j+1 < arr[i].size())
        {
            Node* next = new Node(arr[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    return ans;
    }

int main()
{
    //pre requisit
    vector<vector<int>> arr = {{1,2,3,4},{6,7,8},{9,10,11,12,13},{14,15},{16}};
    int row = arr.size();
    cout<<"Total rows: "<<row<<endl;
    for(int i = 0; i<row;i++)
    {
        for(int j = 0; j < arr[i].size();j++)
        {
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    vector <int> ans = mergeKSortedArrays(arr,arr.size());
    for (int i: ans)
    {
        cout<<i<<"  ";
    }cout<<endl;
    return 0;
}