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
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low< high){
          int partitionIndex =  partition(arr,low,high); // find the pivot index and move the pivot element at that index
           quickSort(arr,low,partitionIndex-1); // recursive call for low to pivot-1 index
           quickSort(arr,partitionIndex+1,high);// recursive call for pivot + 1 index to high 
       }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int i=low;
        int j=high; // j index start by back side
        int pivot = arr[low]; // select first element as pivot
        
        while(i<j){
            while(arr[i] <= pivot && i<= high-1){ // if first portion of element is smaller than pivot just move i index 
                i++;
            }
            
            while(arr[j] > pivot && j>= low+1){ // if second portion of element is greater than pivot just move j index
                j--;
            }
            if(i<j){             // after moving I and J index swap this
                swap(arr[i],arr[j]);
            }
        }
        
        swap(arr[low],arr[j]); // swap jth element with pivot and place pivot at that index
        
            return j; //return pivot index
        
    }
    
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends