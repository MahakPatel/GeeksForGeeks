//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

// +++++++++++++++++ TC O(V+E).    SC O(V)
bool isPossible(int v, int P, vector<pair<int, int>>& prerequisites) {
    vector<int> adj[v]; // Adjacency list representation of the graph

    // Build the adjacency list
    for (auto it : prerequisites) {
        adj[it.second].push_back(it.first); // it.second must come before it.first
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

    // If the size of the topological order is equal to the number of vertices, return true
    return topo.size() == v;
}

	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends