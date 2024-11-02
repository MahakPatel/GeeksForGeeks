//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 private:
    //++++++++++++++++++++++++++++++ TC O(V  + E).   SC O(V +V)
    // DFS function to visit nodes and push them onto the stack
    void dfs(int node, int vis[], stack<int> &st, vector<vector<int>> &adj) {
        vis[node] = 1; // Mark the current node as visited
        
        // Visit all the adjacent nodes
        for (auto it : adj[node]) {
            if (!vis[it]) { // If the adjacent node has not been visited
                dfs(it, vis, st, adj); // Recursively visit the adjacent node
            }
        }
        
        st.push(node); // Push the current node to the stack after all its adjacent nodes are processed
    }
    
public:
    // Function to return a list containing vertices in topological order
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int v = adj.size(); // Get the number of vertices in the graph
        int vis[v] = {0}; // Create a visited array initialized to 0 (unvisited)
        stack<int> st; // Stack to store the topological order
        
        // Iterate through all vertices
        for (int i = 0; i < v; i++) {
            if (!vis[i]) { // If the vertex has not been visited
                dfs(i, vis, st, adj); // Call DFS for the vertex
            }
        }
        
        vector<int> ans; // Vector to store the topological order
        
        // Pop all elements from the stack to get the topological order
        while (!st.empty()) {
            ans.push_back(st.top()); // Get the top element
            st.pop(); // Remove the top element from the stack
        }
        
        return ans; // Return the topological order
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends