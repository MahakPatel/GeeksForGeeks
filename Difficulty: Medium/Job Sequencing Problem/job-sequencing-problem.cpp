//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/


// ++++++++++++++++ TC O(NlogN + N * MaxProfit).  SC O(1) ++++++++++++++++
class Solution 
{
    public:
    // comparator to compare max profit 
     bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
    // Sort jobs based on profit in descending order
    sort(arr, arr + n, comparison);
    
    // Find maximum deadline among all jobs
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i].dead);
    }
    
    // Initialize variables to track results
    int totalProfit = 0;
    int count = 0;
    
    // Initialize hash array to track job IDs for each deadline
    int hash[maxi + 1];
    for (int i = 0; i <= maxi; i++) {
        hash[i] = -1;
    }
    
    // Iterate through sorted jobs and assign jobs to hash array
    for (int i = 0; i < n; i++) {
        // Place job in the last possible slot before its deadline
        for (int j = arr[i].dead; j > 0; j--) {
            if (hash[j] == -1) {
                hash[j] = arr[i].id;
                totalProfit += arr[i].profit;
                count++;
                break;
            }
        }
    }
    
    return {count, totalProfit};
}

    
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends