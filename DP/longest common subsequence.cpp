https://leetcode.com/problems/longest-common-subsequence/description/


//recursive
// class Solution {
// public:
//     int solver(string text1,string text2,int i,int j){
//         if(i>=text1.size() || j>=text2.size()){
//             return 0;
//         }
//         if(text1[i]==text2[j]){
//             return 1+solver(text1,text2,i+1,j+1);
//         }
//         else{
//             int skipi=solver(text1,text2,i+1,j);
//             int skipj=solver(text1,text2,i,j+1);
//             return max(skipi,skipj);
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//             return solver(text1,text2,0,0);
//     }
// };



//top down 
// class Solution {
// public:
//     int solver(string &text1,string &text2,int i,int j,vector<vector<int>>&dp){
//         if(i>=text1.size() || j>=text2.size()){
//             return 0;
//         }

//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         if(text1[i]==text2[j]){
//             return dp[i][j]=1+solver(text1,text2,i+1,j+1,dp);
//         }
//         else{
//             int skipi=solver(text1,text2,i+1,j,dp);
//             int skipj=solver(text1,text2,i,j+1,dp);
//             return dp[i][j]=max(skipi,skipj);
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size();
//         int m=text2.size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         return solver(text1,text2,0,0,dp);
//     }
// };



//bottom up 
class Solution {
public:
    int solver(string &text1,string &text2,int i,int j){
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    int skipi=dp[i+1][j];
                    int skipj=dp[i][j+1];
                    dp[i][j]=max(skipi,skipj);
                }
            }
        }
        return dp[0][0];
    }


    int longestCommonSubsequence(string text1, string text2) {
        return solver(text1,text2,0,0);
    }
};
