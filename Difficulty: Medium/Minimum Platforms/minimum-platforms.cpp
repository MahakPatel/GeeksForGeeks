//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    // TC O(2(NlogN + N)) SC O(1)
    int findPlatform(int arr[], int dep[], int n)
    {
        std::sort(arr, arr + n); // sort the arrival array
    	int i =0; // point at index 0 of arrival 
    	
        std::sort(dep, dep + n); // sort the departed array
    	int j =0;// point at index 0 of departed 
    	
    	int count =0; // for number of platform
    	int maxCount = 0; //for max number of count
    	
    	while(i<n){ // run till end of array
    	    if(arr[i] <= dep[j]){ // of arrival time is less then departed time
    	        count = count+1; // increase the count
    	        i= i+1; // and move i to next arrival time
    	    }else{ // if departed time is less then arrival
    	        count = count-1; // decrease the count by 1
    	        j = j+1; // move j to next departed time
    	    }
    	    
    	    maxCount = max(maxCount,count); // find the max platform that require
    	}
    	
    	return maxCount;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends