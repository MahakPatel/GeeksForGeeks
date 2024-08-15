//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

// TC O(NlogN). SC O(N)
class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
    int sum = 0;           // Cumulative sum of elements
    int maxi = 0;          // Maximum length of subarray with sum 0
    unordered_map<int, int> mpp; // Map to store the first occurrence of each cumulative sum
    
    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Update cumulative sum
        
        // If the cumulative sum is zero, the subarray from the start to current index has zero sum
        if (sum == 0) {
            maxi = i + 1; // Update the maximum length
        } else {
            // If cumulative sum is already seen, calculate the length of subarray with zero sum
            if (mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); // Update maximum length if current length is larger
            } else {
                // Store the first occurrence of this cumulative sum
                mpp[sum] = i;
            }
        }
    }
    
    return maxi; // Return the maximum length of subarray with sum zero
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends