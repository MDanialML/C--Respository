#include <iostream>
#include <queue>
#include <limits>
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

Node* insertIntoBST(Node* root, int data)
{
    //base condition
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if(data >= root->data)
    {
        root->right = insertIntoBST(root->right,data);
    }
    else if (data <= root->data)
    {
        root->left = insertIntoBST(root->left,data);
    }
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;
    while(data != -1)
    {
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

//level order traversal
void levelOrderTracer(Node* root)
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
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

bool isValidBST(Node* root,int min,int max)
{
    //base case 
    if(root == NULL)
    {
        return true;
    }

    if(root->data > min && root->data < max)
    {
        bool left = isValidBST(root->left,min,root->data);
        bool right = isValidBST(root->right,root->data,max);
        return left && right;
    }
    else
    {
        return false;
    }
    
}

int main()
{
    Node* root = NULL;
    cout<<"Enter data For Node"<<endl;
    takeInput(root);
    cout<<"Level Order Node Printing"<<endl;
    levelOrderTracer(root);
    cout<<"Check for valid BST"<<endl;
    int min = INT8_MIN;
    int max = INT8_MAX;
    bool valid = isValidBST(root,min,max);
    if(valid)
    {
        cout<<"Given Tree is valid BST"<<endl;
    }
    else
    {
        cout<<"Given Tree is not a Valid BST"<<endl;
    }
    
    return 0;
}