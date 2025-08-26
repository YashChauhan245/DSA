https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/


//recursive
// class Solution {
// public:
//     int solver(vector<int>&prices,int i,int flag,int k){
//         if(i==prices.size()||k==0){
//             return 0;
//         }
//         if(flag==1){
//             int buy=-prices[i]+solver(prices,i+1,0,k);
//             int dontbuy=solver(prices,i+1,1,k);
//             return max(buy,dontbuy);
//         }
//         else{
//             int sell=prices[i]+solver(prices,i+1,1,k-1);
//             int dontsell=solver(prices,i+1,0,k);
//             return max(sell,dontsell);
//         }
//     }
//     int maxProfit(int k, vector<int>& prices) {
//         return solver(prices,0,1,k);
//     }
// };


//top down 
// class Solution {
// public:
//     int solver(vector<int>&prices,int i,int flag,int k,vector<vector<vector<int>>>&dp){
//         if(i==prices.size()||k==0){
//             return 0;
//         }
//         if(dp[i][flag][k]!=-1){
//             return dp[i][flag][k];
//         }
//         if(flag==1){
//             int buy=-prices[i]+solver(prices,i+1,0,k,dp);
//             int dontbuy=solver(prices,i+1,1,k,dp);
//             return dp[i][flag][k]=max(buy,dontbuy);
//         }
//         else{
//             int sell=prices[i]+solver(prices,i+1,1,k-1,dp);
//             int dontsell=solver(prices,i+1,0,k,dp);
//             return dp[i][flag][k]= max(sell,dontsell);
//         }
//     }
//     int maxProfit(int k,vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
//         return solver(prices,0,1,k,dp);   
//     }
// };





//bottom up 

// class Solution {
// public:
//     int solver(vector<int>&prices,int i,int flag,int k){
//         int n=prices.size();
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));

//         for(int i=n-1;i>=0;i--){
//             for(int j=0;j<2;j++){
//                 for(int l=1;l<k+1;l++){ //as we want the last trans too
//                     if(j==1){
//                         int buy=-prices[i]+dp[i+1][0][l];
//                         int dontbuy=dp[i+1][1][l];
//                         dp[i][j][l]=max(buy,dontbuy);
//                     }
//                     else{
//                         int sell=prices[i]+dp[i+1][1][l-1];
//                         int dontsell=dp[i+1][0][l];
//                         dp[i][j][l]= max(sell,dontsell);
//                     }
//                 }
//             }
//         }
//         return dp[0][1][k];
//     }
//     int maxProfit(int k,vector<int>& prices) {
//         return solver(prices,0,1,k);  
//     }
// };




//space optimised


class Solution {
public:
    int solver(vector<int>&prices,int i,int flag,int k,vector<vector<vector<int>>>&dp){
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int l=1;l<k+1;l++){ 
                    if(j==1){
                        int buy=-prices[i]+dp[1][0][l];
                        int dontbuy=dp[1][1][l];
                        dp[0][j][l]=max(buy,dontbuy);
                    }
                    else{
                        int sell=prices[i]+dp[1][1][l-1];
                        int dontsell=dp[1][0][l];
                        dp[0][j][l]= max(sell,dontsell);
                    }
                }
            }
            dp[1]=dp[0];
        }
        return dp[0][1][k];
    }
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(k+1,0)));
        return solver(prices,0,1,k,dp);
        
    }
};
