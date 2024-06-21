//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
      // code here
    int fl{-1}, cl{INT_MAX};

    for (int i = 0; i < n; i++) {
        if (arr[i] <= x) {
            fl = max(arr[i], fl); // to find the floor
        }

        if (arr[i] >= x) {
            cl = min(arr[i], cl);  // to find the ceil
        }
    }
    if (cl == INT_MAX) {
        cl = -1;
    }
    
    return {fl, cl};
}