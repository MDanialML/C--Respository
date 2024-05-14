#include<iostream>
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

//functiont to get minimum node from a BST
Node* getMinimumNode(Node* root)
{
    Node* temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

//function to delete a specified node binary tree
Node* deleteFromBSt(Node* root,int val)
{
    if(root == NULL)
        return NULL;

    if(root->data == val)
    {
        //0-child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        //1-child
        //left child
        else if(root->left != NULL && root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == NULL && root->right != NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2-child
        else if(root->left != NULL && root->right != NULL)
        {
            int mini = getMinimumNode(root->right)->data;
            // cout<<"I reached here where target node has two child.............!!!!!!!"<<endl;
            root->data = mini;
            root->right = deleteFromBSt(root->right,mini);
            return root;
        }
    }
    else if(root->data > val)
    {
        root->left = deleteFromBSt(root->left,val);
    }
    else
    {
        root->right = deleteFromBSt(root->right,val);
    }
}



int main()
{
    Node* root = NULL;
    cout <<"Enter Data for BST Nodes"<<endl;
    takeInput(root);
    cout<<"Print BST Nodes"<<endl;
    levelOrderTraversal(root);
    root = deleteFromBSt(root,5);
    cout<<"After deleting specified Node"<<endl;
    levelOrderTraversal(root);
    
    return 0;
}