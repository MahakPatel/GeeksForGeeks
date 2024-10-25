//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
        // ++++++++++++++ Brute Force ++++++ TC O(N^2).  SC O(1)
   // Function to calculate the maximum number of fruits that can be collected
    // int totalFruits(vector<int> &arr) {
    //     int maxLen = 0; // Variable to store the maximum length of fruits collected
    //     int n = arr.size(); // Size of the input array

    //     // Iterate through each starting point in the array
    //     for (int i = 0; i < n; i++) {
    //         set<int> st; // Set to track the types of fruits (unique elements)

    //         // Iterate from the current starting point to the end of the array
    //         for (int j = i; j < n; j++) {
    //             st.insert(arr[j]); // Insert the current fruit type into the set

    //             // Check if the number of unique fruit types is within the limit (<= 2)
    //             if (st.size() <= 2) {
    //                 // Update maxLen if the current length is greater
    //                 maxLen = max(maxLen, j - i + 1);
    //             } else {
    //                 // If more than 2 types of fruits are found, break out of the loop
    //                 break;
    //             }
    //         }
    //     }

    //     // Return the maximum length of fruits collected
    //     return maxLen;
    // }
    
    
    // ++++++++++++++ Better Solution +++++++++++ Tc O(n+n) = O(2N).  Sc O(3)
  // Function to find the maximum number of fruits that can be collected
    // int totalFruits(vector<int>& arr) {
    //     int maxLen = 0; // Variable to store the maximum length of fruits collected
    //     int n = arr.size(); // Size of the input array
    //     int right = 0; // Right pointer for the sliding window
    //     int left = 0; // Left pointer for the sliding window
    //     map<int, int> mp; // Map to count the number of each type of fruit

    //     // Iterate with the right pointer to expand the window
    //     while (right < n) {
    //         // Add the current fruit to the count
    //         mp[arr[right]]++;

    //         // If we have more than 2 types of fruits, shrink the window from the left
    //         while (mp.size() > 2) {
    //             mp[arr[left]]--; // Decrease the count of the leftmost fruit
    //             // If the count drops to zero, remove it from the map
    //             if (mp[arr[left]] == 0) {
    //                 mp.erase(arr[left]);
    //             }
    //             left++; // Move the left pointer to the right
    //         }

    //         // Update the maximum length if the current window is valid
    //         maxLen = max(maxLen, right - left + 1);

    //         // Move the right pointer to the right
    //         right++;
    //     }

    //     return maxLen; // Return the maximum length found
    // }
    
    
    // +++++++++++++++ Optimal Solution +++++++++++ TC O(N).   SC O(1)
  // Function to find the maximum number of fruits that can be collected
    int totalFruits(vector<int>& arr) {
        int maxLen = 0; // Variable to store the maximum length of fruits collected
        int n = arr.size(); // Size of the input array
        int right = 0; // Right pointer for the sliding window
        int left = 0; // Left pointer for the sliding window
        map<int, int> mp; // Map to count the number of each type of fruit
        
        // Iterate with the right pointer to expand the window
        while (right < n) {
            mp[arr[right]]++; // Add the current fruit to the map
            
            // If we have more than 2 types of fruits, shrink the window from the left
            while (mp.size() > 2) {
                mp[arr[left]]--; // Decrease the count of the leftmost fruit
                if (mp[arr[left]] == 0) { 
                    mp.erase(arr[left]); // Remove it from the map if the count is zero
                }
                left++; // Move the left pointer to the right
            }
            
            // Calculate the length of the current valid window
            maxLen = max(maxLen, right - left + 1);
            right++; // Move the right pointer to the right
        }
        
        return maxLen; // Return the maximum length found
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends