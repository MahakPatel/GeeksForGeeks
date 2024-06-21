//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        
    // If last element is smaller than x
    if (x >= v[n - 1])
        return n - 1;
 
    // If first element is greater than x
    if (x < v[0])
        return -1;
 
    // Linearly search for the first element
    // greater than x
    for (int i = 1; i < n; i++)
        if (v[i] > x)
            return (i - 1);
 
    return -1;
        // use binary search to solve this
    // int low =0,high=n-1;
    // int ans=n;  // size of array
    
    // if (x < v[0])
    //     return -1;
    
    // while(low<=high){
    //     int mid = (low+high)/2; // find mid
        
    //     if(v[mid]>=x){ // if v[mid] is >= then ans may be mid and now you can search in first half of array
    //         ans = mid;
    //         high = mid-1;
    //     }else{
    //         low = mid+1; // else search in second half of array
    //     }
    // }

    // return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends