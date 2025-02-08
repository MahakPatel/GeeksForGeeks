//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // TC O(N^2)
    // SC O(N)
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // dp[i] stores the length of the LIS ending at index i
        vector<int> dp(n, 1);
    
        // hash[i] helps track the previous index to reconstruct the LIS sequence
        vector<int> hash(n);
        
        int maxi = 1;         // Maximum LIS length found
        int lastIndex = 0;    // Last index of the LIS sequence
    
        // Iterate through the array to calculate dp[i] and track previous indices
        for (int i = 0; i < n; i++) {
            hash[i] = i;  // Initially, each element is its own predecessor
            for (int prev = 0; prev < i; prev++) {
                // If arr[prev] < arr[i], check if taking arr[i] extends a longer LIS
                if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;  // Store previous index for sequence reconstruction
                }
            }
            
            // Update the maximum LIS length and its ending index
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
    
        // Construct the LIS sequence by backtracking using the hash array
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
    
        while (hash[lastIndex] != lastIndex) { // Until we reach the starting element
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
    
        // Reverse the sequence to get the correct order
        reverse(temp.begin(), temp.end());
    
        return temp;  // Return the LIS sequence
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
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends