https://leetcode.com/problems/edit-distance/solutions/

//recursive
// class Solution {
// public:
//     int solver(string &w1,string &w2,int i,int j){
//         int n=w1.size();
//         int m=w2.size();
//         if (i == n) return m - j; // need to insert remaining w2
//         if (j == m) return n - i; //need to delete remaining w1

//         if(w1[i]==w2[j]){
//             return solver(w1,w2,i+1,j+1);
//         }
//         else{//kuch bhi kra to ek operation +1 hue 
//             int insert=1+solver(w1,w2,i,j+1);
//             int del=1+solver(w1,w2,i+1,j);
//             int replace=1+solver(w1,w2,i+1,j+1);
//             return min({insert,del,replace});
//         }
//     }
//     int minDistance(string word1, string word2) {
//         return solver(word1,word2,0,0);
//     }
// };


//top down

// class Solution {
// public:
//     int solver(string &w1,string &w2,int i,int j,vector<vector<int>>&dp){
//         int n=w1.size();
//         int m=w2.size();
//         if (i == n) return m - j; // need to insert remaining w2
//         if (j == m) return n - i; //need to delete remaining w1

//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         if(w1[i]==w2[j]){
//             return dp[i][j]=solver(w1,w2,i+1,j+1,dp);
//         }
//         else{
//             int insert=1+solver(w1,w2,i,j+1,dp);
//             int del=1+solver(w1,w2,i+1,j,dp);
//             int replace=1+solver(w1,w2,i+1,j+1,dp);
//             return dp[i][j]=min({insert,del,replace});
//         }
//     }
//     int minDistance(string word1, string word2) {
//         int n=word1.size();
//         int m=word2.size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         return solver(word1,word2,0,0,dp);
//     }
// };


//bottom up

class Solution {
public:
    int solver(string &w1,string &w2,int i,int j){
        int n=w1.size();
        int m=w2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for (int i = 0; i <= n; i++) dp[i][m] = n - i; // last col
        for (int j = 0; j <= m; j++) dp[n][j] = m - j; // last row

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(w1[i]==w2[j]){
                    dp[i][j]=dp[i+1][j+1];
                } 
                else{
                    int insert=1+dp[i][j+1];
                    int del=1+dp[i+1][j];
                    int replace=1+dp[i+1][j+1];
                    dp[i][j]=min({insert,del,replace});
                }
            }
        }
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return solver(word1,word2,0,0);
    }
};
