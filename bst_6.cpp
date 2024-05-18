#include<iostream>
#include<queue>
using namespace std;

//Node
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

Node* insertIntoBST(Node* root,int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if(data < root->data)
    {
        root->left = insertIntoBST(root->left,data);
    }
    else if (data > root->data)
    {
        root->right = insertIntoBST(root->right,data);
    }
    
}

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

//k-th smallest element
int kthElement(Node* root,int &i,int k)
{
    //base case
    if(root == NULL)
    {
        return -1;
    }
    
    //left part
    int left = kthElement(root->left,i,k);
    if(left != -1)
    {
        return left;
    }
    //node
    i++;
    if(i == k)
    {
        return root->data;
    }
    //right 
    return kthElement(root->right,i,k);
}

int main()
{
    Node* root = NULL;
    cout<<"Enter data for Tree Nodes"<<endl;
    takeInput(root);
    cout<<"Print Tree Nodes level wise"<<endl;
    levelOrderTraversal(root);

    //kth smallest element
    int i = 0;
    int k = 3;
    int smallest_element = kthElement(root,i,k);
    cout<<" "<<k<<"   Smallest element in BST is  "<<smallest_element<<endl;
    return 0;
}