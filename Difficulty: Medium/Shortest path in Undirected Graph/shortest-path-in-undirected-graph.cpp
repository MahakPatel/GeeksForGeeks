//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
//++++++++++++++++++++ BFS TC O(N + M).   SC O(N)+++++++++++++++
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        // Create an adjacency list for the graph
        vector<int> adj[N];

        // Build the graph from the edges
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]); // Add edge from it[0] to it[1]
            adj[it[1]].push_back(it[0]); // Add edge from it[1] to it[0] (undirected graph)
        }

        // Initialize the distance array with a large number
        vector<int> dist(N, 1e9);
        dist[src] = 0; // Distance to the source is 0

        // Queue for BFS
        queue<int> q;
        q.push(src); // Start BFS from the source

        // Perform BFS to find shortest paths
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Explore all adjacent nodes
            for (auto it : adj[node]) {
                // If a shorter path to the adjacent node is found
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1; // Update the distance
                    q.push(it); // Add the adjacent node to the queue
                }
            }
        }

        // Prepare the answer vector
        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++) {
            if (dist[i] != 1e9) {
                ans[i] = dist[i]; // Set the distance if reachable
            }
        }

        return ans; // Return the distances
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends