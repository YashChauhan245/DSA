https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

//recursive
// class Solution {
// public:
//     int solver(vector<int>&prices,int i,int flag){
//         if(i==prices.size()){
//             return 0;
//         }
//         if(flag==1){ //so we have to buy
//             int buy=-prices[i]+solver(prices,i+1,0);//profit=s-b=-b+s=-prices+sell()
//             int skip=0+solver(prices,i+1,1);
//             return max(buy,skip);
//         }
//         else{//flag is 0 we have to sell now
//             int sell=prices[i]+solver(prices,i+1,1);
//             int dontsell=solver(prices,i+1,0);
//             return max(sell,dontsell);
//         }
//     }
//     int maxProfit(vector<int>& prices) {
//         return solver(prices,0,1);
//     }
// };



//top down
// class Solution {
// public:
//     int solver(vector<int>&prices,int i,int flag,vector<vector<int>>&dp){
//         if(i==prices.size()){
//             return 0;
//         }
//         if(dp[i][flag]!=-1){
//             return dp[i][flag]; 
//         }
//         if(flag==1){ //so we have to buy  
//             int buy=-prices[i]+solver(prices,i+1,0,dp);//profit=s-b=-b+s=-prices+sell()
//             int skip=0+solver(prices,i+1,1,dp);
//             return dp[i][flag]=max(buy,skip);
//         }
//         else{//flag is 0 we have to sell now
//             int sell=prices[i]+solver(prices,i+1,1,dp);
//             int dontsell=solver(prices,i+1,0,dp);
//             return dp[i][flag]=max(sell,dontsell);
//         }
//     }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(2,-1));
//         return solver(prices,0,1,dp);
//     }
// };



//bottom up 
// class Solution {
// public:  
//     int solver(vector<int>&prices,int i,int flag){
//         int n=prices.size();
//         vector<vector<int>>dp(n+1,vector<int>(2,0));
//         for(int i=n-1;i>=0;i--){
//             for(int j=0;j<2;j++){
//                 if(j==1){ 
//                     int buy=-prices[i]+dp[i+1][0];
//                     int skip=0+dp[i+1][1];
//                     dp[i][j]=max(buy,skip);
//                 }
//                 else{//flag is 0 we have to sell now
//                     int sell=prices[i]+dp[i+1][1];
//                     int dontsell=dp[i+1][0];
//                     dp[i][j]=max(sell,dontsell);
//                 }
//             }
//         }
//         return dp[0][1];
//     }
//     int maxProfit(vector<int>& prices) {
//         return solver(prices,0,1);
//     }
// };


//space optimised
class Solution {
public:
    int solveSO(vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                if (j==1) {
                    int buyProfit = -prices[i] + dp[1][0];
                    int skipProfit = dp[1][1];            
                    dp[0][j] = max(buyProfit, skipProfit);
                } else {
                    int sellProfit = prices[i] + dp[1][1];
                    int skipProfit = dp[1][0];           
                    dp[0][j] = max(sellProfit, skipProfit);
                }
            }
            dp[1] = dp[0]; // shift curr → ahead
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(2, 0));
        return solveSO(prices, dp);
    }
};
