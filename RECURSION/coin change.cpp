https://leetcode.com/problems/coin-change/

class Solution {
public:

    int solve(vector<int>& coins, int amount,int i){
        // base case
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(i>=coins.size()){
            return INT_MAX;
        }
        int inc=solve(coins,amount-coins[i],i);
        if(inc!=INT_MAX){
            inc+=1; //+1 bcz i coin already used
        }
        int exc=solve(coins,amount,i+1);
        return min(inc,exc);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans=solve(coins,amount,0);
        if (ans == INT_MAX){
            return -1; 
        }
        else{
            return ans;
        }
    }
};
