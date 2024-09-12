//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   private:
    // Recursive DFS function
    void dfs(int node, int vis[], vector<int> adj[], vector<int> &ls) {
        // Mark the current node as visited
        vis[node] = 1;
        // Add the current node to the list
        ls.push_back(node);
        
        // Traverse all the adjacent nodes
        for (auto it : adj[node]) {
            // If the adjacent node hasn't been visited, perform DFS on it
            if (!vis[it]) {
                dfs(it, vis, adj, ls);
            }
        }
    }
  
public:

    // ++++++++++++++++++ TC O(N + 2E)    SC O(3N) 
    // Function to return a list containing the DFS traversal of the graph
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Initialize the visited array to keep track of visited nodes
        int vis[V] = {0};
        // Starting node for DFS (usually 0 for the 0-based index graph)
        int start = 0;
        
        // Vector to store the DFS traversal
        vector<int> ls;
        
        // Perform DFS starting from the 'start' node
        dfs(start, vis, adj, ls);
        
        // Return the DFS traversal list
        return ls;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends