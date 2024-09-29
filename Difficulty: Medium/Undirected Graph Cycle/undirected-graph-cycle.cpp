//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
     // Helper function to detect cycles using BFS
    bool detectCycle(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1; // Mark the source node as visited
        queue<pair<int, int>> q; // Queue to hold nodes and their parents
        q.push({src, -1}); // Push the source node with parent as -1

        // BFS traversal
        while (!q.empty()) {
            int node = q.front().first; // Current node
            int parent = q.front().second; // Parent of the current node
            q.pop(); // Remove the current node from the queue

            // Explore all adjacent nodes
            for (auto adjNode : adj[node]) {
                // If the adjacent node hasn't been visited
                if (!vis[adjNode]) {
                    vis[adjNode] = 1; // Mark as visited
                    q.push({adjNode, node}); // Push the adjacent node with current node as parent
                } else if (parent != adjNode) {
                    // If the adjacent node is visited and is not the parent of the current node
                    return true; // A cycle is detected
                }
            }
        }

        return false; // No cycle found from the current source node
    }

public:
    // ++++++++++++ TC O(n + 2E)   SC O(n) ++++++++++++
    // Function to detect cycle in an undirected graph
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0}; // Initialize visited array to track visited nodes

        // Check for cycles in each component of the graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) { // If the node is not visited
                // If a cycle is detected, return true
                if (detectCycle(i, adj, vis)) return true;
            }
        }

        return false; // No cycle found in the graph
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends