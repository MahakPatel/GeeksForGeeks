//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    // ++++++++++++++ Using Longest Increasing Subsequence+++++++++
    // TC O(n^2)
    // SC O(n)
    int LongestBitonicSequence(int n, vector<int> &arr) {
        // dp1[i] stores the length of the Longest Increasing Subsequence (LIS) ending at index i
        vector<int> dp1(n, 1);
    
        // Compute LIS for each index
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                // If arr[prev] < arr[i], check if taking arr[i] extends a longer LIS
                if (arr[prev] < arr[i] && 1 + dp1[prev] > dp1[i]) {
                    dp1[i] = 1 + dp1[prev];
                }
            }
        }
    
        // dp2[i] stores the length of the Longest Decreasing Subsequence (LDS) starting at index i
        vector<int> dp2(n, 1);
    
        // Compute LDS for each index
        for (int i = n - 1; i >= 0; i--) {
            for (int next = i + 1; next < n; next++) {
                // If arr[next] < arr[i], check if taking arr[i] extends a longer LDS
                if (arr[next] < arr[i] && 1 + dp2[next] > dp2[i]) {
                    dp2[i] = 1 + dp2[next];
                }
            }
        }
    
        // Find the maximum Bitonic Subsequence Length
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (dp1[i] > 1 && dp2[i] > 1) {  // Ensure both LIS and LDS exist
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
            }// Subtract 1 to avoid double counting `arr[i]`
        }
    
        return maxi;
    }


};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends