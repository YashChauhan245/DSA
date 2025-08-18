https://leetcode.com/problems/house-robber/description/

// recursive -->0(2n)
// class Solution {
// public:
//     int solver(vector<int>&nums,int i){
//         if(i>=nums.size()){
//             return 0;
//         }
//         int take=nums[i]+solver(nums,i+2);//1st element le liya 
//         int skip=solver(nums,i+1);
//         return max(take,skip);
//     }
//     int rob(vector<int>& nums) {
//         return solver(nums,0);
//     }
// };


// top down
// class Solution {
// public:
//     int solver(vector<int>&nums,vector<int>&dp,int i){
//         //if base case solved store it
//         if(i>=nums.size()){
//             return 0;
//         }
//         if(dp[i]!=-1){
//             return dp[i];
//         }
//         //store recursive ans in dp 
//         int take=nums[i]+solver(nums,dp,i+2);
//         int skip=solver(nums,dp,i+1);
//         dp[i]=max(take,skip);
//         return dp[i];
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n+1,-1);
//         return solver(nums,dp,0);
//     }
// };

// bottom up 
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         //create dp 
//         int n=nums.size();
//         vector<int>dp(n+2,0);//n=2 for safety of out of bound 
//         // and 0 for loop bcz we are going from n to 0 
//         //****or iska mtlb ye hai bcz hum already 0 return kr rhe the jb i>nums.size() se 
    
//         //base case analyze and update dp array 
//         //optional bcz already 0 hai dp me
//         vector<int>dp(n+2,-1);
//         dp[n]=0;
//         dp[n+1]=0;

//         //loop
//         for(int i=nums.size()-1;i>=0;i--){
//             int take=nums[i]+dp[i+2];
//             int skip=dp[i+1];
//             dp[i]=max(take,skip);
//         }
//         return dp[0];//ans starting from house 0;
//     }
// };

// space 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // if (n == 0) return 0;
        // if (n == 1) return nums[0];

        int next1 = 0; // dp[i+1]
        int next2 = 0; // dp[i+2]
        int curr = 0;

        // iterate backwards like in bottom-up
        for (int i = n-1; i >= 0; i--) {
            int take = nums[i] + next2;
            int skip = next1;
            curr = max(take, skip);

            // shift values
            next2 = next1;
            next1 = curr;
        }

        return curr;
    }
};
