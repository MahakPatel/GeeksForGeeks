//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  private :
  // ++++++++++++++++ TC O(V + E)    SC O(V)++++++++++++++++++++
   vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0); // Initialize indegree array to 0 for all vertices

        // Calculate indegrees of all vertices
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++; // Increment the indegree of the adjacent nodes
            }
        }

        queue<int> q; // Queue to process nodes with indegree 0
        // Push all vertices with indegree 0 into the queue
        for (int i = 0; i < V; i++) {
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

        return topo; // Return the topological order
    }

  public:
    // Function to find the order of characters in the alien language
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k]; // Adjacency list for the graph
        
        // Build the adjacency list based on the dictionary
        for (int i = 0; i < n - 1; i++) {
            string s1 = dict[i]; // Current word
            string s2 = dict[i + 1]; // Next word
            
            int len = min(s1.length(), s2.length()); // Find the minimum length of the two words
            
            // Compare characters until they differ
            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); // Add the directed edge
                    break; // Break after the first different character
                }
            }
        }
        
        // Get the topological order of characters
        vector<int> topo = topoSort(k, adj);
        string ans = ""; // Initialize the result string
        
        // Construct the result string from the topological order
        for (auto it : topo) {
            ans += char(it + 'a'); // Convert back to characters and append
        }
        
        return ans; // Return the order of characters
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends