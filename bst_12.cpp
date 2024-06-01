#include <iostream>
#include<vector>
#include<queue>
using namespace std;

//BST Node
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//insert data into bst
Node* insertIntoBST(Node* root,int data)
{
    //base case
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }
    //recursive call for left part
    if(root->data > data)
    {
        root->left = insertIntoBST(root->left,data);
    }
    else
    {
        root->right = insertIntoBST(root->right,data);
    }
    
}

//take input
void takeInput(Node* &root)
{
    int data;
    cin>>data;
    while (data != -1)
    {
        root = insertIntoBST(root,data);
        cin>> data;
    }
}

//pre order traversal of bst
void preOrderTraversal(Node* root,vector<int>&preOrder)
{
    if(root == NULL)
    {
        return;
    }
    preOrder.push_back(root->data);
    if(root->left)
    {
        preOrderTraversal(root->left,preOrder);
    }
    if(root->right)
    {
        preOrderTraversal(root->right,preOrder);
    }
}

//create BST
Node* createPreBST(vector<int> pre,int min,int max,int &i)
{
    //base case
    if(i >= pre.size())
    {
        return NULL;
    }
    if(pre[i] < min || pre[i] > max)
    {
        return NULL;
    }

    Node* root = new Node(pre[i++]);
    root->left = createPreBST(pre,min,root->data,i);
    root->right = createPreBST(pre,root->data,max,i);
    return root;
}

//level order traversal
void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
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
    cout<<"Enter values for BST Nodes"<<endl;
    takeInput(root);
    cout<<"BST is finally created..!"<<endl;
    cout<<endl;
    cout<<endl;
    vector<int> preOrder;
    preOrderTraversal(root,preOrder);

    // for(int i = 0; i < preOrder.size();i++)
    // {
    //     cout<<preOrder[i]<<"-";
    // }cout<<endl;

    //creating a BST from given preOrder
    int min = INT16_MIN;
    int max = INT16_MAX;
    int i = 0;
    Node* newTree = createPreBST(preOrder,min,max,i);
    cout<<"Re Creation Done.!"<<endl;
    cout<<"Now printing new tree data level wise"<<endl;
    levelOrderTraversal(newTree);
    return 0;
}