#include<iostream>
#include<vector>
using namespace std;

//Tree Node
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


bool twoSumExist(Node* root, int target)
{
    vector<int> inOrderValues;
    inOrderTraversal(root,inOrderValues);

    //Two pointer approach
    int start = 0;
    int end = inOrderValues.size() - 1;
    while (start < end)
    {
        int sum;
        sum = inOrderValues[start] + inOrderValues[end];
        if(sum == target)
        {
            return true;
        }
        if(sum > target)
        {
            end--;
        }
        if(sum < target)
        {
            start++;
        }
    }
    return false;
}

int main()
{
    Node* root = NULL;
    cout<<"Enter Data for tree Nodes"<<endl;
    takeInput(root);
    int target = 55;
    bool cond = twoSumExist(root,target);
    if(cond)
    {
        cout<<"Two sum Exist in Given BST"<<endl;
    }
    else
    {
        cout<<"Two Sum Not exist in this BST"<<endl;
    }
    return 0;
}