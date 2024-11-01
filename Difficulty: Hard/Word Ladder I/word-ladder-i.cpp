//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 //++++++++++++++++++++++++ BFS    TC O(N*L*26) N = Numers if wordList ,L = Length of each words
 //+++++++++ Sc O(N)
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
       // Create a queue for BFS
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // Start with the beginWord and step count 1

        // Create a set from the wordList for quick lookups
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord); // Remove the beginWord from the set

        while (!q.empty()) {
            string word = q.front().first; // Get the current word
            int step = q.front().second; // Get the current step count

            q.pop(); // Remove the current element from the queue

            // If we have reached the endWord, return the number of steps
            if (word == endWord)
                return step;

            // Iterate through each character in the current word
            for (int i = 0; i < word.size(); i++) {
                char original = word[i]; // Store the original character
                // Try replacing the character with every letter from 'a' to 'z'
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch; // Replace the character

                    // If the transformed word is in the set
                    if (st.find(word) != st.end()) {
                        st.erase(word); // Remove it to avoid cycles
                        q.push({word, step + 1}); // Add the new word to the queue with incremented step
                    }
                }

                // Restore the original character
                word[i] = original;
            }
        }

        // If we exhaust the queue without finding the endWord, return 0
        return 0;
    }
    
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends