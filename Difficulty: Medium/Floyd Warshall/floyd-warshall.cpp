//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  // ++++++++++++++. TC O(N^3).    SC O(N^2) ++++++++++++++++++
    void shortestDistance(vector<vector<int>>& mat) {
        // Get the number of nodes (size of the matrix).
        int n = mat.size();
        
        // Initialize the matrix, replacing -1 with a large value (1e9) to represent no path.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Replace -1 with a large number to indicate no path between i and j.
                if (mat[i][j] == -1) {
                    mat[i][j] = 1e9; // 1e9 is used to represent infinity (no path).
                }
        
                // Set the diagonal elements (i == j) to 0, as the distance from a node to itself is 0.
                if (i == j) {
                    mat[i][j] = 0;
                }
            }
        }
        
        // Floyd-Warshall algorithm to compute shortest paths between all pairs of nodes.
        for (int k = 0; k < n; k++) {  // Loop through all intermediate nodes.
            for (int i = 0; i < n; i++) {  // Loop through the start nodes.
                for (int j = 0; j < n; j++) {  // Loop through the end nodes.
                    // Update the shortest path from i to j considering node k as an intermediate.
                    mat[i][j] = min(mat[i][j], (mat[i][k] + mat[k][j]));
                }
            }
        }
        
        // After applying the Floyd-Warshall algorithm, revert the large values (1e9) back to -1.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1e9) {
                    mat[i][j] = -1;  // Convert the large values back to -1 to represent no path.
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends