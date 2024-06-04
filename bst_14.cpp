//Merge 2 binary search tree into a Doubly linkedlist and then to a BST
#include<iostream>
#include<queue> //for level Order Traversal
using namespace std;

//Node
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
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right,data);
    }
    
}

//takeinput
void takeInput(Node* &root)
{
    int data;
    cin >> data;
    while (data != -1)
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
    while(!q.empty())
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
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

//bst to sorted doubly link list
void bstToSortedDLL(Node* root,Node* &head)
{
    //base case
    if(root == NULL)
    {
        return;
    }
    //right subtree to DDL
    bstToSortedDLL(root->right,head);
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    
    head = root;
    //left subtree to Sorted DLL
    bstToSortedDLL(root->left, head);
}

//merge two linkendList
Node* mergeTwoLinkedList(Node* head1, Node* head2)
{
    Node* head = NULL;
    Node* tail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

//print DLL
void printDLL(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<"-";
        temp = temp->right;
    }
}
//count total nodes in a DLL
int countNodes(Node* root)
{
    // Node* temp = root;
    // int cnt = 0;
    // while(temp != NULL)
    // {
    //     cnt++;
    //     temp = temp->right;
    // }
    if (root == NULL) {
        return 0;
    }

    Node* temp = root;
    int cnt = 0;
    while (temp != NULL) {  // Traverse right
        cnt++;
        temp = temp->right;
    }

    temp = root->left;  // Traverse left
    while (temp != NULL) {
        cnt++;
        temp = temp->left;
    }

    return cnt;
}

Node* sortedDLLToBST(Node* head,int n)
{
    //base case
    if(n <= 0 || head == NULL)
    {
        return NULL;
    }
    Node* left = sortedDLLToBST(head,n/2);
    Node* root = head;
    root->left = left;
    head = head->right;
    if(head != NULL)
    {head->right = sortedDLLToBST(head,n-n/2-1);}
    return root;
}

//main driver function
int main()
{
    Node* root1 = NULL;
    cout<<"Enter Data for BST Nodes"<<endl;
    takeInput(root1);
    cout<<"First Tree created Successfully.!"<<endl;
    levelOrderTraversal(root1);

    Node* root2 = NULL;
    cout<<"Enter Data for BST Nodes"<<endl;
    takeInput(root2);
    cout<<"Second Tree created Successfully.!"<<endl;
    levelOrderTraversal(root2);

    //step 1 Create Sorted Doubly linkendList from BST
    //fisrt BST
    Node* head1 = NULL;
    bstToSortedDLL(root1,head1);
    head1->left = NULL;
    cout<<"Successfully converted first BST to Doubly linkendlist"<<endl;
    cout<<endl;
    cout<<endl;
    //second BST
    Node* head2 = NULL;
    bstToSortedDLL(root2,head2);
    head2->left = NULL;
    cout<<"Successfully Converted second BST to doubly LinkedList"<<endl;
    cout<<endl;
    cout<<endl;

    //step 2 merge 2 sorted doubly linkendList
    Node* sortedDLL = mergeTwoLinkedList(head1,head2);
    cout<<"Sorted Doubly linkendList created successfully"<<endl;
    cout<<"Printing sorted DLL"<<endl;
    printDLL(sortedDLL);
    cout<<endl;

    //step 3 create a BST from sorted doubly linkendList
    int nodeCount = countNodes(sortedDLL);
    Node* finalBST = sortedDLLToBST(sortedDLL,nodeCount);
    cout<<"Doubly Linked List to BST conversion completed"<<endl;
    levelOrderTraversal(finalBST);
    // cout<<"Total Node Count:    "<<nodeCount<<endl;
    
    return 0;
}