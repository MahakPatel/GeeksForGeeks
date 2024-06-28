//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        //++++++++++++++ Optimal Solution ++++++++++++TC O(N).   SC O(1)
        Node* zeroHead = new Node(-1); // create a dummyNode for zero's List
        Node* oneHead = new Node(-1); // create a dummyNode for one's List
        Node* twoHead = new Node(-1); // create a dummyNode for two's List
        
        Node* zero = zeroHead; // Create zero node for zero's tarversal
        Node* one = oneHead;// Create one node for one's tarversal
        Node* two = twoHead;// Create two node for two's tarversal
        
        Node* temp = head;
        
        while(temp!=NULL){ // run till last node
            if(temp-> data == 0){ // if temp -> data == 0 
                zero->next = temp; // zero node's next point to temp
                zero = zero-> next; // and aslo move zero node to next
            }
            else if(temp-> data == 1){ // if temp -> data == 1 
                one->next = temp;// one node's next point to temp
                one = one-> next;// and aslo move one node to next
            }else{ // if temp -> data == 2
                two->next = temp;// two node's next point to temp
                two = two-> next;// and aslo move two node to next
            }
            
            temp = temp-> next;
        }
        // now connect last node of zero to first node of one
        
                      // check if one node is present // if present then connect to oneHead of next // if one node is not present then point to twoHead of next Node 
        zero -> next = (oneHead -> next) ? (oneHead -> next) : (twoHead -> next);
        one -> next = twoHead -> next; // point last nodr of one to first node of two
        two -> next = NULL; // point last node of two to NULL
        
        Node* newHead = zeroHead -> next; // new head become ZeroHead -> next(which is first node of zero)
        
        delete(zeroHead);
        delete(oneHead);
        delete(twoHead);
        
        return newHead;
        
        
        
        // ++++++++ Brute Force +++++++ TC O(2N). SC O(1)
        
    //   int count0=0;  // to count number of 0
    //   int count1=0;// to count number of 1
    //   int count2=0;// to count number of 2
       
    //   Node* temp = head;
       
    //   while(temp!=NULL){
    //       if(temp -> data == 0){ // if temp data is 0 increase count0 by 1
    //           count0++;
    //       }
    //       else if(temp -> data == 1){  // if temp data is 1 increase count1 by 1
    //           count1++;
    //       }else{
    //           count2++;  // if temp data is 2 increase count2 by 1
    //       }
           
    //       temp = temp-> next;
    //   }
       
    //   temp = head;
       
    //   while(temp!=NULL){
    //       if(count0){ // if count0 has value
    //           temp -> data = 0; // then assign to temp -> data 
    //           count0--;
    //       }else if(count1){
    //           temp-> data = 1;
    //           count1--;
    //       }else{
    //           temp -> data = 2;
    //           count2--;
    //       }
           
    //       temp = temp-> next;
    //   }
       
    //   return head;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends