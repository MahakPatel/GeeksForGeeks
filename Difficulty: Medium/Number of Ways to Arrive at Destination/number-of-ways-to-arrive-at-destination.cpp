//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  // +++++++++++++++++ TC O( (N+ E)logN).  SC O(N)+++++++++++++++++
int mod = 1e9 + 7; // Modulo value for large number handling

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n); // Correct declaration for adjacency list
        
        // Constructing the adjacency list
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]}); // {destination, weight}
            adj[it[1]].push_back({it[0], it[2]}); // Bidirectional road
        }

        vector<long long> dist(n, 1e18); // Initialize distances to "infinity"
        vector<int> ways(n, 0); // Number of ways to reach each node
        dist[0] = 0; // Distance to the source is 0
        ways[0] = 1; // One way to start at the source

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // Min-heap priority queue
        pq.push({0, 0}); // Push the source node into the queue

        while (!pq.empty()) {
            int node = pq.top().second; // Current node
            long long dis = pq.top().first; // Current distance
            pq.pop(); // Remove the top element

            // Traverse adjacent nodes
            for (auto it : adj[node]) {
                int adjNode = it.first; // Adjacent node
                long long ewt = it.second; // Edge weight
                
                // If a shorter path to adjNode is found
                if (dis + ewt < dist[adjNode]) {
                    dist[adjNode] = dis + ewt; // Update distance
                    ways[adjNode] = ways[node]; // Update ways to reach this node
                    pq.push({dist[adjNode], adjNode}); // Push the updated node
                }
                // If the same distance is found again
                else if (dis + ewt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod; // Update the number of ways
                }
            }
        }

        return ways[n - 1] % mod; // Return the number of ways to reach the destination
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends