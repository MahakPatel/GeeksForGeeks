//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:    
  // Helper function to generate subsets
    void subSets(int index, vector<int>& nums, vector<vector<int>>& ans,
                 vector<int>& ds) {
        // Add the current subset (represented by ds) to the answer
        ans.push_back(ds);

        // Iterate through the array starting from the current index
        for (int i = index; i < nums.size(); i++) {
            // Skip duplicate elements by checking if the current element is the
            // same as the previous one (only when i != index to prevent
            // skipping the first element of the subset)
            if (i != index && nums[i] == nums[i - 1])
                continue;

            // Add the current element to the subset
            ds.push_back(nums[i]);

            // Recursively generate the next subsets starting from the next
            // index
            subSets(i + 1, nums, ans, ds);

            // Backtrack: Remove the current element from the subset
            ds.pop_back();
        }
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        vector<vector<int>> ans; // This will store all unique subsets
        vector<int> ds; // This will store the current subset during recursion

        // Sort the array to ensure duplicates are adjacent
        sort(nums.begin(), nums.end());

        // Start the recursive subset generation from index 0
        subSets(0, nums, ans, ds);

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends