//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// User function Template for C++
class DisjointSet {
    vector<int> rank, parent, size;  // Arrays for rank, parent, and size for union-find
public:
    // Constructor to initialize the DisjointSet with n elements
    DisjointSet(int n) {
        rank.resize(n + 1, 0);    // Initialize rank of all elements to 0
        parent.resize(n + 1);     // Initialize parent of each element to itself
        size.resize(n + 1, 1);    // Initialize the size of each set to 1 (each element is its own set)
        for (int i = 0; i <= n; i++) {
            parent[i] = i;  // Each element is its own parent initially
            size[i] = 1;    // Each set has size 1 initially
        }
    }

    // Find the ultimate parent (with path compression)
    int findUPar(int node) {
        if (node == parent[node])  // If node is its own parent, return it
            return node;
        return parent[node] = findUPar(parent[node]);  // Path compression: point directly to the ultimate parent
    }

    // Union by rank (attach the tree with smaller rank to the tree with larger rank)
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);  // Find the ultimate parent of u
        int ulp_v = findUPar(v);  // Find the ultimate parent of v
        if (ulp_u == ulp_v) return;  // If they already have the same parent, no need to union
        
        // Union by rank
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;  // Attach u's tree to v's tree
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;  // Attach v's tree to u's tree
        } else {
            parent[ulp_v] = ulp_u;  // Attach v's tree to u's tree
            rank[ulp_u]++;  // Increment rank of u (the root of the new tree)
        }
    }

    // Union by size (attach the tree with smaller size to the tree with larger size)
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);  // Find the ultimate parent of u
        int ulp_v = findUPar(v);  // Find the ultimate parent of v
        if (ulp_u == ulp_v) return;  // If they already have the same parent, no need to union
        
        // Union by size
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;  // Attach u's tree to v's tree
            size[ulp_v] += size[ulp_u];  // Update size of v's tree
        } else {
            parent[ulp_v] = ulp_u;  // Attach v's tree to u's tree
            size[ulp_u] += size[ulp_v];  // Update size of u's tree
        }
    }
};

class Solution {
  private:
    // Function to check if the new row and column are within bounds
    bool isValid(int newRow, int newCol, int n, int m) {
        return newRow >= 0 && newRow < n && newCol >= 0 && newCol < m; 
    }

  public:
    // +++++++++++++++++++ TC O( Q) Where Q = numsers of operators    SC O(M*N) ++++++
    // Function to return the number of islands after each operation
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);  // Create a disjoint set for all cells (n*m)
        
        int vis[n][m];  // 2D array to keep track of visited cells
        memset(vis, 0, sizeof vis);  // Initialize all cells as unvisited
        
        vector<int> ans;  // To store the number of islands after each operation
        int count = 0;    // Variable to count the number of islands
        
        // Iterate through each operation
        for (auto it : operators) {
            int row = it[0];  // Row of the current operation
            int col = it[1];  // Column of the current operation
            
            // If the cell is already visited, no need to process
            if (vis[row][col] == 1) {
                ans.push_back(count);
                continue;
            }
            
            // Mark the cell as visited
            vis[row][col] = 1;
            count++;  // Increment the island count
            
            // Directions for exploring neighboring cells (up, right, down, left)
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            
            // Check all four neighbors of the current cell
            for (int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                
                // If the new position is within bounds and the neighboring cell is visited
                if (isValid(newRow, newCol, n, m)) {
                    if (vis[newRow][newCol] == 1) {
                        int newNode = row * m + col;  // Unique node ID for the current cell
                        int newAdjNode = newRow * m + newCol;  // Unique node ID for the neighboring cell
                        
                        // If the current cell and the neighboring cell belong to different sets (not connected)
                        if (ds.findUPar(newNode) != ds.findUPar(newAdjNode)) {
                            count--;  // Decrease the island count
                            ds.unionBySize(newNode, newAdjNode);  // Union the two sets
                        }
                    }
                }
            }
            
            // Append the current number of islands to the result
            ans.push_back(count);
        }
        
        return ans;  // Return the result containing the number of islands after each operation
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends