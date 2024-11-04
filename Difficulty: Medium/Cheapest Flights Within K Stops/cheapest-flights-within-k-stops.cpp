//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  //++++++++++++++++++ TC O(E).     SC O( E+ V)+++++++++++++++++
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Create an adjacency list to represent the graph
        vector<pair<int,int>> adj[n];
        
        // Populate the adjacency list with flights data
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]}); // {destination, cost}
        }
        
        // Queue for BFS: {stops, {node, cost}}
        queue<pair<int,pair<int,int>>> q;
        q.push({0, {src, 0}}); // Start from the source with 0 cost and 0 stops
        
        // Distance array to track minimum cost to reach each node
        vector<int> dist(n, 1e9);
        dist[src] = 0; // Cost to reach the source is 0
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int stops = it.first; // Number of stops taken to reach the current node
            int node = it.second.first; // Current node
            int cost = it.second.second; // Current cost to reach the node
            
            // If the number of stops exceeds K, skip further processing
            if(stops > K) continue;
            
            // Explore all adjacent nodes
            for(auto iter : adj[node]) {
                int adjNode = iter.first; // Adjacent node
                int ewt = iter.second; // Edge weight (cost)
                
                // If the new cost is cheaper, update the distance
                if(ewt + cost < dist[adjNode] && stops <= K) {
                    dist[adjNode] = ewt + cost; // Update minimum cost
                    // Push the adjacent node into the queue with updated stops and cost
                    q.push({stops + 1, {adjNode, ewt + cost}});
                }
            }
        }
        
        // If the destination cost remains max, return -1 (unreachable)
        if(dist[dst] == 1e9) return -1;
        
        return dist[dst]; // Return the minimum cost to reach the destination
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends