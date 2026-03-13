https://leetcode.com/problems/house-robber/description/


//recursive 

// class Solution {
// public:

//     int solver(vector<int>& nums,int i){
//         int n=nums.size();
//         if(i>=n){
//             return 0;
//         }
//         //take
//         int take=nums[i]+solver(nums,i+2);
//         //skip
//         int skip=solver(nums,i+1);

//         return max(take,skip);
//     }

//     int rob(vector<int>& nums) {
//         return solver(nums,0);
//     }
// };



//top down 

// class Solution {
// public:

//     int solver(vector<int>& nums,int i,vector<int>&dp){
//         int n=nums.size();
//         if(i>=n){
//             return 0;
//         }

//         if (dp[i]!=-1){
//             return dp[i];
//         }

//         //take
//         int take=nums[i]+solver(nums,i+2,dp);
//         //skip
//         int skip=solver(nums,i+1,dp);

//         return dp[i]= max(take,skip);
//     }


//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n+1,-1);
//         return solver(nums,0,dp);
//     }
// };



//bottom up  (both o(n))
class Solution {
public:

    int solver(vector<int>& nums ){
        int n=nums.size();
        vector<int>dp(n+2,0); //overcome out of bound by n+2 

        for(int i=n-1;i>=0;i--){
            int take=nums[i]+dp[i+2];
            int skip=dp[i+1];
            dp[i]= max(take,skip);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        return solver(nums);
    }
};
