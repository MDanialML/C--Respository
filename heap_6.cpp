#include <bits/stdc++.h>
using namespace std;


//binary tree
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

//inssert into BST
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
            cout<<temp->data<<"   ";
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

void inOrderTraversal(Node* root,vector<int>&arr)
{
    if(root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left,arr);
    arr.push_back(root->data);
    inOrderTraversal(root->right,arr);
}

void constructMinHeap(Node* root,int &i,vector<int>&in)
{
    root->data = in[i++];
    if(root-> left)
    {
        constructMinHeap(root->left,i,in);
    }
    if(root->right)
    {
        constructMinHeap(root->right,i,in);
    }
}


int main()
{
    Node* root = NULL;
    cout<<"Enter Data for BST nodes:"<<endl;
    takeInput(root);
    levelOrderTraversal(root);
    vector<int> inOrder;
    inOrderTraversal(root,inOrder);
    for (int i = 0; i < inOrder.size();i++)
    {
        cout<<inOrder[i]<<"   ";
    }cout<<endl;
    int i = 0;
    constructMinHeap(root,i,inOrder);
    levelOrderTraversal(root);
    return 0;
}