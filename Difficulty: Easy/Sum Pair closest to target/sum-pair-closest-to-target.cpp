//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  // +++++++++++++++ TC O(nlogn).    SC 0(1) +++++++++++++++
   vector<int> sumClosest(vector<int>& arr, int target) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    // Edge case: If the array has fewer than 2 elements, return an empty vector
    if (n < 2) {
        return {};
    }
    
    int mini = INT_MAX; // To store the minimum difference
    int left = 0, right = n - 1;
    pair<int, int> closestPair; // To store the closest pair
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        int diff = abs(target - sum); // Calculate the absolute difference
        
        // Update the minimum difference and the closest pair
        if (diff < mini) {
            mini = diff;
            closestPair = {arr[left], arr[right]};
        }
        
        // Move pointers based on the sum and target
        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    // Return the closest pair as a vector
    return {closestPair.first, closestPair.second};
}

};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends