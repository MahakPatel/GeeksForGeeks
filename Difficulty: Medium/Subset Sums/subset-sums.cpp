//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
  public:
    // Helper function to compute all subset sums
    void func(int index, int sum, int n, vector<int> &arr, vector<int> &subSet) {
        // Base case: If index is equal to n, we have explored all elements
        if (index == n) {
            subSet.push_back(sum);  // Add the current sum of subset to the subSet array
            return;
        }

        // Recursive call to include the current element in the subset
        func(index + 1, sum + arr[index], n, arr, subSet);

        // Recursive call to exclude the current element from the subset
        func(index + 1, sum, n, arr, subSet);
    }

    // Main function to compute the subset sums of the given array
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> subSet;  // This will store all subset sums
        
        // Start the recursive function with initial values: index = 0, sum = 0
        func(0, 0, n, arr, subSet);
        
        // Sort the resulting subset sums in ascending order
        sort(subSet.begin(), subSet.end());

        // Return the sorted subset sums
        return subSet;
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
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends