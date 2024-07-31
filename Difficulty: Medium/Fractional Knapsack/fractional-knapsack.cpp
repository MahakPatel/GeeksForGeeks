//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

// TC - O(NlogN)  SC - O(1)
class Solution {
    public:
      // comparatop to compare two value
      bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
  public:
  
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
  
        sort(arr, arr + n, comp); // in decending order
    
        int curWeight = 0; // to store total weight
        double finalvalue = 0.0; // to store total value

        for (int i = 0; i < n; i++) {

            if (curWeight + arr[i].weight <= w) { // check total weight is less then given w
                curWeight += arr[i].weight; // add weight
                finalvalue += arr[i].value; // add value
            } else { // other wise take fraction value
                int remain = w - curWeight; // calculate remain weight
                finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain; // add total value from remain weight
                break;
            }
        }

        return finalvalue;

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends