//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


struct meeting {
   int start;
   int end;
   int pos;
};

// TC - O(2N*logN) SC - O(3N)
class Solution {
  public:
    // comparator to to check second meeting end value if greater then previous one or not
   bool static comparator(struct meeting m1, meeting m2) {
         if (m1.end < m2.end) return true;
         else if (m1.end > m2.end) return false;
         else if (m1.pos < m2.pos) return true;
         return false;
      }
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
      meeting arr[n];
      
      for(int i=0;i<n;i++){
          arr[i].start = start[i]; //assign start , end , pos to new data structure
          arr[i].end = end[i];
          arr[i].pos = i + 1;
      }
      
      sort(arr,arr+n,comparator); // sort the arr accoering to end time
      
      vector < int > answer; // to store pos

      int limit = arr[0].end; // first meeting end time
      int count = 1; // 1 beacause first meeting will be always posible
      answer.push_back(arr[0].pos); // push pos of first meeting into answer vector
      
      for(int i=1;i<n;i++){
          if(limit < arr[i].start){ // if limit is less then next meeting start time
              count = count + 1; // increase meeting count
              limit = arr[i].end; // assign limit to current end time
            answer.push_back(arr[i].pos); // and push the pos into vector
          }
      }
      
      return count; // return numbers pf meeting
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends