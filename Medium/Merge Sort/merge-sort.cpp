//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int left = l; //left array  start with index 0
        int right = m+1; // right array start with mid+1 index
        vector<int> mergeArr;
        
        while(left<= m && right <= r){
            if(arr[left]<= arr[right]){  // compare left and right array 
                mergeArr.push_back(arr[left]); // and push smaller elementr
                left++;
            }else{
                mergeArr.push_back(arr[right]);
                right++;
            }
        }
        
        while(left<=m){ // if second array finish and push all the element of array 1 
                mergeArr.push_back(arr[left]);
                left++;
        }
        
                
        while(right<=r){ // if first array finish and push all the element of array 2 
                mergeArr.push_back(arr[right]);
                right++;
        }
        
        
   for(int i=l;i<=r;i++){
       arr[i] = mergeArr[i-l];
   }
        
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l == r){
            return;
        }
        
        int mid = (l+r)/2; // find mid of array
        
        mergeSort(arr,l,mid); // divide the first portion of array
        mergeSort(arr,mid+1,r);// divide the second portion of array
        merge(arr,l,mid,r); // merge the divided array into larger array
    }
};

// Time Complexity : o(nlogn)
// Space Complexity : 0(n)

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends