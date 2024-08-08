//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++
// TC O(NlogN).     SC O(1)
class Solution {
  public:
    // Function to compute the average wait time for a list of burst times
    long long solve(std::vector<int>& bt) {
        int n = bt.size(); // Get the number of burst times
    
        // Sort the burst times in ascending order
        std::sort(bt.begin(), bt.end());
    
        long long waitTime = 0; // Initialize total wait time
        int t = 0; // Initialize the current time (completion time of the last process)
    
        // Calculate the total wait time
        for(int i = 0; i < n; i++) {
            waitTime += t; // Add the current time to the total wait time
            t += bt[i]; // Update the current time by adding the burst time of the current process
    }
    
    // Return the average wait time
    return (waitTime / n);
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        long long ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends