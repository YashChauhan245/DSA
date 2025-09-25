https://leetcode.com/problems/triangle/description/?envType=daily-question&envId=2025-09-25


// class Solution {
// public:
//     int solver(vector<vector<int>>& triangle,int &m,int i,int j){
//         if(i==m-1){
//             return triangle[i][j];
//         }
//         int addjth=triangle[i][j]+solver(triangle,m,i+1,j);
//         int addjthplus=triangle[i][j]+solver(triangle,m,i+1,j+1);
//         return min(addjth,addjthplus);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m=triangle.size();
//         return solver(triangle,m,0,0);
//     }
// };


//top down 

// class Solution {
// public:
//     int solver(vector<vector<int>>& triangle,int &m,int i,int j,vector<vector<int>>&dp){
//         if(i==m-1){
//             return triangle[i][j];
//         }
//         if(dp[i][j]!=-2){
//             return dp[i][j];
//         }
//         int addjth=triangle[i][j]+solver(triangle,m,i+1,j,dp);
//         int addjthplus=triangle[i][j]+solver(triangle,m,i+1,j+1,dp);
//         dp[i][j]= min(addjth,addjthplus);
//         return dp[i][j];
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m=triangle.size();
//         vector<vector<int>>dp(m+1,vector<int>(m+1,-2));//as -1 is output in tle
//         return solver(triangle,m,0,0,dp);
//     }
// };


//bottom up
class Solution {
public:
    int solver(vector<vector<int>>& triangle,int &m,int i,int j){
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        //storing last row
        for (int j = 0; j < m; j++) {
            dp[m - 1][j] = triangle[m - 1][j];
        }

        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){//note
                int addjth=triangle[i][j]+dp[i+1][j];
                int addjthplus=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]= min(addjth,addjthplus);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        return solver(triangle,m,0,0);
    }
};
