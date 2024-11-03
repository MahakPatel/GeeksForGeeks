//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
   private:
   //+++++++++++++++++ TC O(V + E).   SC O(V) ++++++++++++++++
    // Function to perform DFS and generate a topological sort
    void topoSort(int node, int vis[], stack<int> &st, vector<pair<int, int>> adj[]) {
        vis[node] = 1; // Mark the current node as visited
        
        // Explore all adjacent nodes
        for (auto it : adj[node]) {
            int v = it.first; // Get the adjacent node
            if (!vis[v]) {
                topoSort(v, vis, st, adj); // Recursively call topoSort for unvisited nodes
            }
        }
        
        st.push(node); // Push the current node onto the stack after exploring all its neighbors
    }

public:
    // Function to find the shortest path from source to all vertices in a directed graph
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Create an adjacency list
        vector<pair<int, int>> adj[V];

        // Build the adjacency list from the edges
        for (int i = 0; i < E; i++) {
            int u = edges[i][0]; // Source node
            int v = edges[i][1]; // Destination node
            int wt = edges[i][2]; // Weight of the edge
            
            adj[u].push_back({v, wt}); // Add the edge to the adjacency list
        }
        
        int vis[V] = {0}; // Array to track visited nodes
        stack<int> st; // Stack to hold the topological sort order
        
        // Perform topological sorting
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSort(i, vis, st, adj); // Perform DFS for unvisited nodes
            }
        }
        
        vector<int> dist(V, 1e9); // Distance array initialized to "infinity"
        dist[0] = 0; // Distance to the source node is 0
        
        // Process nodes in topological order
        while (!st.empty()) {
            int node = st.top(); // Get the top node
            st.pop(); // Remove it from the stack
            
            // Relax edges for the current node
            for (auto it : adj[node]) {
                int v = it.first; // Adjacent node
                int wt = it.second; // Weight of the edge
                
                // If a shorter path to the adjacent node is found
                if (dist[node] != 1e9 && dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt; // Update the shortest distance
                }
            }
        }
        
        // Replace distances that remain "infinity" with -1 for unreachable nodes
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1; // Mark as unreachable
            }
        }

        return dist; // Return the array of shortest distances
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends