//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // ++++++++++++ Recursive ++++++++++ TC O(2^N).   SC O(n)
    // // Recursive function to solve the Unbounded Knapsack problem
    // int f(vector<int>& val, vector<int>& wt, int capacity, int index) {
    //     // Base Case: If we're at index 0, take as many of wt[0] as possible
    //     if (index == 0) {
    //         return (capacity / wt[0]) * val[0];  
    //     }
    
    //     // Option 1: Exclude the current item and move to the previous item
    //     int notTake = f(val, wt, capacity, index - 1);
        
    //     // Option 2: Include the current item (if its weight does not exceed the remaining capacity)
    //     int take = INT_MIN;
    //     if (wt[index] <= capacity) {
    //         take = val[index] + f(val, wt, capacity - wt[index], index); // Stay on the same index (unbounded choice)
    //     }
    
    //     // Return the maximum of the two choices
    //     return max(take, notTake);
    // }
    
    // // Function to solve the Knapsack problem
    // int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    //     int n = wt.size(); // Number of items
    //     return f(val, wt, capacity, n - 1); // Start from the last index
    // }
    
    
    // ++++++++++++ memoization ++++++++++ TC O(n * capacity).   SC O(n * capacity + capacity + capacity) 
     // Recursive function to solve the Unbounded Knapsack problem
    // int f(vector<int>& val, vector<int>& wt, int capacity, int index, vector<vector<int>>& dp) {
    //     // Base Case: If we're at index 0, take as many of wt[0] as possible
    //     if (index == 0) {
    //         return (capacity / wt[0]) * val[0];  
    //     }
    
    //     // Return precomputed result if available
    //     if (dp[index][capacity] != -1) return dp[index][capacity];
    
    //     // Option 1: Exclude the current item and move to the previous item
    //     int notTake = f(val, wt, capacity, index - 1, dp);
    
    //     // Option 2: Include the current item (if its weight does not exceed the remaining capacity)
    //     int take = INT_MIN;
    //     if (wt[index] <= capacity) {
    //         take = val[index] + f(val, wt, capacity - wt[index], index, dp); // Stay on the same index (unbounded choice)
    //     }
    
    //     // Store the result in DP table and return
    //     return dp[index][capacity] = max(take, notTake);
    // }
    
    // // Function to solve the Knapsack problem
    // int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    //     int n = wt.size(); // Number of items
    //     vector<vector<int>> dp(n, vector<int>(capacity + 1, -1)); // DP table initialized with -1
    
    //     return f(val, wt, capacity, n - 1, dp); // Start from the last index
    // }
    
    
    //     // +++++++++++++++ Tabulation ++++++++++ TC O(n * capacity).   SC O(n * capacity) 
    //     int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    //     int n = wt.size(); // Number of items
    //     vector<vector<int>> dp(n, vector<int>(capacity + 1, 0)); // DP table initialized with 0
    
    //     // Base Case: If we're at index 0, take as many of wt[0] as possible
    //     for (int c = 0; c <= capacity; c++) {  
    //         dp[0][c] = (c / wt[0]) * val[0];  
    //     }
    
    //     // Fill DP table for all items
    //     for (int ind = 1; ind < n; ind++) {
    //         for (int c = 0; c <= capacity; c++) {
    //             // Option 1: Exclude the current item
    //             int notTake = dp[ind - 1][c];
    
    //             // Option 2: Include the current item (if weight allows)
    //             int take = 0;
    //             if (wt[ind] <= c) {
    //                 take = val[ind] + dp[ind][c - wt[ind]]; // Stay at the same index for unbounded choice
    //             }
    
    //             // Store the max of both choices
    //             dp[ind][c] = max(take, notTake);
    //         }
    //     }
    
    //     return dp[n - 1][capacity]; // Maximum value we can obtain
    // }
    
    //     // +++++++++++++++ Space Optimization(2D Array) ++++++++++ TC O(n * capacity).   SC O(capacity ) 
    //     int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    //     int n = wt.size(); // Number of items
    //     vector<int> prev(capacity + 1, 0), cur(capacity + 1, 0); // Two DP arrays for space optimization
    
    //     // Base Case: Fill the first row considering taking multiple instances of the first item
    //     for (int c = 0; c <= capacity; c++) {  
    //         prev[c] = (c / wt[0]) * val[0];  
    //     }
    
    //     // Process each item one by one
    //     for (int ind = 1; ind < n; ind++) {
    //         for (int c = 0; c <= capacity; c++) {
    //             // Option 1: Exclude the current item
    //             int notTake = prev[c];
    
    //             // Option 2: Include the current item (if weight allows)
    //             int take = 0;
    //             if (wt[ind] <= c) {
    //                 take = val[ind] + cur[c - wt[ind]]; // Use previous computed value for unbounded choice
    //             }
    
    //             // Store the maximum of both choices
    //             cur[c] = max(take, notTake);
    //         }
    
    //         // Update prev array for the next iteration
    //         prev = cur;
    //     }
    
    //     // Return the maximum value possible with the given capacity
    //     return prev[capacity];
    // }
    
    // +++++++++++++++ Space Optimization(1D Array) ++++++++++ TC O(n * capacity).   SC O(capacity ) 
        int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size(); // Number of items
        vector<int> prev(capacity + 1, 0); // DP arrays for space optimization
    
        // Base Case: Fill the first row considering taking multiple instances of the first item
        for (int c = 0; c <= capacity; c++) {  
            prev[c] = (c / wt[0]) * val[0];  
        }
    
        // Process each item one by one
        for (int ind = 1; ind < n; ind++) {
            for (int c = 0; c <= capacity; c++) {
                // Option 1: Exclude the current item
                int notTake = prev[c];
    
                // Option 2: Include the current item (if weight allows)
                int take = 0;
                if (wt[ind] <= c) {
                    take = val[ind] + prev[c - wt[ind]]; // Use previous computed value for unbounded choice
                }
    
                // Store the maximum of both choices
                prev[c] = max(take, notTake);
            }

        }
    
        // Return the maximum value possible with the given capacity
        return prev[capacity];
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends