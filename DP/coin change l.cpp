https://leetcode.com/problems/coin-change/

//recursive
// class Solution {
// public:
//     int solver(vector<int>& coins, int amount, int i) {
//         if (amount < 0 || i == coins.size()) return 1e9; // impossible
//         if (amount == 0) return 0;                       // 0 coins needed

//         int take = 1 + solver(coins, amount - coins[i], i); // use coin
//         int skip = solver(coins, amount, i + 1);            // skip coin

//         return min(take, skip);
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         int ans = solver(coins, amount, 0);
//         return (ans >= 1e9 ? -1 : ans);
//     }
// };



//top down 
// class Solution {
// public:
//     int solver(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
//         if (amount < 0 || i == coins.size()) return 1e9; // impossible
//         if (amount == 0) return 0;                       // no more coins needed

//         if (dp[amount][i] != -1) return dp[amount][i];

//         // take this coin → add 1 and stay on same index
//         int take = 1 + solver(coins, amount - coins[i], i, dp);
//         // skip this coin → move to next index
//         int skip = solver(coins, amount, i + 1, dp);
//         return dp[amount][i] = min(take, skip);
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(amount + 1, vector<int>(n + 1, -1));
//         int ans = solver(coins, amount, 0, dp);
//         return (ans >= 1e9 ? -1 : ans);
//     }
// };



//bottom up 


class Solution {
public:
    int solver(vector<int>& coins, int amount, int i) {
        int n=coins.size();
        //create dp
        vector<vector<int>> dp(amount + 1, vector<int>(n + 1, 1e9));
        // if (amount == 0) return 0;
        //i.e 0th row ke sb coln 0 kro   
        for(int col=0;col<n;col++){
            dp[0][col]=0;
        }                 
        for(int a=1;a<=amount;a++){//amount 1->11 as zeero index is already filled
            for(int i=n-1;i>=0;i--){
                // if (amount < 0 || i == coins.size()) return 1e9;
                int take = 1e9;
                if(a-coins[i]>=0){//recrusive case if amount<0 retrun 1e9//preventing neg digits
                    take=1+dp[a-coins[i]][i];
                }
                int skip = dp[a][i+1];
                dp[a][i] = min(take, skip);
            }
        }  
        return dp[amount][0];
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solver(coins, amount, 0);
        return (ans >= 1e9 ? -1 : ans);
    }
};
