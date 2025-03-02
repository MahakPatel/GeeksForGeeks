//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    void solve(int col, vector<vector<int>>& ans,vector<int>& place,
    int n,vector<int>& leftRow,vector<int>& lowerDiagonal,
    vector<int>& upperDiagonal){
        if(col == n){
            ans.push_back(place);
            return;
        }
        for(int row =0;row<n;row++){
            if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0
            && upperDiagonal[n-1+col-row] == 0){
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                place.push_back(row+1);
                solve(col+1,ans,place,n,leftRow,lowerDiagonal,upperDiagonal);
                place.pop_back();
                
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1+col-row] = 0;
                
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> place;
        
        vector<int> leftRow(n,0);
        vector<int> lowerDiagonal(2*n-1,0);
        vector<int> upperDiagonal(2*n-1,0);
        
        solve(0,ans,place,n,leftRow,lowerDiagonal,upperDiagonal);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends