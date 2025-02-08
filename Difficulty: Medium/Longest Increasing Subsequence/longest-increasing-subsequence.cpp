//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // +++++++++++ Using Binary Search +++++++++++++
    // TC O(nlogn)
    // SC O(n)
    // Function to find length of longest increasing subsequence.
    int lis(vector<int>& arr) {
        int n = arr.size();
        
        // temp stores the smallest possible tail value for increasing subsequences
        vector<int> temp;
        
        // Initialize temp with the first element
        temp.push_back(arr[0]);
        
        int len = 1;  // Stores the length of the Longest Increasing Subsequence
    
        for (int i = 1; i < n; i++) {
            if (arr[i] > temp.back()) {  
                // If arr[i] is greater than the last element in temp, extend LIS
                temp.push_back(arr[i]);
                len++;
            } else {
                // Replace the first element in temp that is >= arr[i]
                int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[ind] = arr[i];
            }
        }
    
        return len;  // Return the length of the longest increasing subsequence
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends