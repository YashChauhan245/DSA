https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:
    vector<vector<string>>result;

    bool ispalindrome(string &s,int l,int r){
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void solve(string &s,vector<string>&curr,int idx){
        if(idx==s.size()){
            result.push_back(curr);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(ispalindrome(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                solve(s,curr,i+1);
                curr.pop_back(); 
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        solve(s,curr,0);
        return result;
    }
};https://leetcode.com/problems/palindrome-partitioning/description/


