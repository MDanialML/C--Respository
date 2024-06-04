#include<iostream>
using namespace std;

//class Node
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

//class for info
class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

//insert Into bst
Node* insertIntoBST(Node* root,int data)
{
    //base case
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if(root->data > data)
    {
        root->left = insertIntoBST(root->left,data);
    }
    else
    {
        root->right = insertIntoBST(root->right,data);
    }
}

//takeInput
void takeInput(Node* &root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

bool isValidBST(Node* root,int min,int max)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->data > min && root->data < max)
    {
        bool left = isValidBST(root->left,min,root->data);
        bool right = isValidBST(root->right,root->data,max);
        return left && right;
    }
    else
    {
        return false;
    }
}

//function to check largest BST in given binary tree
info largestBSTInBT(Node* root , int &ans)
{
    //base case
    if(root == NULL)
    {
        return {INT16_MIN,INT16_MAX,true,0};
    }
    info left = largestBSTInBT(root->left,ans);
    info right = largestBSTInBT(root->right,ans);
    info currentNode;
    currentNode.size = left.size + right.size + 1;
    currentNode.maxi = max(root->data,right.maxi);
    currentNode.mini = min(root->data, left.mini);
    if(left.isBST && right.isBST && (left.maxi < root->data && root->data < right.mini))
    {
        currentNode.isBST = true;
    }
    else
    {
        currentNode.isBST = false;
    }
    //update answer
    if(currentNode.isBST)
    {
        ans = max(ans,currentNode.size);
    }
    return currentNode;
}

//main driver function
int main()
{
    Node* root = NULL;
    cout<<"Enter Data for BST Nodes"<<endl;
    takeInput(root);
    int maxSize = 0;
    info temp = largestBSTInBT(root,maxSize);
    cout<<"Largest BST size is: "<<maxSize<<endl;
    
    return 0;
}