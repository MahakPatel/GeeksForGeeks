//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

// TC O(m^v)
// Function to check if it's safe to color a node
bool isSafe(int node, int color[], vector<vector<int>>& adj, int col) {
    for (int neighbor : adj[node]) {
        if (color[neighbor] == col) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve M-Coloring problem
bool solve(int node, int color[], vector<vector<int>>& adj, int v, int m) {
    if (node == v) {
        return true;  // All nodes colored successfully
    }

    for (int i = 1; i <= m; i++) {
        if (isSafe(node, color, adj, i)) {
            color[node] = i;  // Assign color

            if (solve(node + 1, color, adj, v, m)) {
                return true;  // If successful, return immediately
            }

            color[node] = 0;  // Backtrack
        }
    }

    return false;
}

// Main function to check if the graph can be colored with `m` colors
bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
    vector<vector<int>> adj(v); // Adjacency list

    // Convert edge list to adjacency list
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    int color[v] = {0}; // Initialize color array with 0

    // Start coloring from node 0
    return solve(0, color, adj, v, m);
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends