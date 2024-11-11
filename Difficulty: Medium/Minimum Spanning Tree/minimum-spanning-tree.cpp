//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	// ++++++++++++++++++++ Prim's Algoritham +++++++++++++++++++++++++
	// ++++++++++++ TC O(E log V).    sc O(V + E) ++++++++++++++
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Visited array to track which nodes have been added to the MST
        vector<int> vis(V, 0); 
        pq.push({0, 0});  // Push the starting node (node 0) with a weight of 0
        int sum = 0;  // To store the total weight of the MST
        
        while (!pq.empty()) {
            auto it = pq.top();  // Get the node with the minimum weight edge
            pq.pop();
        
            int wt = it.first;  // Edge weight of the current node
            int node = it.second;  // The current node being processed
        
            // If this node is already visited, skip it
            if (vis[node] == 1) continue;
        
            // Mark the node as visited and add its edge weight to the sum
            vis[node] = 1;
            sum += wt;
        
            // Iterate through all the neighbors of the current node
            for (auto it : adj[node]) {
                int adjNode = it[0];  // The adjacent node
                int ewt = it[1];  // The edge weight to the adjacent node
                
                // If the adjacent node hasn't been visited, push it to the priority queue
                if (!vis[adjNode]) {
                    pq.push({ewt, adjNode});
                }
            }
        }
        
        return sum;  // Return the total weight of the Minimum Spanning Tree
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends