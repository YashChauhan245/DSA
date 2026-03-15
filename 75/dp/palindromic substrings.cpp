https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:

    bool check(string &s, int i, int j) {
        if(i >= j) {
            return true;
        }
        if(s[i] == s[j]) {
            return check(s, i+1, j-1);
        }
        return false;
    }

    int countSubstrings(string s) {
        int n = s.length();

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) { //check all possible substrings
                if(check(s, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};



//Approach-2(expand from centre)

class Solution {
public:
    int count = 0;
    void check(string& s, int i, int j, int n) {
        
        while(i >= 0 && j < n && s[i] == s[j]) {
            count++;
            i--; //expanding from center
            j++; //expanding from center
        }
    }
    int countSubstrings(string s) {
        int n = s.length();
        count = 0;
        
        /*
            
    Every single character in the string is a center for possible odd-length palindromes: check(s, i, i);
    Every pair of consecutive characters in the string is a center for possible even-length palindromes: check(s, i, i+1);.

        */
        for(int i = 0; i<n; i++) {
            check(s, i, i, n);
            check(s, i, i+1, n);
        }
        return count;
    }
};


