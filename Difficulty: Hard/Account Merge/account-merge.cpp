//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//User function Template for C++
class DisjointSet {
    vector<int> rank, parent, size;  // To store the rank, parent and size of the disjoint sets
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);  // Initialize rank array to 0
        parent.resize(n + 1);    // Initialize parent array
        size.resize(n + 1, 1);   // Initialize size array to 1 (each element is its own set initially)
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;   // Each element is its own parent initially
        }
    }

    // Find the ultimate parent of a node with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;  // If the node is its own parent, return it
        return parent[node] = findUPar(parent[node]);  // Path compression: directly set the parent of the node
    }

    // Union by rank (attach smaller rank tree to the larger rank tree)
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);  // Find the ultimate parent of u
        int ulp_v = findUPar(v);  // Find the ultimate parent of v
        
        if (ulp_u == ulp_v) return;  // If both have the same parent, no need to union
        
        // Union by rank: attach the tree with the smaller rank to the tree with larger rank
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;  // If both have the same rank, increment the rank of the root
        }
    }

    // Union by size (attach smaller size tree to the larger size tree)
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);  // Find the ultimate parent of u
        int ulp_v = findUPar(v);  // Find the ultimate parent of v
        
        if (ulp_u == ulp_v) return;  // If both have the same parent, no need to union
        
        // Union by size: attach the tree with the smaller size to the tree with larger size
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];  // Update the size of the root
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];  // Update the size of the root
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();  // Number of accounts
        DisjointSet ds(n);  // Create a DisjointSet to manage the accounts
        
        unordered_map<string, int> mapMailNode;  // Map to store email addresses with their associated account index
        
        // Process each account
        for (int i = 0; i < n; i++) {
            // Iterate through the emails of each account
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                
                // If email doesn't exist in map, add it with the current account index
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } 
                // If email exists, union the accounts
                else {
                    ds.unionByRank(i, mapMailNode[mail]);  // Union current account with the account of the same email
                }
            }
        }
        
        // Create a list of merged emails for each connected component (i.e., each parent in the disjoint set)
        vector<string> mergeMail[n];
        
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);  // Find the ultimate parent of the account
            
            // Add the email to the list of the corresponding parent (account)
            mergeMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        // Iterate through the merged emails list and create the final merged accounts list
        for (int i = 0; i < n; i++) {
            if (mergeMail[i].size() == 0) continue;  // Skip empty lists
            
            sort(mergeMail[i].begin(), mergeMail[i].end());  // Sort emails in alphabetical order
            
            vector<string> temp;
            temp.push_back(accounts[i][0]);  // Add the name of the account as the first element
            
            // Add the sorted emails to the temp account list
            for (auto it : mergeMail[i]) {
                temp.push_back(it);
            }
            
            ans.push_back(temp);  // Add the merged account to the result list
        }
        
        return ans;  // Return the list of merged accounts
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends