#include <iostream>
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

Node* insertIntoBST(Node* root,int d)
{
    //base case
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if(d > root->data)
    {
        root->right = insertIntoBST(root->right,d);
    }
    else
    {
        root->left = insertIntoBST(root->left,d);
    }
    
}

void takeInput(Node* &root)
{
    int data;
    cin >>data;
    while(data != -1)
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
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
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

bool searchInBST(Node* root, int value)
{
    //base case
    if(root == NULL)
    {
        return false;
    }
    if(root->data == value)
    {
        return true;
    }
    if(value < root->data)
    {
        return searchInBST(root->left,value);
    }
    else
    {
        return searchInBST(root->right,value);
    }
}

int findMinElement(Node* root)
{
    Node* temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int findMaxElement(Node* root)
{
    Node* temp = root;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

int main()
{
    Node* root = NULL;
    cout << "Enter data to Construct Tree"<<endl;
    takeInput(root);
    // cout<<"Print the Data"<<endl;
    // levelOrderTraversal(root);
    // bool found = searchInBST(root,7);
    // if(found)
    // {
    //     cout<<"Value Found "<<endl;
    // }
    // else
    // {
    //     cout<<"Value Not Found"<<endl;
    // }

    return 0;
}