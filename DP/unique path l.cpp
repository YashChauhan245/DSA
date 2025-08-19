https://leetcode.com/problems/unique-paths/description/

//recursive
// class Solution {
// public:
//     int solver(int &m,int &n,int i,int j){
//         //desti tk aa gye
//         if(i==m-1 &&j==n-1){
//             return 1;
//         }
//         //safe check
//         if(i<0 ||i>=m||j<0 ||j>=n){
//             return 0;
//         }
//         //right and down ans;
//         int rightans=solver(m,n,i,j+1);
//         int downans=solver(m,n,i+1,j);
//         int ans=rightans+downans;
//         return ans;
//     }
//     int uniquePaths(int m, int n) {
//         return solver(m,n,0,0);
//     }
// };


//top down
// class Solution {
// public:
//     int solver(int &m,int &n,int i,int j,vector<vector<int>>&dp){
//         //destination tk aa gye
//         if(i==m-1 &&j==n-1){
//             return 1;
//         }
//         //safe check
//         if(i<0 ||i>=m||j<0 ||j>=n){
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         //right and down ans;
//         int rightans=solver(m,n,i,j+1,dp);
//         int downans=solver(m,n,i+1,j,dp);
//         dp[i][j]=rightans+downans;
//         return dp[i][j];
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
//         return solver(m,n,0,0,dp);
//     }
// };


//bottom up
// class Solution {
// public:
//     int solver(int &m,int &n,int i,int j){
//         vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
//         //store base case
//         dp[m-1][n-1]=1;

//         //loop logic
//         for(int i=m-1;i>=0;i--){
//             for(int j=n-1;j>=0;j--){
//      We don’t need to calculate dp[m-1][n-1] because it’s already set to 1.
//                 if(i == m-1 && j == n-1) continue; // skip destination
//                 int rightans=dp[i][j+1];
//                 int downans=dp[i+1][j];
//                 dp[i][j]=rightans+downans;
//             }
//         }
//         return dp[0][0];//reverse loop hai and mujhe 1t index chaiye only 
//     }
//     int uniquePaths(int m, int n) {
//         return solver(m,n,0,0);
//     }
// };



