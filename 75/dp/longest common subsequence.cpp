https://leetcode.com/problems/longest-common-subsequence/description/

//recursion 

// class Solution {
// public:

//     int solver(string text1, string text2,int n,int m,int i,int j){
//         if(i>=n || j>=m){
//             return 0;
//         }

//         //matched
//         if(text1[i]==text2[j]){
//             return 1+solver(text1,text2,n,m,i+1,j+1);
//         }

//         //not matched
//         //case1 ->skip i
//         int skip_i=solver(text1,text2,n,m,i+1,j);
//         //case2->skip j
//         int skip_j=solver(text1,text2,n,m,i,j+1);
//         // return max from both
//         return max(skip_i,skip_j);
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size();
//         int m=text2.size();

//         return solver(text1,text2,n,m,0,0);
//     }
// };

//top down 
// class Solution {
// public:

//     int solver(string &text1, string &text2, int i, int j, vector<vector<int>>& dp){
        
//         if(i >= text1.size() || j >= text2.size())
//             return 0;

//         if(dp[i][j] != -1)
//             return dp[i][j];

//         if(text1[i] == text2[j]){
//             return dp[i][j] = 1 + solver(text1,text2,i+1,j+1,dp);
//         }

//         int skip_i = solver(text1,text2,i+1,j,dp);
//         int skip_j = solver(text1,text2,i,j+1,dp);

//         return dp[i][j] = max(skip_i,skip_j);
//     }

//     int longestCommonSubsequence(string text1, string text2) {

//         int n = text1.size();
//         int m = text2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
//         return solver(text1,text2,0,0,dp);
//     }
// };


//bottom up 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){

                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }

            }
        }

        return dp[0][0];
    }
};



//space optimised 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();

        vector<int> next(m+1,0);
        vector<int> curr(m+1,0);

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){

                if(text1[i]==text2[j]){
                    curr[j] = 1 + next[j+1];
                }
                else{
                    curr[j] = max(next[j], curr[j+1]);
                }
            }

            next = curr;
        }
        return next[0];
    }
};
