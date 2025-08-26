https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

//recursive
// class Solution {
// public:
//     int solver(vector<int>&prices,int i,int flag,int limit){
//         if(i==prices.size()||limit==0){
//             return 0;
//         }
//         if(flag==1){
//             int buy=-prices[i]+solver(prices,i+1,0,limit);
//             int dontbuy=solver(prices,i+1,1,limit);
//             return max(buy,dontbuy);
//         }
//         else{
//             int sell=prices[i]+solver(prices,i+1,1,limit-1);
//             int dontsell=solver(prices,i+1,0,limit);
//             return max(sell,dontsell);
//         }
//     }
//     int maxProfit(vector<int>& prices) {
//         return solver(prices,0,1,2);//price,i,flag,limit
//     }
// };



//top down 
// class Solution {
// public:
//     int solver(vector<int>&prices,int i,int flag,int limit,vector<vector<vector<int>>>&dp){
//         if(i==prices.size()||limit==0){
//             return 0;
//         }
//         if(dp[i][flag][limit]!=-1){
//             return dp[i][flag][limit];
//         }
//         if(flag==1){
//             int buy=-prices[i]+solver(prices,i+1,0,limit,dp);
//             int dontbuy=solver(prices,i+1,1,limit,dp);
//             return dp[i][flag][limit]=max(buy,dontbuy);
//         }
//         else{
//             int sell=prices[i]+solver(prices,i+1,1,limit-1,dp);
//             int dontsell=solver(prices,i+1,0,limit,dp);
//             return dp[i][flag][limit]= max(sell,dontsell);
//         }
//     }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
//         return solver(prices,0,1,2,dp);   
//     }
// };




//bottom up 
// class Solution {
// public:
//     int solver(vector<int>&prices,int i,int flag,int limit){
//         int n=prices.size();
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

//         for(int i=n-1;i>=0;i--){
//             for(int j=0;j<2;j++){
//                 for(int k=1;k<3;k++){ //k cant be 0 to avoid k-1(0-1) in sell func
//                     if(j==1){
//                         int buy=-prices[i]+dp[i+1][0][k];
//                         int dontbuy=dp[i+1][1][k];
//                         dp[i][j][k]=max(buy,dontbuy);
//                     }
//                     else{
//                         int sell=prices[i]+dp[i+1][1][k-1];
//                         int dontsell=dp[i+1][0][k];
//                         dp[i][j][k]= max(sell,dontsell);
//                     }
//                 }
//             }
//         }
//         return dp[0][1][2];
//     }
//     int maxProfit(vector<int>& prices) {
//         return solver(prices,0,1,2);
        
//     }
// };


//space optimised

class Solution {
public:
    int solver(vector<int>&prices,int i,int flag,int limit,vector<vector<vector<int>>>&dp){
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<3;k++){ 
                    if(j==1){
                        int buy=-prices[i]+dp[1][0][k];
                        int dontbuy=dp[1][1][k];
                        dp[0][j][k]=max(buy,dontbuy);
                    }
                    else{
                        int sell=prices[i]+dp[1][1][k-1];
                        int dontsell=dp[1][0][k];
                        dp[0][j][k]= max(sell,dontsell);
                    }
                }
            }
            dp[1]=dp[0];
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(3,0)));
        return solver(prices,0,1,2,dp);
        
    }
};
