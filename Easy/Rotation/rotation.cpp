//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int low = 0;
        int high = n - 1;
        int ans = INT_MAX;
        int index = -1;// take min value as max


// so if you find the index of smallest element of array you will get the number of rotation
        while (low <= high) {
            int mid = (low + high) / 2;

            // if array is already sorted
            if (arr[low] <= arr[high]) {
                if(arr[low]<ans){ 
                    index=low;
                    ans = arr[low];
                }
                break;
            }

            // if left part is sorted:
            if (arr[low] <= arr[mid]) {
                // keep the minimum:
                if(arr[low]<ans){
                    index=low;
                    ans = arr[low];
                }

                // Eliminate left half:
                low = mid + 1;
            } else { // if right part is sorted:
            
                if(arr[mid]<ans){
                    index=mid;
                    ans = arr[mid];
                }

                // Eliminate right half:
                high = mid - 1;
            }
        }
        return index;
    }
	

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends