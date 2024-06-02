#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//BST node
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

//insert Into BST
Node* insertIntoBST(Node* root,int data)
{
    //base case
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if(root->data > data)
    {
        root->left = insertIntoBST(root->left,data);
    }
    else
    {
        root->right = insertIntoBST(root->right,data);
    }
    
}

//take Input
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

//level Order traversal
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

void inOrderTraversal(Node* root, vector<int> &vec)
{
    //base case
    if(root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left,vec);
    vec.push_back(root->data);
    inOrderTraversal(root->right,vec);
}

//merge two sorted array
vector<int> mergeTwoArrays(vector<int> &arr1,vector<int> &arr2)
{
    vector<int> ans(arr1.size() + arr2.size());
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] <= arr2[j])
        {
            ans[k++] = arr1[i];
            i++;
        }
        else
        {
            ans[k++] = arr2[j];
            j++;
        }
    }

    while(i < arr1.size())
    {
        ans[k++] = arr1[i];
        i++;
    }

    while (j < arr2.size())
    {
        ans[k++] = arr2[j];
        j++;
    }
    return ans;
}

//sorted array to bst using in-order
Node* arrayToBST(int start,int end, vector<int>&arr)
{
    //base case
    if(start > end)
    {
        return NULL;
    }
    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);
    root->left = arrayToBST(start,mid-1,arr);
    root->right = arrayToBST(mid+1,end,arr);
    return root;
}

int main()
{
    //BST creation
    cout<<"Enter Data For first BST"<<endl;
    Node* BST1 = NULL; 
    //10 8 4 2 12 16 20 -1
    takeInput(BST1);
    cout<<"First BST created successfully"<<endl;
    levelOrderTraversal(BST1);
    cout<<endl;
    cout<<endl;

    cout<<"Enter data for second BST"<<endl;
    Node* BST2 = NULL;
    //30 28 26 27 35 33 39 41 -1
    takeInput(BST2);
    cout<<"Second BST created Successfully"<<endl;
    levelOrderTraversal(BST2);
    cout<<endl;
    cout<<endl;

    //Problem merge 2 Binary search Tree
    //step#1 save inoder of Both Trees
    cout<<"     MERGE TWO BST       "<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Step 1 save In-Order of Both given trees "<<endl;
    vector<int> bst1Values;
    inOrderTraversal(BST1,bst1Values);

    vector<int> bst2Values;
    inOrderTraversal(BST2,bst2Values);
    cout<<"Step One Completed"<<bst1Values.size()<<"    "<<bst2Values.size()<<endl;
    cout<<endl;
    cout<<endl;

    //step#2
    cout<<"Step# 2 Merge two Sorted array/vector i,e In-order of Both BST"<<endl;
    vector <int> mergedArray = mergeTwoArrays(bst1Values,bst2Values);
    cout<<"Sorted merge Complete..!"<<endl;
    for(int i = 0; i < mergedArray.size(); i++)
    {
        cout<<mergedArray[i]<<"-";
    }
    cout<<endl;

    //step#3
    cout<<"Step 3:- creating new  BST from sorted Array"<<endl;
    int start = 0;
    int end = mergedArray.size();
    Node* mergedTree = arrayToBST(start,end,mergedArray);
    cout<<"Successfully created merged BST...!!"<<endl;
    cout<<endl;
    cout<<endl;
    levelOrderTraversal(mergedTree);
    return 0;
}