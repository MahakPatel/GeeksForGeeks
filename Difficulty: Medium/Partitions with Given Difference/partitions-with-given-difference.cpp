//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
int mod = (int)(1e9 + 7); // Modulo for large numbers
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();

        // Create a DP table where dp[i][j] represents the number of ways to achieve sum j
        // using the first i elements
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Base case: If arr[0] == 0, there are two ways to form sum 0: include or exclude 0
        dp[0][0] = (arr[0] == 0) ? 2 : 1;

        // Base case: If arr[0] is nonzero and equals target, set dp[0][target] = 1
        if (arr[0] != 0 && arr[0] <= target) {
            dp[0][arr[0]] = 1;
        }

        // Fill the DP table for all indices and target sums
        for (int ind = 1; ind < n; ind++) {
            for (int sum = 0; sum <= target; sum++) {
                // Case 1: Exclude the current element
                int notTake = dp[ind - 1][sum];

                // Case 2: Include the current element (if it does not exceed the target sum)
                int take = 0;
                if (arr[ind] <= sum) {
                    take = dp[ind - 1][sum - arr[ind]];
                }

                // Total ways to form the sum
                dp[ind][sum] = (take + notTake) % mod;
            }
        }

        // The result is stored in dp[n-1][target]
        return dp[n - 1][target];
    }

// ++++++++++++++++++= Tabulation ++++++++ TC O(n * target).  SC O(n* larget)
    int countPartitions(vector<int>& arr, int d) {
        int totalSum = 0;
        int n = arr.size();

        // Calculate the total sum of the array
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        // Check if partitioning is possible
        if (totalSum - d < 0 || (totalSum - d) % 2 != 0) return 0;

        // Find subsets that sum to (totalSum - d) / 2
        int target = (totalSum - d) / 2;
        return perfectSum(arr, target);
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends