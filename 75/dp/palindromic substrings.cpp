https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:

    bool isPalindrome(string &s, int l, int r){
        if(l >= r) return true;

        if(s[l] != s[r]) return false;

        return isPalindrome(s, l+1, r-1);
    }

    int solve(string &s, int i){
        int n = s.size();

        if(i == n) return 0;

        int count = 0;

        for(int j = i; j < n; j++){
            if(isPalindrome(s, i, j)){
                count++;
            }
        }

        return count + solve(s, i + 1);
    }

    int countSubstrings(string s) {
        return solve(s, 0);
    }
};
