https://leetcode.com/problems/triangle/

//recursive
// class Solution {
// public:
//     int solver(vector<vector<int>>& triangle,int &m,int&n,int i,int j){
//         if(i==m-1){
//             return triangle[i][j];
//         }
//         // not need as they cant be o.f.b
//         // if(i>=m ){
//         //     return 0;
//         // }
//         int ithans=triangle[i][j]+solver(triangle,m,i+1,j);
//         int iplusans=triangle[i][j]+solver(triangle,m,i+1,j+1);
//         int ans=min(ithans,iplusans);
//         return ans;
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m=triangle.size();
////       int n=triangle[0].size();//not needed as column are not fixed then are inc. with row...diff in each row
//         return solver(triangle,m,0,0);
//     }
// };


//top down 

class Solution {
public:
    int solver(vector<vector<int>>& triangle,int &m,int i,int j,vector<vector<int>>&dp){
        if(i==m-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-100000){
            return dp[i][j];
        }
        int ithans=triangle[i][j]+solver(triangle,m,i+1,j,dp);
        int iplusans=triangle[i][j]+solver(triangle,m,i+1,j+1,dp);
        dp[i][j]=min(ithans,iplusans);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, -100000));//or can choose -2 as -1 are the output in tle case
        return solver(triangle,m,0,0,dp);
    }
};


//bottom down 

class Solution {
public:
    int solver(vector<vector<int>>& triangle,int &m,int i,int j){
        vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
        // Base case: copy last row bcz we need the values of whole last row
        for (int j = 0; j < m; j++) {
            dp[m - 1][j] = triangle[m - 1][j];
        }
        for(int i=m-2;i>=0;i--){//as we already store the last row to start from 2nd last
            for(int j=i;j>=0;j--){ //Row i of the triangle has exactly i + 1 elements
                int ithans=triangle[i][j]+dp[i+1][j];
                int iplusans=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(ithans,iplusans);  
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        return solver(triangle,m,0,0);
    }
};
