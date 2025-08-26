https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

// recursive
// class Solution {
// public:
//     int solver(vector<int>&prices,int i,int flag){
//         if(i>=prices.size()){
//             return 0;
//         }
//         if(flag==1){ 
//             int buy=-prices[i]+solver(prices,i+1,0);
//             int skip=0+solver(prices,i+1,1);
//             return max(buy,skip);
//         }
//         else{
//             int sell=prices[i]+solver(prices,i+2,1);
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
//         if(i>=prices.size()){
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
//             int sell=prices[i]+solver(prices,i+2,1,dp);
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
class Solution {
public:  
    int solver(vector<int>&prices,int i,int flag){
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
       // vector<vector<int>>dp(n+1,vector<int>(2,0));//but now we have to give i+2 check in sell condn
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==1){ //so we have to j  
                    int buy=-prices[i]+dp[i+1][0];
                    int skip=0+dp[i+1][1];
                    dp[i][j]=max(buy,skip);
                }
                else{//flag is 0 we have to sell now
                    int sell=prices[i]+dp[i+2][1];
                    //if we use n+1 then apply check for out of bound
                    // int sell = prices[i] + (i+2 <= n ? dp[i+2][1] : 0);
                    int dontsell=dp[i+1][0];
                    dp[i][j]=max(sell,dontsell);
                }
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        return solver(prices,0,1);
    }
};

