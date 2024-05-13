#include <iostream>
#include <queue>
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

Node* insertIntoBST(Node* root,int val)
{
    //base case 
    if(root == NULL)
    {
        root = new Node(val);
        return root;
    }
    //recursive call for left sub BST
    if(root->data > val)
    {
        root->left = insertIntoBST(root->left,val);
    }
    else
    {
        root->right = insertIntoBST(root->right,val);
    }
}

void takeInput(Node* &root)
{
    int data;
    cin >> data;
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
            if(!q.empty())
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
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int inOrderSuccessor(Node* root,int val)
{
    while(root != NULL)
    {
        int successor = -1;
        if(val >= root->data)
        {
            root = root->right;
        }
        else
        {
            successor = root->data;
            root = root->left;
        }
        return successor;
    }
}

int main()
{
    Node* root = NULL;
    cout <<"Enter Data for BST Nodes"<<endl;
    takeInput(root);
    cout<<"Print BST Nodes"<<endl;
    levelOrderTraversal(root);
    int target;
    cout<<"Enter value to check their Successor:    "<<endl;
    cin>>target;
    int successor = inOrderSuccessor(root,target);
    if(successor != -1)
    {
        cout<<"Successor FOund :    "<<successor<<endl;
    }
    else
    {
        cout <<"Successor NOt Found:    "<<endl;
    }
    
    return 0;
}