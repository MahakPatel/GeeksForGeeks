//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
// ++++++++++++++++ BFS ++++++++++ TC O(N*L) Where N = Numbers of words in List and L = Size of each word
//++++++++++++++++++ SC O(N)
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
 // Create an unordered set from the word list for quick look-up
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q; // Queue to store paths from beginWord to endWord
        q.push({beginWord}); // Start the queue with the initial path containing beginWord

        vector<string> usedOnLevel; // To keep track of words used at the current BFS level
        usedOnLevel.push_back(beginWord); // Initially, beginWord is used
        int level = 0; // To track the current level in the BFS
        vector<vector<string>> ans; // To store all valid transformation sequences

        while (!q.empty()) { // While there are paths to explore
            vector<string> vec = q.front(); // Get the front path from the queue
            q.pop(); // Remove the path from the queue

            // Check if we have moved to a new level in the BFS
            if (vec.size() > level) {
                level++; // Increment the level
                // Erase all words used in the previous level from the set
                for (auto it : usedOnLevel) {
                    st.erase(it); // Remove words to avoid revisiting them
                }
                usedOnLevel.clear(); // Clear the used words for the new level
            }

            string word = vec.back(); // Get the last word in the current path

            // If we have reached the endWord, store the current path in the result
            if (word == endWord) {
                ans.push_back(vec); // Add the current valid path to the result
            }

            // Generate all possible one-letter transformations of the current word
            for (int i = 0; i < word.size(); i++) { // Loop through each character in the word
                char original = word[i]; // Save the original character

                // Iterate over all possible characters from 'a' to 'z'
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch; // Change the current character

                    // If the new transformed word is in the set
                    if (st.count(word) > 0) {
                        vec.push_back(word); // Add the new word to the current path
                        q.push(vec); // Enqueue the new path for further exploration
                        usedOnLevel.push_back(word); // Track the new word used in this level
                        vec.pop_back(); // Restore the path by removing the last added word
                    }
                }

                // Restore the original character before the next iteration
                word[i] = original; 
            }
        }

        return ans; // Return all valid paths found
    }
    
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends