//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        
        // using linear Search
        
    //     int ans=1;
    //     for(int i=1;i<=x;i++){
    //         if(i*i<=x){
    //             ans = i;
    //         }
    //         break;
    //     }
        
    //     return ans;
    // }
        
        // Applying binary Search Tree - TC - O(logn)
      int low =1;
      int high = x;
      long long int ans = 1;

      while(low<= high){
          
          long long mid = (low + high) / 2;
          
          long long val = mid * mid;
          if (val <= (long long)(x)) {
            //eliminate the left half:
            ans= mid;
              low = mid + 1;
          }
          else {
            //eliminate the right half:
            high = mid - 1;
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends