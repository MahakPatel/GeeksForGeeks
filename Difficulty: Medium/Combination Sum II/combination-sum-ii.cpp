//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  
  // Recursive function to find unique combinations that sum to the target
    void findCombinationSum(int index, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& ds) {
        // Base case: if the target becomes zero, add the current combination to the answer
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        // Loop through the array starting from 'index'
        for (int i = index; i < arr.size(); i++) {
            // Skip duplicate elements to avoid duplicate combinations
            if (i > index && arr[i] == arr[i - 1]) continue;

            // If the current element is greater than the remaining target, stop further recursion
            if (arr[i] > target) break;

            // Include the current element in the combination
            ds.push_back(arr[i]);

            // Move to the next element (i + 1) to ensure each element is used at most once
            findCombinationSum(i + 1, arr, target - arr[i], ans, ds);

            // Backtrack: remove the last added element before the next iteration
            ds.pop_back();
        }
    }

    // TC O(2^n * nlogn * K) where k = avg length of Combination
    // SC O(k * x) where x = combination
    // Main function to find all unique combinations
    vector<vector<int>> uniqueCombinations(vector<int>& candidates, int target) {
        // Sort the input array to easily handle duplicates
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans; // Stores all valid combinations
        vector<int> ds; // Temporary list to store the current combination

        // Call the recursive function
        findCombinationSum(0, candidates, target, ans, ds);

        return ans;
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
        vector<vector<int>> ans = ob.uniqueCombinations(arr, sum);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                sort(ans[i].begin(), ans[i].end());
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends