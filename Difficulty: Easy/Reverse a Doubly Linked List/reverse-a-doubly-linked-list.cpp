//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}




void displayList(Node *head)
{
    //Head to Tail
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
    
    
    
}


int getLength(Node * head)
{
    Node *temp=head;
    
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}




bool verify(Node* head)
{
    int fl=0;
    int bl=0;
    
    Node *temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
        fl++;
    }
    
    while(temp->prev)
    {
        temp=temp->prev;
        bl++;
    }
    
    return fl==bl;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        
        // +++++++++ Optimal Solution TC O(N)    SC O(1)
        
        if( head == NULL || head -> next == NULL) return head; // if DLL is empty or 1 element
        Node* current = head;
        Node* back = NULL;
        
        while(current != NULL){
            back = current -> prev; // first store back value
            current -> prev = current -> next; // now chcek next value with previous value
            current -> next = back; // now assign next value to back and make connection
            
            current = current -> prev; // now move current to next node
            
        }
        
        
        return back -> prev; // beacuase now back is at econd last element
    }
        // ++++++++++ Brute Force Approch++++++++++++++ TC O(2N) SC O(N)
    //     // if head is empty or there is only one element
    // // we can directly just return the head
    // if(head==NULL || head->next == NULL){
    //     return head;
    // }
    
    // // Initialise a stack st
    // stack<int> st;
    
    // // Initialise the node pointer temp at head
    // Node* temp = head;
    
    // // Traverse the doubly linked list via the temp pointer
    // while(temp!=NULL){
    //     // insert the data of the current node into the stack
    //     st.push(temp->data);
    //     // traverse further
    //     temp = temp->next;
    // }
    
    // // Reinitialise temp to head
    // temp = head;
    
    // // Second iteration of the DLL to replace the values
    // while(temp!=NULL){
    //     // Replace the value pointed via temp with
    //     // the value from the top of the stack
    //     temp->data = st.top();
    //     // Pop the value from the stack
    //     st.pop();
    //     // Traverse further
    //     temp = temp->next;
    // }
    
    // // Return the updated doubly linked 
    // // where the values of nodes from both ends 
    // // has been swapped
    // return head;
    // }
};



//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL, *tail=NULL;
        int x;
	    cin>>x;
	    head = newNode(x);
	    tail = head;
	    
	    for(int i=0;i<n - 1;i++)
	    {
	        cin>>x;
	        Node* temp=newNode(x);
	        tail->next=temp;
	        temp->prev= tail;
	        tail = temp;
	    }
	    Solution ob;
	    head=ob.reverseDLL(head);
	    
	    
	    if(verify(head))
	    displayList(head);
	    else
	    cout<<"Your pointers are not correctly connected";
 
	    cout<<endl;
	}
	return 0;
}


// } Driver Code Ends