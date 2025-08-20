https://leetcode.com/problems/minimum-falling-path-sum/description/


//recursive
// class Solution {
// public:
//     int solver(vector<vector<int>>& matrix,int m,int n,int j,int i){
//         //check boundary
//         if(j<0 || j>=n){
//             return 1e9;
//         } 
//         if(i==m-1){
//             return matrix[i][j];
//         }
//         int below=matrix[i][j]+solver(matrix,m,n,j,i+1);
//         int belowleft=matrix[i][j]+solver(matrix,m,n,j-1,i+1);
//         int belowright=matrix[i][j]+solver(matrix,m,n,j+1,i+1);
//         int ans=min({below,belowleft,belowright});
//         return ans;
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         int n=matrix[0].size();
//         int result=INT_MAX;
//         for(int j=0;j<n;j++){
//             result=min(result,solver(matrix,m,n,j,0));
//         }
//         return result;
//     }
// };


//top down 
// class Solution {
// public:
//     int solver(vector<vector<int>>& matrix,int m,int n,int i,int j, vector<vector<int>>&dp){
//         //check boundary
//         if(j<0 || j>=n){
//             return 1e9;
//         } 
//         if(i==m-1){
//             return matrix[i][j];
//         }
//         if(dp[i][j]!=-100000){
//             return dp[i][j]; 
//         }
//         int below=matrix[i][j]+solver(matrix,m,n,i+1,j,dp);
//         int belowleft=matrix[i][j]+solver(matrix,m,n,i+1,j-1,dp);
//         int belowright=matrix[i][j]+solver(matrix,m,n,i+1,j+1,dp);
//         dp[i][j]=min({below,belowleft,belowright});
//         return dp[i][j];
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m=matrix.size();
//         int n=matrix[0].size();
//         int result=INT_MAX;
//         vector<vector<int>>dp(m,vector<int>(n,-100000));
//         for(int j=0;j<n;j++){
//             result=min(result,solver(matrix,m,n,0,j,dp));
//         }
//         return result;
//     }
// };


//bottom up 
class Solution {
public:
    int solver(vector<vector<int>>& matrix,int m,int n){
        //dp create
        vector<vector<int>>dp(m,vector<int>(n,1e9));//can use n+1 and m+1 too
        for(int j=0;j<n;j++){
            dp[m-1][j]=matrix[m-1][j];
        }
        for(int i=m-2;i>=0;i--){//start from last 2nd row
            for(int j=n-1;j>=0;j--){//last coln
                int below=matrix[i][j]+dp[i+1][j];
                int belowleft  = (j > 0)     ? matrix[i][j] + dp[i+1][j-1] : 1e9;
                int belowright = (j < n-1)   ? matrix[i][j] + dp[i+1][j+1] : 1e9;
                dp[i][j]=min({below,belowleft,belowright});
            }
        }
        //cant be [0][0] as we want min.ans from 0th row and all coln
        return *min_element(dp[0].begin(), dp[0].end());
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int result=INT_MAX;
        return solver(matrix,m,n);
    }
};
// padding is worst use loop and bounday check instead

