//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(std::vector<int> &arr) {
    int n = arr.size();
    
    // Edge case: If there are fewer than 2 elements, the function can't find a valid pair.
    if (n < 2) {
        return 0; // or handle according to your requirements
    }
    
    // Initialize sum of the first two elements.
    int s = 0;
    for(int i = 0; i < 2; i++) {
        s += arr[i];
    }
    
    // Set initial answer to the sum of the first two elements.
    int ans = s;
    
    // Iterate through the array starting from the 3rd element.
    // Update the sum to include the current element and exclude the element that is no longer part of the window.
    for(int i = 2; i < n; i++) {
        s += arr[i] - arr[i - 2]; // Update the sum by adding the current element and subtracting the element that's left out of the window.
        ans = max(ans, s);    // Update the maximum sum found so far.
    }
    
    return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.pairWithMaxSum(nums) << endl;
    }
    return 0;
}

// } Driver Code Ends