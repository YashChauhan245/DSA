https://leetcode.com/problems/word-ladder/description/


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        // If endWord is not present → impossible
        if(st.find(endWord) == st.end()) return 0;

        // Step 2: BFS queue → (word, level)
        queue<pair<string, int>> q;
        q.push({beginWord, 1});  // start with level = 1

        // Remove beginWord from set
        st.erase(beginWord);

        // Step 3: BFS traversal
        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            string word = front.first;
            int steps = front.second;

            // If we reached target
            if(word == endWord) return steps;

            // Try changing every character
            for(int i = 0; i < word.size(); i++) {
                char original = word[i];

                // Try all 26 letters
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    // If new word exists in set → valid 
                    if(st.find(word) != st.end()) {
                        q.push({word, steps + 1});
                        st.erase(word); // mark visited 
                    }
                }

                // Restore original character
                word[i] = original;
            }
        }
        return 0;
    }
};
