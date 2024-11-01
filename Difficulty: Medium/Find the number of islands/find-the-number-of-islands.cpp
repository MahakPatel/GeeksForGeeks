//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  
  // +++++++++++++++++++++++ SC O(N^2 + N^2).     TC O(N^2) 
  void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid){
      vis[row][col] = 1; // Mark the current cell as visited

        int n = grid.size(); // Get the number of rows in the grid
        int m = grid[0].size(); // Get the number of columns in the grid
        queue<pair<int, int>> q; // Create a queue for BFS
        
        q.push({row, col}); // Push the starting cell into the queue
        
        // Perform BFS
        while (!q.empty()) {
            int row = q.front().first; // Current row from the front of the queue
            int col = q.front().second; // Current column from the front of the queue
            
            q.pop(); // Remove the current cell from the queue
            
            // Check the four possible directions (up, down, left, right)
            for (int delrow = -1; delrow <= 1; delrow++) {
                for (int delcol = -1; delcol <= 1; delcol++) {
                        int nrow = row + delrow; // New row index
                        int ncol = col + delcol; // New column index
                        
                        // Check if the new cell is within bounds and is part of an island
                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                            vis[nrow][ncol] = 1; // Mark the new cell as visited
                            q.push({nrow, ncol}); // Push the new cell into the queue
                        }
                }
            }
        }
  }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size(); // Get the number of rows in the grid
        int m = grid[0].size(); // Get the number of columns in the grid
        
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Create a visited array initialized to 0
        
        int count = 0; // Counter for islands
        
        // Iterate through each cell in the grid
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                // If we find an unvisited land cell
                if (!vis[row][col] && grid[row][col] == '1') {
                    count++; // Increment the island count
                    bfs(row, col, vis, grid); // Call BFS to mark the whole island
                }
            }
        }
        
        return count; // Return the total number of islands found
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends