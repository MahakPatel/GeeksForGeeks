//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    // +++++++++++++++++ Brute Force +++++++++++++++
    // TC O(n^2)
    // SC O(1)
    // int inversionCount(vector<int> &arr) {
    //   int n = arr.size();
    //   int count = 0;
       
    //   for(int i=0;i<n;i++){
    //       for(int j = i+1;j<n;j++){
    //           if(arr[i] > arr[j]){
    //               count++;
    //           }
    //         }
    //   }
       
    //   return count;
    // }
    
        // +++++++++++++++++ Optimal Solution +++++++++++++++
        // ++++++++++++ Using Merge Sort+++++++++++++++++
        // TC O(nlogn)
        // SC O(n)
        int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr
    
        //Modification 1: cnt variable to count the pairs: ++++++++++++++
        int cnt = 0;
    
        //storing elements in the temporary array in a sorted manner//
    
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1); //Modification 2 +++++++++++ just Change here in merge sort
                right++;
            }
        }
    
        // if elements on the left half are still left //
    
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
    
        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
    
        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    
        return cnt; // Modification 3 // ++++++++++++Modify return count
    }
    
    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2 ;
        cnt += mergeSort(arr, low, mid);  // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += merge(arr, low, mid, high);  // merging sorted halves
        return cnt;
    }
    
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return  mergeSort(arr,0,n-1);
        
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends