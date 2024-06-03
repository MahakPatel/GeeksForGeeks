//{ Driver Code Starts
// Initial Template for C++

// C program for implementation of Bubble sort
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// swapping the elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) {
        
         if (n == 1) return; // base condition
        // compare and move biggest element at the end of the array
        for(int i=0;i<n-1;i++){
            if(arr[i]>= arr[i+1]){ // compare element with next element
                 int temp = arr[i]; // swap
                    arr[i] = arr[i+1];
                    arr[i+1]= temp;
                } 
            }
            
            bubbleSort(arr,n-1); // for second intertion apply recursion
        }
        
        //++++++++++++++++++ Brute force approch)+++++++++++++
        // int didSwap=0;
        
        // for(int i=n-1;i>=1;i--){
            
        //     for(int j=0;j<=i-1;j++){
                
        //         if(arr[j]>arr[j+1]){
                    
        //             swap(arr[j],arr[j+1]);
        //             didSwap=1;
        //         //     int temp = arr[j];
        //         //     arr[j] = arr[j+1];
        //         //     arr[j+1]= temp;
        //         // }
        //     }
        // }
        // // if array is already sort then no need to run for n-1(second loop)
        // if(didSwap ==0){
        //     break;
        // }
        
    
    
};


//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main() {
    int arr[1000], n, T, i;

    scanf("%d", &T);

    while (T--) {

        scanf("%d", &n);

        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;

        ob.bubbleSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends