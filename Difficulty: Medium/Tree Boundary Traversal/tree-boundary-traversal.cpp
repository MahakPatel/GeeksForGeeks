//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
  // Function to check
    // if a node is a leaf
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }
    
    void addLeftBoundary(Node *root,vector<int> &res){
    Node* cur = root->left; // move to left side
    while(cur){ // run till cur move to valid left 
        if(!isLeaf(cur)){ // if not a leaf not 
            res.push_back(cur->data); // push that node data into res
            
        }
        
        if(cur->left){ // if valid
            cur = cur->left; // move to left 
        }else{
            cur = cur->right; // move to right
        }
    }
    
}
    void addLeafsNode(Node *root,vector<int> &res){
        if(isLeaf(root)){ // if it is a leaf node
            res.push_back(root->data); // push to res
            return;
        }
        
        if(root->left) addLeafsNode(root->left,res); // move left and call that func again
        if(root->right) addLeafsNode(root->right,res);// move right and call that func again
    }
    
    void addRightBoundary(Node *root,vector<int> &res){
        Node* cur = root->right; // move to right
        vector<int> temp; // for storing right side boundary node
        while(cur){
            if(!isLeaf(cur)) temp.push_back(cur->data); // if not a leaf push into res
            
            if(cur -> right){ // if valid move right
                cur = cur->right;
            }else{
                cur = cur->left; // move left
            }
        }
        
        for(int i=temp.size() - 1; i>=0;i--){ // now push right side node in reverse position 
            res.push_back(temp[i]);
        }
    }
    
    vector <int> boundary(Node *root)
    {
       vector<int> res; // for storing ans
       
       if(root == NULL) return res;
       if(!isLeaf(root)) res.push_back(root->data); // if root is not a leaf not put in ans
       addLeftBoundary(root,res); // for adding left side node into ans
       addLeafsNode(root,res); // for adding leaf node into ans
       addRightBoundary(root,res); // for adding right side node into ans
       
       return res;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends