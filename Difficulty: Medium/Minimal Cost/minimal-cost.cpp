//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
     // +++++++++++++++ Mamoization TC O(N * k)   SC O(N) +O(N)
//     // Function to find the minimum cost to reach the end using at most 'k' jumps
// int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k) {
//     // Base case: If we are at the beginning (index 0), no cost is needed.
//     if (ind == 0) return 0;
    
//     // If the result for this index has been previously calculated, return it.
//     if (dp[ind] != -1) return dp[ind];
    
//     int mmSteps = INT_MAX;
    
//     // Loop to try all possible jumps from '1' to 'k'
//     for (int j = 1; j <= k; j++) {
//         // Ensure that we do not jump beyond the beginning of the array
//         if (ind - j >= 0) {
//             // Calculate the cost for this jump and update mmSteps with the minimum cost
//             int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
//             mmSteps = min(jump, mmSteps);
//         }
//     }
    
//     // Store the minimum cost for this index in the dp array and return it.
//     return dp[ind] = mmSteps;
// }
  public:
 
//     int minimizeCost(vector<int>& arr, int& k) {
//         int n = arr.size();
//         vector<int> dp(n, -1); // Initialize a memoization array to store calculated results
//     return solveUtil(n - 1, arr, dp, k); // Start the recursion from the last index
// }
// ++++++++++++++++++ Tabulation +++++++++++++++ TC O(N * k)   SC O(N)
// Function to find the minimum cost to reach the end using at most 'k' jumps
int solveUtil(int n, vector<int>& height, vector<int>& dp, int k) {
    dp[0] = 0;

    // Loop through the array to fill in the dp array
    for (int i = 1; i < n; i++) {
        int mmSteps = INT_MAX;

        // Loop to try all possible jumps from '1' to 'k'
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                mmSteps = min(jump, mmSteps);
            }
        }
        dp[i] = mmSteps;
    }
    return dp[n - 1]; // The result is stored in the last element of dp
}
// Function to find the minimum cost to reach the end of the array
int minimizeCost( vector<int>& height, int k) {
    int n = height.size();
    vector<int> dp(n, -1); // Initialize a memoization array to store calculated results
    return solveUtil(n, height, dp, k);
}

};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends