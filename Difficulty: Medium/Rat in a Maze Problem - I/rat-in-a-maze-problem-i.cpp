//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  
    // TC O(4^(n*m))
    // SC O(m*n)
    void solve(int i, int j, vector<vector<int>>& mat, int n, 
               vector<vector<int>>& vis, int di[], int dj[], 
               string move, vector<string>& ans) {
        if (i == n - 1 && j == n - 1) {  // Base case: reached destination
            ans.push_back(move);
            return;
        }
        
        string dir = "DLRU";  // Direction order
    
        for (int index = 0; index < 4; index++) {
            int nexti = i + di[index];
            int nextj = j + dj[index];
    
            if (nexti >= 0 && nextj >= 0 && nexti < n && 
                nextj < n && !vis[nexti][nextj] && mat[nexti][nextj] == 1) {
                
                vis[i][j] = 1;  // Mark cell as visited
                solve(nexti, nextj, mat, n, vis, di, dj, move + dir[index], ans);
                vis[i][j] = 0;  // Backtrack
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
    
        int di[] = {1, 0, 0, -1};  // D, L, R, U
        int dj[] = {0, -1, 1, 0}; 
    
        if (mat[0][0] == 1) {  // Check if start position is open
            solve(0, 0, mat, n, vis, di, dj, "", ans);
        }
    
        return ans;
    }

};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends