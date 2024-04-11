#include <iostream>
using namespace std;

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
        this -> right = NULL;
    }
};

//function to build Tree
Node* buildTree(Node* root)
{
    cout <<"Enter data: ";
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1)
    {
        return NULL;
    }
    cout <<"Enter data for inserting to the left of: "<<data<<endl;
    root -> left = buildTree(root->left);
    cout <<"Enter data for inserting to the Right of: "<<data<<endl;
    root -> right = buildTree(root -> right);
    return root;
}

//In-Order Tracer
void inOrderTracer(Node* root)//Left Node Right
{
    //base condition
    if(root == NULL)
    {
        return;
    }
    inOrderTracer(root -> left);
    cout<<root -> data<<" ";
    inOrderTracer(root -> right);
}

//Pre-Order Tracer
void preOrderTracer(Node* root) //Node Left Right
{
    //base condition
    if(root == NULL)
    {
        return;
    }
    cout<<root -> data<<" ";
    preOrderTracer(root->left);
    preOrderTracer(root -> right);
}

//Post Order Tracer
void postOrderTracer(Node* root) // Left Right Node
{
    //base condition
    if(root == NULL)
    {
        return;
    }
    postOrderTracer(root -> left);
    postOrderTracer(root -> right);
    cout<<root -> data<<" ";
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    cout<<endl;
    cout<<endl;
    cout<<"     In-Order Tracer"<<endl;
    cout<<endl;
    inOrderTracer(root);
    cout<<endl;

    cout<<endl;
    cout<<endl;
    cout<<"     Pre-Order Tracer"<<endl;
    cout<<endl;
    preOrderTracer(root);
    cout<<endl;

    cout<<endl;
    cout<<endl;
    cout<<"     Post-Order Tracer"<<endl;
    cout<<endl;
    postOrderTracer(root);
    cout<<endl;
    return 0;
}