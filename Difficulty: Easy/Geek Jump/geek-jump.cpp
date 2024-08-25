//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:

// +++++++++++++++ / Memoization : TC O(N) SC O(N) + O(N)+++++++++++++++
//     int f(int index, const std::vector<int>& height, std::vector<int>& dp) {
//         // Base case: If at the first step, no energy is required
//         if (index == 0) return 0;
        
//         // Return the already computed value if it exists
//         if (dp[index] != -1) {
//             return dp[index];
//         }
        
//         // Calculate energy to move to the previous step
//         int left = f(index - 1, height, dp) + abs(height[index] - height[index - 1]);
        
//         // Initialize right as a large number
//         int right = INT_MAX;
        
//         // Calculate energy to jump over one step if possible
//         if (index >= 2) {
//             right = f(index - 2, height, dp) + abs(height[index] - height[index - 2]);
//         }
        
//         // Store and return the minimum energy required to reach the current step
//         return dp[index] = std::min(left, right);
//     }

// 
//     int minimumEnergy(const std::vector<int>& height, int n) {
//         // Initialize dp vector with -1 (indicating uncomputed values)
//         std::vector<int> dp(n, -1);
        
//         // Compute the minimum energy required to reach the last step
//         return f(n - 1, height, dp);
//     }

// ++++++++++++++ Tabulation tc O(N)   SC O(N) ++++++++++++
//   int minimumEnergy(const std::vector<int>& height, int n) {
//         // Initialize dp vector with 0 for all elements
//         std::vector<int> dp(n, 0);
        
//         // Base case: Starting point (no energy required)
//         dp[0] = 0;

//         for(int i = 1; i < n; i++) {
//             // Calculate energy for stepping from the previous step
//             int fs = dp[i - 1] + abs(height[i] - height[i - 1]);

//             // Calculate energy for jumping over one step (if possible)
//             int ss = INT_MAX;
//             if(i >= 2) {
//                 ss = dp[i - 2] + abs(height[i] - height[i - 2]);
//             }
            
//             // Store the minimum energy required to reach the current step
//             dp[i] = std::min(fs, ss);
//         }
        
//         // Return the minimum energy required to reach the last step
//         return dp[n - 1];
//     }


// ++++++++++++++ Tablular Space Otimazied     TC O(N).   SC O(1) +++++++++++
int minimumEnergy(const std::vector<int>& height, int n) {
       
       int prev = 0;
       int prev2 = 0;
       

        for(int i = 1; i < n; i++) {
            // Calculate energy for stepping from the previous step
            int fs = prev + abs(height[i] - height[i - 1]);

            // Calculate energy for jumping over one step (if possible)
            int ss = INT_MAX;
            if(i >= 2) {
                ss =prev2 + abs(height[i] - height[i - 2]);
            }
            
            // Store the minimum energy required to reach the current step
            int current = std::min(fs, ss);
            
            prev2= prev;
            prev =current;
        }

        
        // Return the minimum energy required to reach the last step
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends