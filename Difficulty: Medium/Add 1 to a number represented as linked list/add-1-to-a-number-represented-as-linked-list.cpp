//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    
    // +++++++++++++ Brute Force +++++++++++ TC O(3N).  SC O(1)
    
    // reverse the LL
      Node* reverseList(Node* head) {
      if (head == NULL || head -> next == NULL) return head;

    Node* newHead = reverseList(head -> next);
    Node* front = head -> next;
    front -> next = head;
    head -> next = NULL;

    return newHead;
      }
      
public:
    Node* addOne(Node *head) 
    {
        head = reverseList(head); // first reverse the given LL
        
        Node* temp = head;
        
 
        
        int carry =1; // carry = 1 beacuse we need to add 1
         
        while(temp != NULL){
            temp -> data = temp->data +carry; // sum the value of node with carry
             
            if(temp->data  < 10){ // if sum is less then 10 
                carry = 0; // carry = 0
                break;// break because now there will be no carry
            }else{
                temp->data = 0; // is sum is greater then 10 then value should be 0 
                carry = 1; // ansd carry = 1
            }
        
            
            temp = temp->next;
        }
        
        if(carry == 1){ // now if carry is one 
             Node* newNode = new Node(1); // then create a new node with carry value 12
            
             head = reverseList(head);
             newNode -> next = head; // newHead will be the newNode
            
             return newNode; // return that newHead 
        }
        
        head = reverseList(head);// if carry is 0 then reverse the LL
                  
        return head; // and return head
        
    }
      
      
    
    // ++++++++++++ Optimal Solution ++++++++++++ TC O(N).   SC O(N)
    
    // int helperFunc(Node* temp){
    //     if(temp == NULL) return 1; // for base case carry is 1
        
    //     int carry = helperFunc(temp -> next); // call same func with the next Node
        
    //     temp->data = temp->data + carry; // sum the value of the ndoe and carry
        
    //     if(temp->data < 10){ // if sum is less then 10 the return carry = 1
    //         return 0;
    //     }
        
    //     temp->data = 0; // else data will be 0 because sam = 10 
        
    //     return 1; // return carry = 1
        
    // }
    // public:
    // Node* addOne(Node *head) 
    // {
    //     int carry = helperFunc(head); // this func will return carry
        
    //     if(carry == 1 ){ // if carry is 1
    //         Node* newNode = new Node(1); // then create a new node with carry value 12
            
    //         newNode -> next = head; // newHead will be the newNode
            
    //         head = newNode; // return that newHead 
    //     }
        
    //     return head;
    // }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends