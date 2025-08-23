https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

APPROACH -1) JUST FIND LONGEST PALINDROMIC SUBSEQUENCE AND THEN SUBTRACT IN BY SIZE OF STRING
           (MIN INSERTION =N-LIS)

APPROACH-2)
//recursive
// class Solution {
// public:
//     int solver(string &s,int i,int j){
//         if(i>=j){  //equal bcz if i and j are at same elment so no insertion needed
//             return 0;
//         }
//         if(s[i]==s[j]){//no insertion needed go for i+1,j-1
//             return solver(s,i+1,j-1);
//         }
//         else{
//             //not equal so 1 insertion for sure
//             int iinc=1+solver(s,i+1,j);
//             int jinc=1+solver(s,i,j-1);
//             return min(iinc,jinc);
//         }
//     }
//     int minInsertions(string s) {
//         int n=s.size();
//         return solver(s,0,n-1);
//     }
// };


//top down
// class Solution {
// public:
//     int solver(string &s,int i,int j,vector<vector<int>>&dp){
//         if(i>=j){  //equal bcz if i and j are at same elment so no insertion needed
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         if(s[i]==s[j]){
//             return dp[i][j]=solver(s,i+1,j-1,dp);
//         }
//         else{
//             //not equal so 1 insertion for sure
//             int iinc=1+solver(s,i+1,j,dp);
//             int jinc=1+solver(s,i,j-1,dp);
//             return dp[i][j]=min(iinc,jinc);
//         }
//     }
//     int minInsertions(string s) {
//         int n=s.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return solver(s,0,n-1,dp);
//     }
// };



//bottom up
class Solution {
public:
    int solver(string &s,int i,int j){
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if (i < j) { 
                    if (s[i] == s[j]) {
                        dp[i][j] = dp[i+1][j-1];
                    } 
                    else {
                        int iinc = 1 + dp[i+1][j];
                        int jinc = 1 + dp[i][j-1];
                        dp[i][j] = min(iinc, jinc);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
    int minInsertions(string s) {
        int n=s.size();
        return solver(s,0,n-1);
    }
};
