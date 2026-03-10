https://leetcode.com/problems/coin-change-ii/description/

// recursive->0(2^n)


// class Solution {
// public:

//     int solve(int i,int amount,vector<int>& coins,int n){
//         if(amount==0){
//             return 1;
//         }
//         if(i==n){
//             return 0;
//         }
//         if(amount<coins[i]){
//             return solve(i+1,amount,coins,n);
//         }
//         int take=solve(i,amount-coins[i],coins,n);
//         int skip=solve(i+1,amount,coins,n);
//         return take+skip;
//     }

//     int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         return solve(0,amount,coins,n);
//     }
// };


//top down 
// class Solution {
// public:

//     int solve(int i,int amount,vector<int>& coins,int n,vector<vector<int>>& dp){
//         if(amount==0){
//             return 1;
//         }
//         if(i==n){
//             return 0;
//         }
//         if (dp[i][amount]!=-1){
//             return dp[i][amount];
//         }
//         int take = 0;
//         if(coins[i] <= amount)
//             take = solve(i, amount - coins[i], coins, n, dp);

//         int skip = solve(i+1, amount, coins, n, dp);

//         return dp[i][amount] = take + skip;
//     }

//     int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount+1, -1));
//         return solve(0,amount,coins,n,dp);
//     }
// };


// bottom up  (2d)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1, 0));

        // base case-->if(amount==0){ return 1;}
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for(int i = n - 1; i >= 0; i--) { //array
            for(int a = 1; a <= amount; a++) {  //amount
                unsigned long long take = 0;
                if(coins[i] <= a)
                    take = dp[i][a - coins[i]];

                unsigned long long skip = dp[i + 1][a];

                dp[i][a] = take + skip;
            }
        }
        return dp[0][amount];
    }
};


// 1-D 
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {

//         vector<unsigned long long> dp(amount + 1, 0);
//         dp[0] = 1;

//         for(int i = 0; i < coins.size(); i++){
//             int coin = coins[i];

//             for(int a = coin; a <= amount; a++){
//                 dp[a] += dp[a - coin];
//             }
//         }

//         return dp[amount];
//     }
// };
