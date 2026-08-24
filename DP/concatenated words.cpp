https://leetcode.com/problems/concatenated-words/description/


RECURSIVE
// class Solution {
// public:

//     bool solve(string &word, int index, unordered_set<string> &st) {

//         if (index == word.size()) {
//             return true;
//         }
//         // Try every possible substring starting at index
//         for (int j = index + 1; j <= word.size(); j++) {

//             string part = word.substr(index, j - index);

//             // If this part exists in dictionary
//             if (st.count(part)) {

//                 // Recursively try to form the remaining part
//                 if (solve(word, j, st)) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }


//     vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
//         unordered_set<string> st;
//         // Put all words into set
//         for (string word : words) {
//             st.insert(word);
//         }

//         vector<string> ans;

//         for (string word : words) {
//             // Remove current word so it cannot use itself
//             st.erase(word);

//             // Try to form the word using other words
//             if (solve(word, 0, st)) {
//                 ans.push_back(word);
//             }

//             // Put it back
//             st.insert(word);
//         }
//         return ans;
//     }
// };


//TOP DOWN 

class Solution {
public:

    bool solve(string &word, int index, unordered_set<string> &st,vector<int> &dp) {

        if (index == word.size()) {
            return true;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        // Try every possible substring
        for (int j = index + 1; j <= word.size(); j++) {
            string part = word.substr(index, j - index);
            if (st.count(part)) {
                //try to form the remaining part
                if (solve(word, j, st, dp)) {
                    return dp[index] = 1;
                }
            }
        }
        // No way to form word from this index
        return dp[index] = 0;
    }


    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st;

        for (string word : words) {
            st.insert(word);
        }

        vector<string> ans;

        for (string word : words) {
            st.erase(word);
            int n = word.size();
            vector<int> dp(n + 1, -1);

            if (solve(word, 0, st, dp)) {
                ans.push_back(word);
            }

            // Put word back
            st.insert(word);
        }

        return ans;
    }
};
