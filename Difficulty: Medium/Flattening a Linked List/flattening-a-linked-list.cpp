//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // ++++++++++++++++++ Optimal Solution +++++++++++++++
    // TC O(n)
    // SC O(1)
    // Merges two sorted linked lists.
    Node *mergeList(Node *a, Node *b) {
        Node *temp = new Node(0); // Dummy node to build the result
        Node *res = temp;  // Keeps track of the result list
        
        // Traverse both lists and merge them
        while (a != NULL && b != NULL) {
            if (a->data < b->data) {
                temp->bottom = a;  // Attach a to the result list
                temp = temp->bottom;
                a = a->bottom;  // Move to the next node in list a
            } else {
                temp->bottom = b;  // Attach b to the result list
                temp = temp->bottom;
                b = b->bottom;  // Move to the next node in list b
            }
        }
    
        // If one list is exhausted, attach the remaining nodes of the other list
        if (a) temp->bottom = a;
        else temp->bottom = b;
    
        return res->bottom;  // Return the flattened result (skip dummy node)
    }
    
    // Function which flattens the linked list of linked lists.
    Node *flatten(Node *root) {
        if (root == NULL || root->next == NULL) return root;  // Base case: Single list or empty list
        
        // Recursively flatten the next list
        root->next = flatten(root->next);
        
        // Merge the current list with the flattened next list
        root = mergeList(root, root->next);
        
        return root;  // Return the flattened list
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends