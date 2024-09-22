//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  // +++++++++++++++++++ Brute force  ++++++++++++++++
  // TC O(N).   SC O(N)
 
//Function to reverse an array
    vector<int> reverseArray(vector<int> &arr) {
        int n = arr.size();        // Get the size of the input array
        vector<int> ans;           // Create a new vector to hold the reversed array
        
        // Iterate from the last index to the first index
        for (int i = n - 1; i >= 0; i--) {
            ans.push_back(arr[i]); // Add the elements in reverse order
        }
        
        return ans;                // Return the reversed array
    }
    
    
    // +++++++++++ Optimal Solution TC O(nlogn).  SC O(1) +++++++++++++++
    
    //  // Function to reverse an array in-place
    // void reverseArray(vector<int>& arr) {
    //     int left = 0;                 // Pointer starting from the beginning of the array
    //     int right = arr.size() - 1;  // Pointer starting from the end of the array
        
    //     // Continue swapping until the two pointers meet
    //     while (left < right) {
    //         // Swap the elements at left and right indices
    //         swap(arr[left], arr[right]);
    //         left++;   // Move the left pointer to the right
    //         right--;  // Move the right pointer to the left
    //     }
    // }

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

        Solution ob;
        arr = ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends