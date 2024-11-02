//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  // +++++++++++++++++ TC O(V+E).    SC O(V) ++++++++++++++++++++++
    vector<int> findOrder(int v, int m, vector<vector<int>> prerequisites) 
    {
         vector<int> adj[v]; // Adjacency list for the graph

        // Build the adjacency list based on prerequisites
        for (auto it : prerequisites) {
            // Since it.first depends on it.second, we add it.second to the adjacency list of it.first
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(v, 0); // Initialize indegree array to 0 for all vertices
        
        // Calculate indegrees of all vertices
        for (int i = 0; i < v; i++) {
            for (auto it : adj[i]) {
                indegree[it]++; // Increment the indegree of adjacent nodes
            }
        }
        
        queue<int> q; // Create a queue to store all vertices with indegree 0
        // Push all vertices with indegree 0 into the queue
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topo; // Vector to store the topological order
        
        // Process the nodes in the queue
        while (!q.empty()) {
            int node = q.front(); // Get the front node
            q.pop(); // Remove the front node
            
            topo.push_back(node); // Add the node to the topological order
            
            // Decrease the indegree of adjacent nodes
            for (auto it : adj[node]) {
                indegree[it]--; // Decrease the indegree by 1
                // If indegree becomes 0, push it into the queue
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        if(topo.size() == v) return topo;// If the size of the topological order is equal to the number of vertices, return sequence
        return {}; // or else return empty array
    
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends