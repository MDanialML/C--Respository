#include <iostream>
#include<queue>
using namespace std;

//class Node
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

//insert into bst
Node* insertIntoBST(Node* root,int data)
{
    //base case
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if(root->data >= data)
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
            if (temp->left)
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

Node* findLowestCommonAncesstor(Node* root,int key_1,int key_2)
{
    //recursive solution
    //base case 
    /*
    if(root == NULL)
    {
        return NULL;
    }

    //finding LCA for keys in left subtree
    if(root->data > key_1 && root->data > key_2)
    {
        return findLowestCommonAncesstor(root->left,key_1,key_2);
    }
    //find LCA in right subTree
    if(root->data < key_1 && root->data < key_2)
    {
        return findLowestCommonAncesstor(root->right,key_1,key_2);
    }
    return root;
    */

   //iterative approach 
    while (root != NULL)
    {
        if(root->data > key_1 && root->data > key_2)
        {
            root = root->left;
        }
        else if(root->data < key_1 && root->data < key_2)
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }
}

int main()
{
    Node* root = NULL;
    cout<<"Enter data for BST nodes     "<<endl;
    takeInput(root);
    cout<<"Print BST Nodes"<<endl;
    levelOrderTraversal(root);
    cout<<"Get Lowest common ancesstor"<<endl;
    int key_1;
    int key_2;
    cout<<"Enter first key Value"<<endl;
    cin>> key_1;
    cout<<"Enter second Key Value"<<endl;
    cin>> key_2;
    Node* ancesstor = findLowestCommonAncesstor(root,key_1,key_2);
    if(ancesstor)
    {
        cout<<"Lowest common Ancesstor "<<ancesstor->data<<endl;
    }
    else
    {
        cout<<"Ancesstor not exist"<<endl;
    }
    
    return 0;
}