//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}

// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
     // ++++++++++ Brute Force Approch ++++++++++++ TC O(N + 2 logN) +++++ SC O(N)

        // map<Node*,int> mpp; // craete Map of Node* and timer
        // Node* temp = head;
        // int timer = 1;

        // while(temp != NULL){
        //     if(mpp.find(temp) != mpp.end()){ // check if Node is already present in map or not
        //         int value = mpp[temp]; // get the timer value of that Node
        //         return (timer - value); // return current timer value - that Node value
        //     }

        //     mpp[temp] = timer; // else fix the timer value to giver node
        //     timer++;// increase the timer value
        //     temp = temp -> next; 
        // }

        // return 0;
        
        
        // ++++ Optimal Solution [TortoiseHare Method] ++++++++++ TC O(N ) +++++ SC O(1)
        
        Node* slow = head; // move by 1 node everytime
        Node* fast = head;// move by 2 node everytime

        while (fast != NULL && fast->next != NULL) { // fast stop at last or NULL node
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow){// if loop present then both are collide at same node other wise they will not colide
             int  count = 1; // take count = 1
             slow = slow -> next; // because we alraedy move slow by one
            
             while(slow != fast){ // continue till both meet again
                count++; 
                slow = slow-> next; // move slow by one
             }
    
            return count; // return count
                
            }
        }

        return 0;
}
