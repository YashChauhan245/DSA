https://leetcode.com/problems/minimum-operations-to-form-subset-sum-i/

class Solution {
public:
    int solve(int i , int sum,vector<int>& nums,vector<vector<int>>& dp){
        if(sum==0){
            return 0;
        }
        if(i==nums.size()){
            return 1e9;
        }

        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int ans=1e9;

        //skip
        ans=solve(i+1,sum,nums,dp);
        int x=nums[i];

        //divide
        int value=x;
        int cost=0;

        while(value>0){
            if(value<=sum){
                int temp=solve(i+1,sum-value,nums,dp);
                if(temp!=1e9){
                    ans=min(ans,cost+temp);
                }
            }
            value/=2;
            cost++;
        }

        //multiply
        value=x;
        cost=0;

        while(value<=sum){
            int temp=solve(i+1,sum-value,nums,dp);
            if(temp!=1e9){
                ans=min(ans,cost+temp);
            }
            if(value>sum/2){
                break;
            }
            value*=2;
            cost++;
        }
        return dp[i][sum]=ans;     
    }
    
    
    int minOperations(vector<int>& nums, int sum) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        int ans=solve(0,sum,nums,dp);
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};
