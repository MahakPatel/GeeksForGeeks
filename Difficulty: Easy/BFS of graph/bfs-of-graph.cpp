//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of the given graph
    // TC O(N + 2E).       SC O(3N)
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Create a visited array to keep track of visited nodes
    int vis[V] = {0}; // Initialize all nodes as unvisited (0)
    vis[0] = 1;       // Mark the starting node (0) as visited

    // Vector to store the BFS traversal order
    vector<int> bfs;

    // Queue for BFS traversal
    queue<int> q;

    // Start BFS from node 0
    q.push(0);

    // Continue until the queue is empty
    while(!q.empty()) {
        // Get the front node from the queue
        int node = q.front();
        q.pop();

        // Add the current node to the BFS traversal list
        bfs.push_back(node);

        // Explore all the adjacent nodes of the current node
        for(auto it : adj[node]) {
            // If the adjacent node is not visited
            if(!vis[it]) {
                // Mark it as visited
                vis[it] = 1;
                // Add it to the queue for further exploration
                q.push(it);
            }
        }
    }

    // Return the BFS traversal order
    return bfs;
}

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends