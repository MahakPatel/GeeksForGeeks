//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
//   // +++++++++++++++++++ Tabulation ++++++++++ TC O(n*m).  SC O(n*m)
//     int longestCommonSubstr(string& s1, string& s2) {
//         int index1 = s1.size(), index2 = s2.size();
    
//         // DP table to store the length of the longest common suffix for substrings ending at i and j
//         vector<vector<int>> dp(index1 + 1, vector<int>(index2 + 1, 0)); // Initialize with 0
    
//         int ans = 0; // Stores the maximum length of common substring found
    
//         // Build the DP table iteratively
//         for (int i = 1; i <= index1; i++) {
//             for (int j = 1; j <= index2; j++) {
//                 if (s1[i - 1] == s2[j - 1]) {
//                     // If characters match, extend the previous substring length
//                     dp[i][j] = 1 + dp[i - 1][j - 1];
    
//                     // Update the maximum length found
//                     ans = max(ans, dp[i][j]);
    
//                 } else {
//                     // If characters don't match, reset the substring length to 0
//                     dp[i][j] = 0;
//                 }
//             }
//         }
    
//         return ans; // Return the length of the longest common substring
//     }

// +++++++++++++++++++ Space optimization ++++++++++ TC O(n*m).  SC O(m)
        int longestCommonSubstr(string& s1, string& s2) {
        int index1 = s1.size(), index2 = s2.size();
    
        // DP arrays to store the length of the longest common suffix for substrings ending at i and j
        vector<int> prev(index2 + 1, 0), cur(index2 + 1, 0); // Initialize with 0
    
        int ans = 0; // Stores the maximum length of common substring found
    
        // Build the DP table iteratively
        for (int i = 1; i <= index1; i++) {
            for (int j = 1; j <= index2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    // If characters match, extend the previous substring length
                    cur[j] = 1 + prev[j - 1];
    
                    // Update the maximum length found
                    ans = max(ans, cur[j]);
                } else {
                    // If characters don't match, reset the substring length to 0
                    cur[j] = 0;
                }
            }
            // Update previous row for the next iteration
            prev = cur;
        }
    
        return ans; // Return the length of the longest common substring
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends