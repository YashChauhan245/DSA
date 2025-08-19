https://leetcode.com/problems/unique-paths-ii/description/


//recursive
// class Solution {
// public:
//     int solver(vector<vector<int>>&obstacleGrid,int &m,int&n,int i,int j){
//         if(i==m-1 &&j==n-1){
//             return 1;
//         }
//         if(i<0 || i>=m ||j<0 ||j>=n ||obstacleGrid[i][j]==1){
//             return 0;
//         }
//         int rightans=solver(obstacleGrid,m,n,i,j+1);
//         int downans=solver(obstacleGrid,m,n,i+1,j);
//         int ans=rightans+downans;
//         return ans;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();
//         return solver(obstacleGrid,m,n,0,0);
//     }
// };


//top down 
// class Solution {
// public:
//     int solver(vector<vector<int>>&obstacleGrid,int &m,int&n,int i,int j,vector<vector<int>>&dp){
//         if(i<0 || i>=m ||j<0 ||j>=n ||obstacleGrid[i][j]==1){
//             return 0;
//         }
//         if(i==m-1 &&j==n-1){
//             return 1;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int rightans=solver(obstacleGrid,m,n,i,j+1,dp);
//         int downans=solver(obstacleGrid,m,n,i+1,j,dp);
//         dp[i][j]=rightans+downans;
//         return dp[i][j];
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();
//         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//         return solver(obstacleGrid,m,n,0,0,dp);
//     }
// };



//bottom up 

class Solution {
public:
    int solver(vector<vector<int>>&obstacleGrid,int &m,int&n,int i,int j){
        //optional 
        if (obstacleGrid[m-1][n-1] == 1) return 0;//if destination itself is a obstacle
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if (obstacleGrid[i][j] == 1) { 
                    dp[i][j] = 0; 
                    continue;
                }
                if(i == m-1 && j == n-1) continue; 
                long long rightans=dp[i][j+1];
                long long downans=dp[i+1][j];
                dp[i][j]=rightans+downans;
            }
        }
        return dp[0][0];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        return solver(obstacleGrid,m,n,0,0);
    }
};
