//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
        int first = firstOccurance(arr,n,x); // will get index of first accurance
        if(first == -1) return 0;
        
        int last =lastOccurance(arr,n,x); // will get index of last occurance


        return last-first+1;  // +1 because index start with 0 
	}
	

    int firstOccurance(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int first = -1; // size of array

        while (low <= high) {
            int mid = (low + high) / 2; // find mid

            if (arr[mid] == x) { // if v[mid] is >= then ans may be mid and now
                                  // you can search in first half of array
                first = mid;
                high = mid - 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
                ; // else search in second half of array
            }
        }

        return first;
    }
    int lastOccurance(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int last = -1; // size of array

        while (low <= high) {
            int mid = (low + high) / 2; // find mid

            if (arr[mid] == x) { // if v[mid] is >= then ans may be mid and now
                                  // you can search in first half of array
                last = mid;
                low = mid + 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
                ; // else search in second half of array
            }
        }

        return last;
    }
};

//{ Driver Code Starts.

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
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends