//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    struct Item {
        int value, weight;
    };

    // Comparator to sort items by value-to-weight ratio in descending order
    static bool comp(Item i1, Item i2) {
        return (double)i1.value / i1.weight > (double)i2.value / i2.weight;
    }

    // TC O(nlogn + n + n) = TC O(nlogn)
    // SC O(1)
    // Function to get the maximum total value in the knapsack
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> items(n);

        // Initializing the items vector
        for (int i = 0; i < n; i++) {
            items[i] = {val[i], wt[i]};
        }

        // Sorting items based on their value-to-weight ratio
        sort(items.begin(), items.end(), comp);

        double totalValue = 0.0;

        // Greedy approach: take as much of the most valuable items as possible
        for (int i = 0; i < n; i++) {
            if (items[i].weight <= capacity) {
                // Take the whole item
                capacity -= items[i].weight;
                totalValue += items[i].value;
            } else {
                // Take fraction of the item
                totalValue += (double)items[i].value * ((double)capacity / items[i].weight);
                break; // Knapsack is full
            }
        }

        return totalValue;
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends