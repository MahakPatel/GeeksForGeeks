//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
public:

//+++++++++++++++++ TC O((V + E)log V).    SC O(V) ++++++++++++++++++
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Create a priority queue to store (distance, node) pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int V = adj.size(); // Number of vertices in the graph
        vector<int> dist(V, INT_MAX); // Initialize distances to infinity
        dist[src] = 0; // Distance to the source is 0
        pq.push({0, src}); // Push the source node into the priority queue

        // Process the priority queue
        while (!pq.empty()) {
            int dis = pq.top().first; // Current shortest distance
            int node = pq.top().second; // Current node
            pq.pop(); // Remove the node from the queue

            // Iterate through all adjacent nodes of the current node
            for (auto it : adj[node]) {
                int adjNode = it.first; // The adjacent node
                int edgeWeight = it.second; // Weight of the edge to the adjacent node
                
                // If the current path to adjNode is shorter, update the distance
                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight; // Update the shortest distance
                    pq.push({dist[adjNode], adjNode}); // Push the updated distance and node into the queue
                }
            }
        }
        
        return dist; // Return the array of shortest distances from the source
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends