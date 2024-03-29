#include <iostream>
#include <vector>
using namespace std;

//Node template
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }

    //destructor
    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Memory is freedup for Node: "<<value<<endl;
    }
};
//head of linked list initially NULL means link list is empty
Node* head = NULL;
class InserNode{
    public:
    void insert(int value)
    {
        Node* obj = new Node(value);
        if(head == NULL)
        {
            obj->next = head;
            head = obj;
        }
        else
        {
            obj->next = head;
            head = obj;
        }
        
    }
};

//print element of linked list
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data <<"-";
        temp = temp->next;
    }
    cout <<endl;
}

//first approach 
void firstApproach(vector<int> &arr,Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    //check for valid palindrome
    int start = 0;
    int len = arr.size();
    int end = len - 1;
    while(start <= end)
    {
        if(arr[start] != arr[end])
        {
            cout<<"Link List is not a Palindrome.!"<<endl;
            return;
        }
        start++;
        end--;
    }
    cout <<"Link list is valid palindrome.!"<<endl;
}

//get middle node
Node* getMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

//reverse second half of 
Node* reversedHalf(Node* head)
{
    Node* previous = NULL;
    Node* current = head;
    Node* next = 0;
    while(current != NULL)
    {
        next = current -> next;
        current -> next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

//check palindrome
bool isPalindrome(Node* head)
{
    Node* mid = getMiddle(head);
    Node* temp = mid->next;
    mid->next = reversedHalf(temp);
    // cout <<"check wheter second half of link list is reversed or not"<<endl;
    //check valid palindrome
    Node* head1 = head;
    Node* head2 = mid -> next;
    while(head2 != NULL)
    {
        if (head1->data != head2 -> data)
        {
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    // temp = mid->next;
    // mid->next = reversedHalf(temp);

    return true;
    // cout<<"Link list is valud Palindrome"<<endl;
    // print (head);
}
//driver function
int main()
{
    InserNode obj;
    obj.insert(4);
    obj.insert(3);
    obj.insert(2);
    obj.insert(1);
    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    print(head);

    //first approach
    // vector<int> arr;
    // firstApproach(arr,head);
    // Node* middle = getMiddle(head);
    // cout <<"Middle node :   "<<middle->data<<endl;
    if(isPalindrome(head))
    {
        cout <<"Linked list is palindrome"<<endl;
    }
    else
    {
        cout <<"Linked list is not a palindrome"<<endl;
    }
    print(head);

    return 0;
}