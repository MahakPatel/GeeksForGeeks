//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
  //++++++++++++++++ TC O((n*m)log(n*m)).  SC O(n*m) +++++++++++++++++
    int MinimumEffort(int n, int m, vector<vector<int>> &heights) {
        // Create a priority queue containing pairs of cells 
        // and their respective distance from the source cell in the 
        // form {diff, {row of cell, col of cell}}.
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        // Distance matrix to track the minimum effort to reach each cell
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0; // Starting point effort is 0

        pq.push({0, {0, 0}}); // Push the starting cell into the queue

        // Direction arrays for moving right, up, left, down
        int delRow[] = {0, -1, 0, 1};
        int delCol[] = {1, 0, -1, 0};

        // BFS loop
        while (!pq.empty()) {
            auto it = pq.top(); // Get the cell with the minimum effort
            pq.pop();

            int diff = it.first; // Current effort to reach this cell
            int row = it.second.first; // Current cell row
            int col = it.second.second; // Current cell column

            // If we reach the bottom-right corner, return the effort
            if (row == n - 1 && col == m - 1) return diff;

            // Explore the four possible directions
            for (int i = 0; i < 4; i++) {
                int newrow = row + delRow[i]; // New row index
                int newcol = col + delCol[i]; // New column index

                // Check if the new position is within bounds
                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m) {
                    // Calculate the new effort required to move to the new cell
                    int newEffort = max(abs(heights[row][col] - heights[newrow][newcol]), diff);
                    // If the new effort is less than the recorded effort, update and push to the queue
                    if (newEffort < dist[newrow][newcol]) {
                        dist[newrow][newcol] = newEffort; // Update the minimum effort
                        pq.push({newEffort, {newrow, newcol}}); // Push new cell into the queue
                    }
                }
            }
        } 

        return 0; // If the destination is unreachable, return 0 (although this should not happen with valid inputs)
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends