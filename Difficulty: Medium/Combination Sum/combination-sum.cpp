//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  
  
    void findCombination(int index,int target,vector<int> &arr,vector<vector<int>> &ans, vector<int>&ds){
        if(index == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            
              return; // else return empty
        }
         // Picked  
        if (arr[index] <= target){
            ds.push_back(arr[index]);
            findCombination(index,target - arr[index],arr,ans,ds);
            ds.pop_back();
        
        }
            // not picked
         findCombination(index+1,target,arr,ans,ds);
        
    }// Function to find all combinations of elements
    // in array arr that sum to target.
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target,arr,ans,ds);
        
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
        vector<vector<int>> ans = ob.combinationSum(arr, sum);
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