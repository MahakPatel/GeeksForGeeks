//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  // +++++++++++++++++ Recursive +++++++++ TC O(3^N).   SC O(N)
//   int f(int i, int j1, int j2, vector<vector<int>> &grid) {
//     int n = grid.size();
//     int m = grid[0].size();

//     // If out of bounds, return a very small value
//     if (i < 0 || i >= n || j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
//         return -1e9;

//     // Base case: If we are at the last row, calculate the sum
//     if (i == n - 1) {
//         if (j1 == j2) {
//             return grid[i][j1];  // If both are on the same column, just return the value at that column
//         } else {
//             return grid[i][j1] + grid[i][j2];  // If they are on different columns, return the sum of both
//         }
//     }

//     int maxi = INT_MIN;  // Initialize maxi to keep track of the maximum sum

//     // Try moving in all possible directions for both agents
//     for (int dj1 = -1; dj1 <= 1; dj1++) {  // For the first agent
//         for (int dj2 = -1; dj2 <= 1; dj2++) {  // For the second agent
//             // Ensure that the new positions are valid
//             if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m) {
//                 if (j1 == j2) {  // If both agents are on the same column
//                     maxi = max(maxi, grid[i][j1] + f(i + 1, j1 + dj1, j2 + dj2, grid));
//                 } else {  // If agents are on different columns
//                     maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(i + 1, j1 + dj1, j2 + dj2, grid));
//                 }
//             }
//         }
//     }

//     return maxi;  // Return the maximum sum
// }

// int solve(int n, int m, vector<vector<int>>& grid) {
//     return f(0, 0, m - 1, grid);  // Start from the first row with the first and last column for the agents
// }



  // +++++++++++++++++ Memoization +++++++++ TC O(n*m*m*9).   SC O(n*m*m)

// int f(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
//     int n = grid.size();
//     int m = grid[0].size();

//     // If out of bounds, return a very small value
//     if (i < 0 || i >= n || j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
//         return -1e9;

//     // If this state has already been computed, return the value from dp
//     if (dp[i][j1][j2] != -1) 
//         return dp[i][j1][j2];

//     // Base case: If we are at the last row, calculate the sum
//     if (i == n - 1) {
//         if (j1 == j2) {
//             return grid[i][j1];  // If both agents are on the same column, just return the value at that column
//         } else {
//             return grid[i][j1] + grid[i][j2];  // If they are on different columns, return the sum of both
//         }
//     }

//     int maxi = INT_MIN;  // Initialize maxi to keep track of the maximum sum

//     // Try moving in all possible directions for both agents
//     for (int dj1 = -1; dj1 <= 1; dj1++) {  // For the first agent
//         for (int dj2 = -1; dj2 <= 1; dj2++) {  // For the second agent
//             // Ensure that the new positions are valid
//             if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m) {
//                 if (j1 == j2) {  // If both agents are on the same column
//                     maxi = max(maxi, grid[i][j1] + f(i + 1, j1 + dj1, j2 + dj2, grid, dp));
//                 } else {  // If agents are on different columns
//                     maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(i + 1, j1 + dj1, j2 + dj2, grid, dp));
//                 }
//             }
//         }
//     }

//     // Store the computed result in dp
//     dp[i][j1][j2] = maxi;

//     return maxi;  // Return the maximum sum
// }

// int solve(int n, int m, vector<vector<int>>& grid) {
//     // Initialize dp with -1 for uncomputed states
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    
//     // Start from the first row with the first and last column for the agents
//     return f(0, 0, m - 1, grid, dp);  
// }

// // +++++++++++++++++++++ Tabulation ++++++++ TC O(n*m*m)*9.   SC O(n*m*m)
// int solve(int n, int m, vector<vector<int>>& grid) {
//     // Initialize dp with -1 for uncomputed states (set to 0 for simplicity in initialization)
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

//     // Base case for the last row: calculate the sum for both agents
//     for (int j1 = 0; j1 < m; j1++) {
//         for (int j2 = 0; j2 < m; j2++) {
//             // If both agents are in the same column, only one value is added
//             if (j1 == j2) 
//                 dp[n - 1][j1][j2] = grid[n - 1][j1];
//             else 
//                 dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
//         }
//     }

//     // Fill the dp table for all rows, starting from the second last row to the top
//     for (int i = n - 2; i >= 0; i--) {
//         for (int j1 = 0; j1 < m; j1++) {
//             for (int j2 = 0; j2 < m; j2++) {
//                 int maxi = INT_MIN;

//                 // Try moving in all possible directions for both agents (up, left diagonal, right diagonal)
//                 for (int dj1 = -1; dj1 <= 1; dj1++) {  // For the first agent
//                     for (int dj2 = -1; dj2 <= 1; dj2++) {  // For the second agent
//                         // Compute the value if agents are in the same column or different columns
//                         int value = 0;
//                         if (j1 == j2) {
//                             value = grid[i][j2];  // If both agents are in the same column
//                         } else {
//                             value = grid[i][j1] + grid[i][j2];  // If agents are in different columns
//                         }

//                         // Check if the new positions are within bounds
//                         if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m) {
//                             value += dp[i + 1][j1 + dj1][j2 + dj2];  // Add the result from the next row
//                         }

//                         // Update the maximum value found
//                         maxi = max(maxi, value);
//                     }
//                 }

//                 dp[i][j1][j2] = maxi;  // Store the result in dp
//             }
//         }
//     }

//     // The result is the maximum value starting from the first row (0) and from the first and last columns for the agents
//     return dp[0][0][m - 1];
// }

 //+++++++++++++++++ Space Optimization ++++++++ TC O(n*m*m*9).   sc O(n*m) +++++++
int solve(int n, int m, vector<vector<int>>& grid) {
    
    int prev[m][m];
    int cur[m][m];
   
    // Base case for the last row: calculate the sum for both agents
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            // If both agents are in the same column, only one value is added
            if (j1 == j2) 
                prev[j1][j2] = grid[n - 1][j1];  // Same column, add grid value of that column
            else 
                prev[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];  // Different columns, sum both grid values
        }
    }

    // Iterate through all rows starting from the second-last row
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = INT_MIN;  // Initialize the maximum value for the current cell

                // Try moving both agents in all 3 possible directions (up, left diagonal, right diagonal)
                for (int dj1 = -1; dj1 <= 1; dj1++) {  // For the first agent
                    for (int dj2 = -1; dj2 <= 1; dj2++) {  // For the second agent
                        // Compute the value if agents are in the same column or different columns
                        int value = 0;
                        if (j1 == j2) {
                            value = grid[i][j2];  // If both agents are in the same column
                        } else {
                            value = grid[i][j1] + grid[i][j2];  // If agents are in different columns
                        }

                        // Check if the new positions are within bounds
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m) {
                            value += prev[j1 + dj1][j2 + dj2];  // Add the result from the previous row
                        }

                        // Update the maximum value found
                        maxi = max(maxi, value);
                    }
                }

                // Store the maximum value for the current state in 'cur'
                cur[j1][j2] = maxi;
            }
        }

        // Copy the values from 'cur' to 'prev' for the next row
        memcpy(prev, cur, sizeof(prev));
    }

    // The result is the maximum value starting from the first row (0) and from the first and last columns for the agents
    return prev[0][m - 1];
}



};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends