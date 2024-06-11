//{ Driver Code Starts
// C program for insertion sort
#include <stdio.h>
#include <math.h>

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
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        
        find(arr,0,n);
   
    }
    
    void find(int arr[],int i, int n){
        if (i==n){ // base condition
            return;
        }
    
        
        int j = i;
  
      while( j>0 && arr[j-1] > arr[j]){ // compare and if the previous element is bigger then the current one then swap
              int temp = arr[j-1];
              arr[j-1] = arr[j];
              arr[j] = temp;
              j--;
            }
            
            find(arr,i+1,n); // recursion
            

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
    ob.insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends