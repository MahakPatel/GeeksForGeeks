//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    // ++++++++++++++++++++++ Recursive ++++++++++++++ TC O(2^N).  SC O(N)
        // int f(int index, vector<int> &arr, int target) {
        //     // Base case 1: If the target becomes 0, we've found a valid subset, return 1
        //     if (target == 0) return 1;
        
        //     // Base case 2: If we reach the first element (index 0), check if it matches the target
        //     if (index == 0) {
        //         return (arr[index] == target);
        //     }
        
        //     // Recursive case: Calculate subsets without including the current element
        //     int notTake = f(index - 1, arr, target);
        
        //     // Recursive case: Calculate subsets including the current element (only if it's <= target)
        //     int take = 0;
        //     if (arr[index] <= target) {
        //         take = f(index - 1, arr, target - arr[index]);
        //     }
        
        //     // Return the total number of subsets (sum of including and not including the current element)
        //     return take + notTake;
        // }
        
        // int perfectSum(vector<int>& arr, int target) {
        //     // n is the size of the array
        //     int n = arr.size();
        
        //     // Start the recursive function from the last index and the target sum
        //     return f(n - 1, arr, target);
        // }
        
        
        // +++++++++++++ Memoization +++++++++++++++++ TC O(n * target).  SC O(n* target + n)  
        // int f(int index, vector<int> &arr, int target, vector<vector<int>> &dp) {
        //     // Base case: If target becomes 0, we found a valid subset
        //     if (target == 0) return 1;
        
        //     // Base case: If at index 0, check if the single element matches the target
        //     if (index == 0) return (arr[index] == target);
        
        //     // If result is already computed, return it to avoid redundant calculations
        //     if (dp[index][target] != -1) return dp[index][target];
        
        //     // Recursive case: Exclude the current element
        //     int notTake = f(index - 1, arr, target, dp);
        
        //     // Recursive case: Include the current element, if it does not exceed the target
        //     int take = 0;
        //     if (arr[index] <= target) {
        //         take = f(index - 1, arr, target - arr[index], dp);
        //     }
        
        //     // Store the result in the dp array and return it
        //     return dp[index][target] = take + notTake;
        // }
        
        // int perfectSum(vector<int>& arr, int target) {
        //     int n = arr.size();
        //     // Create a DP table initialized with -1 for memoization
        //     vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        //     // Call the helper function starting from the last index
        //     return f(n - 1, arr, target, dp);
        // }
        
        // ++++++++++++++ Tabulation +++++++++++ \TC O(n * target).  SC O(n * target)
        
        // int perfectSum(vector<int>& arr, int target) {
        //     int n = arr.size();
        
        //     // Create a DP table where dp[i][j] represents the number of ways to achieve sum j
        //     // using the first i elements
        //     vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        //     // Base case: If the target sum is 0, there's exactly one way (choose no elements)
        //     for (int i = 0; i < n; i++) {
        //         dp[i][0] = 1;
        //     }
        
        //     // Base case: If we are at index 0, we can form the target only if arr[0] == target
        //     if (arr[0] <= target) {
        //         dp[0][arr[0]] = 1;
        //     }
        
        //     // Fill the DP table for all indices and target sums
        //     for (int ind = 1; ind < n; ind++) {
        //         for (int sum = 0; sum <= target; sum++) {
        //             // Case 1: Exclude the current element
        //             int notTake = dp[ind - 1][sum];
        
        //             // Case 2: Include the current element (if it does not exceed the target sum)
        //             int take = 0;
        //             if (arr[ind] <= sum) {
        //                 take = dp[ind - 1][sum - arr[ind]];
        //             }
        
        //             // Total ways to form the sum
        //             dp[ind][sum] = take + notTake;
        //         }
        //     }
        
        //     // The result is stored in dp[n-1][target], which gives the number of subsets
        //     // of the entire array that sum up to the target
        //     return dp[n - 1][target];
        // }
        
         
         // +++++++++++++++ Space optimization ++++++++++ TC O(n * target).  SC O (target)      
        int perfectSum(vector<int>& arr, int target) {
            int n = arr.size();
            // Use a single DP array to store results for the current target sum
            vector<int> prev(target + 1, 0);
            
            // Base case: If the target sum is 0, there's exactly one way (choose no elements)
            prev[0] = 1;
            
            // Iterate over all elements of the array
            for (int ind = 0; ind < n; ind++) {
                vector<int> curr(target + 1, 0); // Temporary DP array for the current row
                
                for (int sum = 0; sum <= target; sum++) {
                    // Case 1: Exclude the current element
                    int notTake = prev[sum];
                    
                    // Case 2: Include the current element (if it does not exceed the target sum)
                    int take = 0;
                    if (arr[ind] <= sum) {
                        take = prev[sum - arr[ind]];
                    }
                    
                    // Total ways to form the sum
                    curr[sum] = take + notTake;
                }
                
                // Update the previous row to the current row
                prev = curr;
            }
            
            // The result is in the last row of the DP array
            return prev[target];
        }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends