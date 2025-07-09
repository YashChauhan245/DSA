https://leetcode.com/problems/word-break/

class Solution {
public:
    unordered_set<string> st;
    int n;
    bool solve(string &s, int idx) {  
        if(idx == n) {
            return true;
        }
        if(st.find(s)!= st.end()) {
            return true;
        } 
        for(int l = 1; l<=n; l++) {  
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(s, idx+l))
                return true;  
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        for(string &word : wordDict) {
            st.insert(word);
        }
        return solve(s, 0);
    }
};
