https://leetcode.com/problems/longest-palindromic-subsequence/

*********using longest common subsequence just reverse the string as s2 and use same concept******

//recursive
class Solution {
public:
    int solver(string &s1, string &s2, int i, int j) {
        if (i >= s1.size() || j >= s2.size()) return 0;

        if (s1[i] == s2[j]) {
            return 1 + solver(s1, s2, i+1, j+1);
        } else {
            int skipi = solver(s1, s2, i+1, j);
            int skipj = solver(s1, s2, i, j+1);
            return max(skipi, skipj);
        }
    }

    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return solver(s, rev, 0, 0);
    }
};


//top down
class Solution {
public:
    int solver(string &s1, string &s2, int i, int j, vector<vector<int>>&dp) {
        if (i >= s1.size() || j >= s2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solver(s1, s2, i+1, j+1, dp);
        } else {
            int skipi = solver(s1, s2, i+1, j, dp);
            int skipj = solver(s1, s2, i, j+1, dp);
            return dp[i][j] = max(skipi, skipj);
        }
    }

    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solver(s, rev, 0, 0, dp);
    }
};



//bottom up
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (s[i] == rev[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};






**************without lis ****************

//recursive
// class Solution {
// public:
//     int solver(string &s,int i,int j){
//         if(i>j){
//             return 0;
//         }
//         if(i==j){//lenght +1
//             return 1;
//         }
//         if(s[i]==s[j]){
//             return 2+solver(s,i+1,j-1);
//         }
//         else{
//             int skipi=solver(s,i+1,j);
//             int skipj=solver(s,i,j-1);
//             return max(skipi,skipj);
//         }
//     }
//     int longestPalindromeSubseq(string s) {
//         int n=s.size();
//         return solver(s,0,n-1);
//     }
// };



//top down 
// class Solution {
// public:
//     int solver(string &s,int i,int j,vector<vector<int>>&dp){
//         if(i>j){
//             return 0;
//         }
        
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }

//         if(i==j){//lenght +1
//             return 1;
//         }
//         if(s[i]==s[j]){
//             return dp[i][j]=2+solver(s,i+1,j-1,dp);
//         }
//         else{
//             int skipi=solver(s,i+1,j,dp);
//             int skipj=solver(s,i,j-1,dp);
//             return dp[i][j]=max(skipi,skipj);
//         }
//     }
//     int longestPalindromeSubseq(string s) {
//         int n=s.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return solver(s,0,n-1,dp);
//     }
// };


//bottom up 

class Solution {
public:
    int solver(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (i == j) dp[i][j] = 1;
                else if (i < j) {
                    if (s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];
                    else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
                // if i > j, dp[i][j] remains 0
            }
        }
        return dp[0][n-1];
    }
    int longestPalindromeSubseq(string s) {
        return solver(s);
    }
};

// ******You compute many useless cases where j < i..*********8
    // so u can use loop j=i+1 

 
// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         int n = s.size();
//         vector<vector<int>> dp(n, vector<int>(n, 0));

//         // 1 length is always a palindrome
//         for (int i = 0; i < n; i++) dp[i][i] = 1;
//         for (int i = n-1; i >= 0; i--) {
//             for (int j = i+1; j < n; j++) {
//                 if (s[i] == s[j]) {
//                     dp[i][j] = 2 + dp[i+1][j-1];
//                 } else {
//                     dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[0][n-1];
//     }
// };
