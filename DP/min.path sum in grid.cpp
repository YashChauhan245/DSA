https://leetcode.com/problems/minimum-path-sum/description/

//recursive
// class Solution {
// public:
//     int solver(vector<vector<int>>& grid,int &m,int &n,int i,int j){
//         if(i<0 ||i>=m ||j<0||j>=n){
//             return 1e9;//cant return 0 bcz its already minimize
//         }
//         if(i==m-1 &&j==n-1){
//             return grid[i][j];
//         }
//         int rightsum=grid[i][j]+solver(grid,m,n,i,j+1);
//         int downsum=grid[i][j]+solver(grid,m,n,i+1,j);
//         int ans=min(rightsum,downsum);
//         return ans;
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         return solver(grid,m,n,0,0);
//     }
// };


//top bottom 
// class Solution {
// public:
//     int solver(vector<vector<int>>& grid,int &m,int &n,int i,int j,vector<vector<int>>&dp){
//         if(i<0 ||i>=m ||j<0||j>=n){
//             return 1e9;//cant return 0 bcz its already minimize
//         }
//         if(i==m-1 &&j==n-1){
//             return grid[i][j];
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int rightsum=grid[i][j]+solver(grid,m,n,i,j+1,dp);
//         int downsum=grid[i][j]+solver(grid,m,n,i+1,j,dp);
//         dp[i][j]=min(rightsum,downsum);
//         return dp[i][j];
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//         return solver(grid,m,n,0,0,dp);
//     }
// };



//bottom up 
class Solution {
public:
    int solver(vector<vector<int>>& grid,int &m,int &n,int i,int j){
        vector<vector<int>>dp(m,vector<int>(n,1e9));//use 1e9 to avoid and choice is u can use n,n+1 and m or m+1;
//         if(i<0 ||i>=m ||j<0||j>=n)
//             return 1e9;
        dp[m-1][n-1]=grid[m-1][n-1];//jo bhi grid me destination hai 
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 &&j==n-1){
                    continue;
                }
                int rightsum = (j+1 < n) ? grid[i][j] + dp[i][j+1] : 1e9;
                int downsum  = (i+1 < m) ? grid[i][j] + dp[i+1][j] : 1e9;
                dp[i][j]=min(rightsum,downsum);
            }
        }
        return dp[0][0];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        return solver(grid,m,n,0,0);
    }
};

