//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // // ++++++++++++++ Recursive ++++++++++ TC O(2^n).   SC O(N)
    // int f(vector<int> &price, int index, int n) {
    //     // Base Case: If we are at the first index, we can only take full pieces of length 1
    //     if (index == 0) {
    //         return n * price[0];  // Take as many pieces of length 1 as possible
    //     }
    
    //     // Option 1: Exclude the current length and move to the previous index
    //     int notTake = f(price, index - 1, n);
    
    //     // Option 2: Include the current rod length (if possible)
    //     int take = INT_MIN;
    //     int rodLength = index + 1; // Length of the current rod piece
    //     if (rodLength <= n) {
    //         take = price[index] + f(price, index, n - rodLength); // Stay at the same index (unbounded choice)
    //     }
    
    //     // Return the maximum profit between taking or not taking the current rod length
    //     return max(take, notTake);
    // }
    
    // // Function to solve the Rod Cutting problem
    // int cutRod(vector<int> &price) {
    //     int n = price.size(); // Length of the rod
    //     return f(price, n - 1, n); // Start from the last index
    // }
    
    
        // ++++++++++++++ Memoization ++++++++++ TC O(n*n).   SC O(n*n + N)
    // int f(vector<int> &price, int index, int n,vector<vector<int>> &dp) {
    //     // Base Case: If we are at the first index, we can only take full pieces of length 1
    //     if (index == 0) {
    //         return n * price[0];  // Take as many pieces of length 1 as possible
    //     }
        
    //     if(dp[index][n] != -1) return dp[index][n];
    
    //     // Option 1: Exclude the current length and move to the previous index
    //     int notTake = f(price, index - 1, n,dp);
    
    //     // Option 2: Include the current rod length (if possible)
    //     int take = INT_MIN;
    //     int rodLength = index + 1; // Length of the current rod piece
    //     if (rodLength <= n) {
    //         take = price[index] + f(price, index, n - rodLength,dp); // Stay at the same index (unbounded choice)
    //     }
    
    //     // Return the maximum profit between taking or not taking the current rod length
    //     return dp[index][n] = max(take, notTake);
    // }
    
    // // Function to solve the Rod Cutting problem
    // int cutRod(vector<int> &price) {
    //     int n = price.size(); // Length of the rod
        
    //     vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //     return f(price, n - 1, n,dp); // Start from the last index
    // }
    
    // +++++++++++++++ Tabulation +++++++++++ TC O( n* n ) SC O(n * n)
    
    //  // Function to solve the Rod Cutting problem
    //     int cutRod(vector<int> &price) {
    //     int n = price.size(); // Length of the rod
        
    //     // DP table where dp[i][j] represents the maximum price obtained
    //     // using the first (i+1) rod lengths to form a rod of length j
    //     vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    
    //     // Base Case: If we are using only the first rod length (1 unit), 
    //     // we can take as many of them as needed
    //     for (int N = 0; N <= n; N++) {
    //         dp[0][N] = N * price[0]; // Taking N pieces of length 1
    //     }
    
    //     // Iterate over rod lengths
    //     for (int ind = 1; ind < n; ind++) {
    //         for (int N = 0; N <= n; N++) {
    //             // Option 1: Exclude the current rod length
    //             int notTake = dp[ind - 1][N];
    
    //             // Option 2: Include the current rod length (if possible)
    //             int take = INT_MIN;
    //             int rodLength = ind + 1; // Length of the current rod piece
    //             if (rodLength <= N) {
    //                 take = price[ind] + dp[ind][N - rodLength]; // Unbounded choice (reuse same length)
    //             }
    
    //             // Store the maximum profit for the current length
    //             dp[ind][N] = max(take, notTake);
    //         }
    //     }
    
    //     return dp[n - 1][n]; // Maximum obtainable price
    // }
    
    // ++++++++++++ Space Optimization +++++++++ TC O(n * n).  SC O(n)
     // Function to solve the Rod Cutting problem
        int cutRod(vector<int> &price) {
        int n = price.size(); // Length of the rod
        
        vector<int> prev(n+1,0), cur(n+1,0);
    
        // Base Case: If we are using only the first rod length (1 unit), 
        // we can take as many of them as needed
        for (int N = 0; N <= n; N++) {
            prev[N] = N * price[0]; // Taking N pieces of length 1
        }
    
        // Iterate over rod lengths
        for (int ind = 1; ind < n; ind++) {
            for (int N = 0; N <= n; N++) {
                // Option 1: Exclude the current rod length
                int notTake = prev[N];
    
                // Option 2: Include the current rod length (if possible)
                int take = INT_MIN;
                int rodLength = ind + 1; // Length of the current rod piece
                if (rodLength <= N) {
                    take = price[ind] + cur[N - rodLength]; // Unbounded choice (reuse same length)
                }
    
                // Store the maximum profit for the current length
                cur[N] = max(take, notTake);
            }
            
            prev = cur;
        }
    
        return prev[n]; // Maximum obtainable price
    }


};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends