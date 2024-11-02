//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
    
    // +++++++++++++++++++ TC O(V + E) +++++++++++++ SC O(2V) ++++++++++=
    // Helper function to perform DFS and detect cycles
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathVis) {
        vis[node] = true; // Mark the current node as visited
        pathVis[node] = true; // Mark the current node in the current path

        // Explore all adjacent nodes
        for (auto it : adj[node]) {
            if (!vis[it]) { // If the adjacent node has not been visited
                // Recursively check for cycles
                if (dfsCheck(it, adj, vis, pathVis)) return true;
            } 
            // If the adjacent node is in the current path, a cycle is detected
            else if (pathVis[it]) return true;
        }

        pathVis[node] = false; // Backtrack: unmark the current node from the current path
        return false; // No cycle found from this node
    }

public:
    // Function to detect cycle in a directed graph
    bool isCyclic(int V, vector<vector<int>> &adj) {
        vector<bool> vis(V, false); // Visited array to track visited nodes
        vector<bool> pathVis(V, false); // Path visited array to track nodes in the current path
        
        // Check each node for cycles
        for (int i = 0; i < V; i++) {
            if (!vis[i]) { // Only start DFS if the node has not been visited
                if (dfsCheck(i, adj, vis, pathVis)) return true; // Cycle detected
            }
        }
        
        return false; // No cycle detected in the graph
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends