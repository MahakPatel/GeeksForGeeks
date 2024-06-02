//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        
    //     int i=0,j=0;
    //     vector<int> unionArr;
        
    //     while(i<n && j<m){
    //         if(arr1[i]<= arr2[j]){
    //             if(unionArr.back()!=arr1[i] || unionArr.size() == 0){
    //                 unionArr.push_back(arr1[i]);
    //             }
    //             i++;
    //         }else{
    //             if(unionArr.back()!=arr2[j] || unionArr.size() == 0){
    //                 unionArr.push_back(arr2[j]);
    //             }
    //             j++;
    //         }
            
    //     }
    //         while(i<n){
    //              if(unionArr.back()!=arr1[i] || unionArr.size() == 0){
    //                 unionArr.push_back(arr1[i]);
    //             }
    //             i++;
    //         }
            
    //         while(j<m){
    //              if(unionArr.back()!=arr2[j] || unionArr.size() == 0){
    //                 unionArr.push_back(arr2[j]);
    //             }
    //             j++;
    //         }
        
    //           return unionArr;         

    // }
      


        
      //  Brute - Force Approch
        set<int> st;
        vector<int> unionArr;
        
        for(int i=0;i<n;i++){
            st.insert(arr1[i]);
        }
        
        for(int i=0;i<m;i++){
            st.insert(arr2[i]);
        }
        
        for(auto it:st){
            unionArr.push_back(it);
        }
        
        return unionArr;
    }
    
        
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends