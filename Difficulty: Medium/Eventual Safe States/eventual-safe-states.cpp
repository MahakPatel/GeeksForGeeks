//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  //++++++++++++++++++++++ TC O( V + E).  SC (2V + VlogV)+++++++++++++++
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V]; // Adjacency list for the reversed graph
        int indegree[V] = {0}; // Array to store the indegrees of nodes
        
        // Build the reversed graph and calculate indegrees
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjRev[it].push_back(i); // Reverse the edge
                indegree[i]++; // Increment the indegree of the original node
            }
        }
        
        queue<int> q; // Queue to process nodes with indegree 0
        vector<int> safeNode; // Vector to store safe nodes

        // Push all nodes with indegree 0 into the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process the queue
        while (!q.empty()) {
            int node = q.front(); // Get the front node
            q.pop(); // Remove the front node

            safeNode.push_back(node); // Add the node to the list of safe nodes

            // Decrease the indegree of adjacent nodes in the reversed graph
            for (auto it : adjRev[node]) {
                indegree[it]--; // Decrease the indegree by 1

                // If indegree becomes 0, push it into the queue
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Sort the list of safe nodes before returning
        sort(safeNode.begin(), safeNode.end());

        return safeNode; // Return the list of safe nodes
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends