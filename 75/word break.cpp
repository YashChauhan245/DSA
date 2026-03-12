https://leetcode.com/problems/word-break/description/

//recursion 

// class Solution {
// public:
//     unordered_set<string> st;
//     int n;
//     bool solve(string &s, int idx) {  
//         if(idx == n) {    //worddict ke sabhi element mile jbhi idx yha tk aaya so true
//             return true;
//         }
//         for(int l =idx; l<=n; l++) {  
//             string temp = s.substr(idx,l-idx);
//             //if true then search for remaing dictwords
//             if(st.find(temp) != st.end() && l>idx &&solve(s, l)) //L is now the new idx 
//                 return true;  
//         }
//         return false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         n = s.length();
//         for(string &word : wordDict) {
//             st.insert(word);
//         }
//         return solve(s, 0);
//     }
// };


//top down 

// class Solution {
// public:
    
//     bool solve(string &s, int idx, unordered_set<string> &st, vector<int> &dp) {

//         if(idx == s.size())
//             return true;

//         if(dp[idx] != -1)
//             return dp[idx];

//         for(int l = idx + 1; l <= s.size(); l++) {
//             string temp = s.substr(idx, l - idx);
//             if(st.find(temp) != st.end() && solve(s, l,st,dp))
//                 return dp[idx] = true;
//         }
//         return dp[idx] = false;
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {

//         unordered_set<string> st(wordDict.begin(), wordDict.end());
//         vector<int> dp(s.size(), -1); //-1 → not computed 0 → false1 → true
//         return solve(s, 0, st, dp);
//     }
// };



//bottom up 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<bool> dp(n + 1, false); //false =0
        dp[n] = true;  //base case

        for(int i = n - 1; i >= 0; i--) {
            for(int l = i + 1; l <= n; l++) {
                string temp = s.substr(i, l - i);
                if(st.find(temp) != st.end() && dp[l]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
