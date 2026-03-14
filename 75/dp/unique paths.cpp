https://leetcode.com/problems/unique-paths/


//recursive 

// class Solution {
// public:
//     int solver(int m,int n,int i,int j){
//         //return paths
//         if(i==m-1 && j==n-1){
//             return 1;
//         }
//         //out of bound-boundary check 
//         if(i>=m || j>=n){
//             return 0;
//         }

//         int right=solver(m,n,i,j+1);
//         int down=solver(m,n,i+1,j);
//         return right+down;

//     }

//     int uniquePaths(int m, int n) {
//         return solver(m,n,0,0);
//     }
// };



//top down 

// class Solution {
// public:
//     int solver(int m,int n,int i,int j,vector<vector<int>>&dp){

//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }

//         if(i==m-1 && j==n-1){
//             return 1;
//         }
//         if(i>=m || j>=n){
//             return 0;
//         }

//         int right=solver(m,n,i,j+1,dp);
//         int down=solver(m,n,i+1,j,dp);
//         dp[i][j]=right+down;
//         return dp[i][j];
//     }
    
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
//         return solver(m,n,0,0,dp);
//     }
// };



//bottom up 

class Solution {
public:
    int solver(int m,int n,int i,int j){

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        dp[m-1][n-1] = 1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){

                if(i == m-1 && j == n-1) continue; 
//as we already assigned it previously and also due to loops we dont need i>=m or j>=n condn checks 

                int right=dp[i][j+1];
                int down=dp[i+1][j];
                dp[i][j]=right+down;
            }
        }
        return dp[0][0];
    }

    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solver(m,n,0,0);
    }
};
