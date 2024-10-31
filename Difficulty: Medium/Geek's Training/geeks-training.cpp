//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // +++++++++++++ TC O(N).  SC O(N)
    // Recursive function to calculate maximum points
    int f(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        // Base case: If it's the first day
        if (day == 0) {
            int maxi = 0; // To keep track of the maximum points for the first day
            for (int task = 0; task < 3; task++) {
                if (task != last) { // Ensure the task is not the same as the last one
                    maxi = max(maxi, arr[0][task]); // Get the maximum points possible for the first day
                }
            }
            return maxi; // Return the maximum points for the first day
        }

        int maxi = 0; // Variable to keep track of the maximum points for the current day

        // Check if the result is already computed
        if (dp[day][last] != -1) return dp[day][last];

        // Iterate through all tasks for the current day
        for (int task = 0; task < 3; task++) {
            if (task != last) { // Ensure the current task is not the same as the last task
                // Calculate points for the current task and add the result of the next day
                int point = arr[day][task] + f(day - 1, task, arr, dp);
                maxi = max(maxi, point); // Update the maximum points
            }
        }

        // Store the result in the dp array
        return dp[day][last] = maxi; // Return the maximum points for the current day
    }

    // Main function to calculate maximum points
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n, vector<int>(4, -1)); // DP table initialized to -1
        return f(n - 1, 3, arr, dp); // Start from the last day with no previous task
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends