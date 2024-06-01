#include<iostream>
#include<vector>
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

//insertInto BST
Node* insertIntoBST(Node* root,int data)
{
    //base condition
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }
    //for left subtree
    if(root->data > data)
    {
        root->left = insertIntoBST(root->left,data);
    }
    else
    {
        root->right = insertIntoBST(root->right,data);
    }
    
}

//takeinput
void takeInput(Node* &root)
{
    int data;
    cin>>data;
    while (data != -1)
    {
        root = insertIntoBST(root,data);
        cin >> data;
    }
}

//level order tracer
void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<"     ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

//in-order traversal
void inOrderTraversal(Node* root,vector<int> &in)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left)
    {
        inOrderTraversal(root->left,in);
    }
    in.push_back(root->data);
    if (root->right)
    {
        inOrderTraversal(root->right,in);
    }
}


//make a Balanced Binary search Tree
Node* balancedBSTCreation(vector<int> sortedVec,int start,int end)
{
    //base case
    if(start > end)
    {
        return NULL;
    }
    int mid = (start + end)/2;
    Node* root = new Node(sortedVec[mid]);
    root->left = balancedBSTCreation(sortedVec,start,mid-1);
    root->right = balancedBSTCreation(sortedVec,mid+1,end);
    return root;
}

int main()
{
    Node* root = NULL;
    cout<<"Enter data for BST Nodes:    "<<endl;
    takeInput(root);
    cout<<"Tree created Not Balanced     "<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<endl;
    cout<<"Now un-balanced to balanced BST conversion process started"<<endl;
    vector<int> inOrderValues;
    //function call for populating inOrderValues vector
    inOrderTraversal(root,inOrderValues);
    int start = 0;
    int end = inOrderValues.size()-1;
    Node* balancedBST = balancedBSTCreation(inOrderValues,start,end);
    cout<<endl;
    cout<<"Conversion Done!!!!!"<<endl;
    cout<<endl;
    cout<<"Balanced BST     "<<endl;
    levelOrderTraversal(balancedBST);
    return 0;
}