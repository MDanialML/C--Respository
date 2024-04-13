#include <iostream>
#include <queue>
using namespace std;

//node class
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildFromLevelOrder(Node* root)
{
    queue<Node*> q;
    cout<<"Enter data for root Node:    ";
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout<<"Enter left node data for "<<temp->data<<endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node data for "<<temp->data<<endl;
        int rightData;
        cin >> rightData;
        if(rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
    return root;
}

void inOrderTracer(Node* root)
{
    //base condition
    if(root == NULL)
    {
        return;
    }
    inOrderTracer(root->left);
    cout<<root->data<<" ";
    inOrderTracer(root->right);
}

//count leaf nodes
void countLeafNodes(Node* root, int &count)
{
    //base condition
    if(root == NULL)
    {
        return;
    }
    countLeafNodes(root->left, count);
    if(root->left == NULL && root->right == NULL)
    {
        count++;
    }
    countLeafNodes(root->right,count);
}

int main()
{
    Node* root = NULL;
    int count = 0;
    root = buildFromLevelOrder(root);
    cout<<"----------------------   Printing data In-order Tracer ----------------------------"<<endl;
    inOrderTracer(root);
    cout<<endl;
    cout<<endl;
    countLeafNodes(root,count);
    cout<<"Total Leaf Nodes:    "<<count<<endl;
    return 0;
}