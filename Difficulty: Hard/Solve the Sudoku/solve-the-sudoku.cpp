//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
    }
    
    bool solve(vector<vector<int>> &mat){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 0){
                    for(int k=1;k<=9;k++){
                        if(isValid(mat,i,j,k) == true){
                            mat[i][j] = k;
                            
                            if(solve(mat) == true){
                                return true;
                            }else{
                                mat[i][j] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isValid(vector<vector<int>> &mat,int row,int col,int k){
        for(int i=0;i<9;i++){
            if(mat[row][i] == k)
                return false;
            if(mat[i][col] == k)
                return false;
                
            int subRow = 3 * (row/3) + i/3;
            int subCol = 3*(col/3) + i%3;
            
            if(mat[subRow][subCol] == k)
                return false;
        }
        
        return true;
    }
    
};


//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends