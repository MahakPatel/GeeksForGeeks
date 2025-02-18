//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // +++++++++++++++ Brute Force ++++++++++++++++++
    // TC O(n^2)
    // SC O(n)
//     vector<int> findTwoElement(vector<int>& arr) {
//     int n = arr.size();
    
//     int miss = -1;  // variable to store the missing number
//     int repeat =-1;  // variable to store the repeated number
    
//     // Loop through the array from 1 to n to check for missing and repeated elements
//     for(int i = 1; i <= n; i++) { // Loop from 1 to n because the array contains values 1 to n
//         int count = 0;
        
//         // Inner loop to count occurrences of the current number (i) in the array
//         for(int j = 0; j < n; j++) {
//             if(arr[j] == i) {
//                 count++;
//             }
//         }
        
//         // If the current number appears twice, it's the repeated number
//         if(count == 2) {
//             repeat = i;
//         }
//         // If the current number doesn't appear at all, it's the missing number
//         else if(count == 0) {  
//             miss = i;
//         }

 //if(repeat != -1 && miss != -1) break;
//     }

    
//     // Store the repeated and missing elements in the result vector
//     vector<int> ans;
//     ans.push_back(repeat);  // Add the repeated element
//     ans.push_back(miss);  // Add the missing element
    
//     return ans;  // Return the result
// }
    // +++++++++++++++ Better Solution ++++++++++++++++++
    // TC O(n)
    // SC O(n)
    //  vector<int> findTwoElement(vector<int>& arr) {
    //     int n = arr.size();
        
    //     int miss = -1;  // Variable to store the missing number
    //     int repeat = -1;  // Variable to store the repeated number
    //     int hash[n+1] = {0};  // Array to count occurrences of each number (1-based index)
        
    //     // Fill the hash array by counting occurrences of each number
    //     for(int i = 0; i < n; i++) {
    //         hash[arr[i]]++;  // Increment count of arr[i]
    //     }
        
    //     // Check for missing and repeated elements
    //     for(int i = 1; i <= n; i++) {  // Loop from 1 to n
    //         if(hash[i] == 2) repeat = i;  // If a number appears twice, it's the repeated number
    //         else if(hash[i] == 0) miss = i;  // If a number doesn't appear, it's the missing number
            
    //         // If both the repeat and miss are found, break early to save time
    //         if(repeat != -1 && miss != -1) break;
    //     }
        
    //     // Store the repeated and missing elements in the result vector
    //     vector<int> ans;
    //     ans.push_back(repeat);  // Add the repeated element
    //     ans.push_back(miss);  // Add the missing element
        
    //     return ans;  // Return the result
    // }
    
    // ++++++++++++++++++ Optimal Solution +++++++++++++++
    // TC O(n)
    // SC O(1)
    vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();
    
    // Initializing the sums
    long long s1 = 0, s2 = 0;
    long long SN = 0, S2N = 0;
    
    // Compute the sum and sum of squares of the input array elements
    for (int i = 0; i < n; i++) {
        s1 += arr[i];  // Sum of elements
        s2 += (long long)arr[i] * (long long)arr[i];  // Sum of squares of elements
    }

    // Calculate SN and S2N (expected sums for 1 to n)
    SN = (long long)n * (n + 1) / 2;
    S2N = (long long)n * (n + 1) * (2 * n + 1) / 6;
    
    // Calculate differences
    long long val1 = s1 - SN;  // This is x - y
    long long val2 = s2 - S2N;  // This is x^2 - y^2
    
    // Calculate the sum of x and y
    val2  = val2/val1;  // val2 / val1 gives x + y
    
    // Now we can calculate x and y
    long long x = (val1 + val2) / 2;  // x = (val1 + val2) / 2
    long long y = x - val1;  // y = x - val1
    
    return {(int)x, (int)y};  // Return the missing and repeated elements
}


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends