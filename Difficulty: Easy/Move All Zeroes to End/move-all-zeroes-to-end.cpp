//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  //+++++++++++++++++ TC O(N).    SC O(1) +++++++++++++++++++
    void pushZerosToEnd(vector<int>& arr) {
    int n = arr.size();   // Get the size of the array
    int i = 0, j = 0;     // Initialize two pointers i and j
    
    // Traverse through the entire array with i
    while(i < n) {
        // If the current element is not zero
        if(arr[i] != 0) {
            // Swap arr[i] with arr[j] to move non-zero elements to the front
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;

            // Increment j to point to the next position for the next non-zero element
            j++;
        }
        
        // Always increment i to traverse the next element
        i++;
    }
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
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends