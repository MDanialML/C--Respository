#include<iostream>
#include<vector>
using namespace std;


//class node
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

//insert into BST
Node* insertIntoBST(Node* root,int data){
    
    //basecase
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    //left tree
    if(data <= root->data)
    {
        root->left = insertIntoBST(root->left,data);
    }
    //right part
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
        cin >> data;
    }
}

//inorder Traversal
void inOrderTraversal(Node* root, vector<int> &in)
{
    //base case
    if(root == NULL)
    {
        return;
    }
    
    //left call
    if(root->left)
    {
        inOrderTraversal(root->left,in);
    }
    in.push_back(root->data);
    if(root->right)
    {
        inOrderTraversal(root->right,in);
    }
}


//create sorted singly linked list from a bst
Node* sortedLinkedList(Node* root)
{
    //first step store inorder traversal
    vector<int> inOrderValues;
    inOrderTraversal(root,inOrderValues);
    Node* newRoot = new Node(inOrderValues[0]);
    Node* current = newRoot;
    int size = inOrderValues.size();
    //second step make left pointer NULL and right to next element in vector
    for(int i = 1; i<size;i++)
    {
        Node* temp = new Node(inOrderValues[i]);
        newRoot->left = NULL;
        newRoot->right = temp;
        current = temp;
    }
    //3rd and last step point last element to left and right pointer to NUll
    current->left = NULL;
    current->right = NULL;
    return newRoot;
}

//print tree data
void printInOrder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left)
    {
        printInOrder(root->left);
    }
    cout<<root->data<<"     ";
    if (root->right)
    {
        printInOrder(root->right);
    }
    
}

int main()
{
    Node* root = NULL;
    cout<<"Enter data for BST Nodes"<<endl;
    takeInput(root);
    Node* linkList = sortedLinkedList(root);
    printInOrder(linkList);
    return 0;
}