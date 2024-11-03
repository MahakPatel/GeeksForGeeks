//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  // ++++++++++++++++++ TC O(M * N).  SC O(M * N) ++++++++++++++++
    int shortestPath(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination) {
        // Initialize a queue for BFS, where each entry is a pair (distance, (row, col))
        queue<pair<int, pair<int, int>>> q;
        
         // Edge Case: if the source is only the destination.
        if (source.first == destination.first &&
            source.second == destination.second)
            return 0;

        int n = grid.size(); // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid

        // Initialize the distance array with "infinity"
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        // Set the distance for the source cell to 0
        dist[source.first][source.second] = 0;

        // Push the source cell into the queue with distance 0
        q.push({0, {source.first, source.second}});

        // Directions for moving up, right, down, left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // BFS loop
        while (!q.empty()) {
            auto it = q.front(); // Get the front element of the queue
            q.pop(); // Remove the front element from the queue

            int dis = it.first; // Current distance
            int row = it.second.first; // Current row
            int col = it.second.second; // Current column

            // Explore all four possible directions
            for (int i = 0; i < 4; i++) {
                int newRow = row + delRow[i]; // New row index
                int newCol = col + delCol[i]; // New column index

                // Check if the new position is within bounds and not blocked (i.e., grid value is 1)
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
                    && grid[newRow][newCol] == 1 && dis + 1 < dist[newRow][newCol]) {
                    
                    dist[newRow][newCol] = dis + 1; // Update the distance to the new cell
                    // If we've reached the destination, return the distance
                    if (newRow == destination.first && newCol == destination.second) {
                        return dis + 1;
                    }

                    // Push the new cell into the queue with the updated distance
                    q.push({dis + 1, {newRow, newCol}});
                }
            }
        }

        // If the destination was not reached, return -1
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends