//{ Driver Code Starts
#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
     // ++++++++++++ TC (V * E).    SC (V + E) +++++++++++=
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
       // Initialize distance array with a very large value (1e8).
        vector<int> dist(V, 1e8);  
        dist[src] = 0;  // Distance to the source is 0.
        
        // Relax all edges V-1 times.
        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                int u = it[0];  // Starting node of the edge.
                int v = it[1];  // Ending node of the edge.
                int wt = it[2];  // Weight of the edge.
                
                // If there is a shorter path from u to v through the edge (u, v),
                // update the distance of v.
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Check for negative weight cycles by relaxing edges one more time.
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            // If a shorter path is found, then there is a negative weight cycle.
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};  // Return -1 if a negative weight cycle is detected.
            }
        }
        
        
        // Return the distances from the source to all other vertices.
        return dist;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends