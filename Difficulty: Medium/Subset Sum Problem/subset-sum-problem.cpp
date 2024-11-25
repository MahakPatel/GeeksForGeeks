//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
   // +++++++++++++ Recursive +++++++++++ TC O(2^N).   SC O(N) +++++++++
    // bool f(int index, int target, vector<int>& arr) {
    //     // Base Case 1: If target becomes 0, return true (we found a subset)
    //     if (target == 0) return true;
    
    //     // Base Case 2: If we've reached the end of the array, return false
    //     if (index < 0) return false;
    
    //     // Option 1: Do not take the current element
    //     bool notTake = f(index - 1, target, arr);
    
    //     bool take = false;
    //     // Option 2: Take the current element, but only if the target is >= arr[index]
    //     if (target >= arr[index]) {
    //         take = f(index - 1, target - arr[index], arr);
    //     }
    
    //     // Return true if either not taking or taking the current element results in a solution
    //     return take || notTake;
    // }
    
    // bool isSubsetSum(vector<int>& arr, int target) {
    //     int n = arr.size();
    //     return f(n - 1, target, arr);  // Call the recursive function with last index and target
    // }
    
    // ++++++++++++++++ Memoization +++++++++++ TC O(N*Target).    SC O(N*Target) + N
        // bool f(int index, int target, vector<int>& arr, vector<vector<bool>> &dp) {
        //     // Base Case 1: If target becomes 0, return true (we found a subset)
        //     if (target == 0) return true;
        
        //     // Base Case 2: If we've reached the end of the array, return false
        //     if (index < 0) return false;
        
        //     // Check if the result is already calculated in dp
        //     if (dp[index][target] != -1) return dp[index][target]; // Corrected here
            
        //     // Option 1: Do not take the current element
        //     bool notTake = f(index - 1, target, arr, dp);
        
        //     bool take = false;
        //     // Option 2: Take the current element, but only if the target is >= arr[index]
        //     if (target >= arr[index]) {
        //         take = f(index - 1, target - arr[index], arr, dp);
        //     }
        
        //     // Store the result in dp and return the result
        //     dp[index][target] = take || notTake;
        //     return dp[index][target];
        // }
    
        // bool isSubsetSum(vector<int>& arr, int target) {
        //     int n = arr.size();
        //     vector<vector<bool>> dp(n, vector<bool>(target + 1, false)); // Initialize with -1
        //     return f(n - 1, target, arr, dp);  // Call the recursive function with last index and target
        // }
        
        // ++++++++++++++++++ Tabulation +++++++++ TC O(N * Target).  SC O(N * Target)
        
        // bool isSubsetSum(vector<int>& arr, int target) {
        //     int n = arr.size();
            
        //     vector<vector<bool>> dp(n,vector<bool>(target+1,0));
            
        //     for(int i=0;i<n;i++){
        //         dp[i][0] = true;
        //     }
            
        //     dp[0][arr[0]] = true;
            
        //     for(int i=1;i<n;i++){
        //         for(int j=1;j<=target;j++){
        //             bool notTake = dp[i - 1][target];
                
        //             bool take = false;
                  
        //             if (target >= arr[i]) {
        //                 take = dp[i - 1][target];
        //             }
        //             dp[i][target] = take || notTake;
        //         }
        //     }
            
        //     return dp[n-1][target];
        // }
        
        // ++++++++++++++ Space Optimization +++++ TC O(N * Target). SC O(Target)
        
         bool isSubsetSum(vector<int>& arr, int target) {
            int n = arr.size();
            
            // Two arrays: 'prev' stores the previous row, 'cur' stores the current row
            vector<bool> prev(target + 1, 0), cur(target + 1, 0);
            
            prev[0] = cur[0] = true;  // Base case: subset sum of 0 is always possible (empty subset)
        
            // If arr[0] is less than or equal to target, mark it as possible in prev
            if (arr[0] <= target) {
                prev[arr[0]] = true;
            }
        
            // Iterate through all elements of the array starting from index 1
            for (int i = 1; i < n; i++) {
                for (int j = 1; j <= target; j++) {
                    // Option 1: Do not take the current element
                    bool notTake = prev[j];
                    
                    // Option 2: Take the current element, but only if j >= arr[i]
                    bool take = false;
                    if (j >= arr[i]) {
                        take = prev[j - arr[i]];  // Look at the previous row for the remaining sum
                    }
        
                    // Current value of dp[j] is the union of the two choices (take or not take)
                    cur[j] = take || notTake;
                }
                
                // Move to the next row by copying current results into prev
                prev = cur;
            }
            
            // The answer will be stored in prev[target], as it holds the final row after all iterations
            return prev[target];
        }


};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends