#include<bits/stdc++.h>
using namespace std;

//heap implementation
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

//insert into bst
Node* insertIntoBT(Node* root,int data)
{
    if(root == NULL)
    {
        return new Node(data);
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(!temp->left)
        {
            temp->left = new Node(data);
            return root;
        }else
        {
            q.push(temp->left);
        }
        if(!temp->right)
        {
            temp->right = new Node(data);
            return root;
        }else
        {
            q.push(temp->right);
        }
    }
    return root;
}

//take input
void takeInput(Node* &root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBT(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root)
{
    queue<Node*>q;
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
            cout<< temp->data<<"  ";
            if(temp->left)
            {
                q.push(temp-> left);
            }
            if(temp -> right)
            {
                q.push(temp->right);
            }
        }
    }
}

//function for checking given BT is max heap or not
//check for complete binanry tree
//count total Nodes
int countNode(Node* root)
{
    //base case 
    if(root == NULL)
    {
        return 0;
    }
    int ans = 1 + countNode(root->left) + countNode(root->right);
    return ans;
}
bool isCBT(Node* root,int i,int totalCount)
{
    //base case
    if(root == NULL)
    {
        return true;
    }
    if(i >= totalCount)
    {
        return false;
    }
    else
    {
        bool left = isCBT(root-> left,2 * i + 1,totalCount);
        bool right = isCBT(root -> right, 2 * i + 2,totalCount);
        return (left && right);
    }
}

//Is given tree statisfie max heap propertise
bool isMaxHeap(Node* root)
{
    //base case 
    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if(root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else
    {
        bool left = isMaxHeap(root->left);
        bool right = isMaxHeap(root->right);
        if (left && right && (root->data > root->left->data && root->data > root->right->data))
        {
            return true;
        }else
        {
            return false;
        }
        
    }
}

int main()
{
    Node* root = NULL;
    cout<<"Enter data for Binary Tree Nodes:    "<<endl;
    takeInput(root);
    cout<<"Print Binary Tree"<<endl;
    levelOrderTraversal(root);
    cout<<"Check for Max heap:  "<<endl;
    int i = 0;
    if(isCBT(root,i,countNode(root)) && isMaxHeap(root) )
    {
        cout<<"Given Binary is a Heap.!"<<endl;
    }
    else
    {
        cout<<"Given Binary Tree is Not a Max Heap"<<endl;
    }
    
    return 0;
}