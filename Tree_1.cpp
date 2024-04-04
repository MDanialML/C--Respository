#include <iostream>
using namespace std;

//Binary tree Node implementation
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

Node* buildTree(Node* root)
{
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter data for inserting to the left of: "<<data<<endl;
    //recursive call for creating left child Node
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting to the right of: "<<data<<endl;
    //recursive call for creating right child Node
    root->right = buildTree(root->right);
    return root;
}

int main()
{
    Node* root = NULL;
    //creating a binary tree
    root = buildTree(root);
}