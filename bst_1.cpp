#include <iostream>
#include<queue>
using namespace std;

//Node
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

//insert into Binary Search Tree
Node* insertIntoBST(Node* root,int data)
{
    //for root Node
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if(data < root->data){
        root->left = insertIntoBST(root->left,data);
    }
    else
    {
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;
    while(data != -1)
    {
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

//level order tracer
void levelOrderTracer(Node* root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* temp =  q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<"    "<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}


int main()
{
    Node* root = NULL;
    cout<<"Enter data for BST"<<endl;
    takeInput(root);
    cout<<"Level Wise Node Printing"<<endl;
    levelOrderTracer(root);
    return 0;
}