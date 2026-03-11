https://leetcode.com/problems/longest-increasing-subsequence/


//recursive 

// class Solution {
// public:
//     int solver(vector<int>& nums,int n,int i,int p){
//         if(i>=n){
//             return 0; //lis
//         }
//         int take=0;
//         if( p==-1 || nums[p]<nums[i]){
//             take=1+solver(nums,n,i+1,i);//updating p as current index 
//         }
//         int skip=solver(nums,n,i+1,p);

//         return max(take,skip);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         return solver(nums,n,0,-1);//prev=-1
//     }
// };



//top down 

// class Solution {
// public:
//     int solver(vector<int>& nums,int i,int p,vector<vector<int>>&dp){
//         if(i>=nums.size()){
//             return 0; //lis
//         }
//         if(dp[i] [p+1]!=-1){ //p+1 bcz i have already take -1 as default index
//             return dp[i][p+1];
//         }
//         int take=0;
//         if( p==-1 || nums[p]<nums[i]){
//             take=1+solver(nums,i+1,i,dp);//updating p as current index 
//         }
//         int skip=solver(nums,i+1,p,dp);

//         return dp[i] [p+1]=max(take,skip);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> dp(n, vector<int>(n+1, -1));
//         return solver(nums,0,-1,dp);//prev=-1
//     }
// };



//bottom up

// class Solution {
// public:
//     int solver(vector<int>&nums,int i,int p){
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//         for(int i=n-1;i>=0;i--){
//             for(int j=i-1;j>=-1;j--){
//                 int take=0;
//                 if(j==-1 ||nums[i]>nums[j]){
//                 take=1+dp[i+1][i+1];
//                 }
//                 int skip=dp[i+1][j+1];
//                 dp[i][j+1]=max(take,skip);
//             }
//         }
//         return dp[0][0];
//     }
//     int lengthOfLIS(vector<int>& nums){
//         return solver(nums,0,-1);
//     }
// };


//space 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> next(n+1,0);
        vector<int> curr(n+1,0);

        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                
                int take = 0;
                //update next prev acc to bottom up 
                if(prev==-1 || nums[i] > nums[prev]){
                    take = 1 + next[i+1];
                }

                int skip = next[prev+1];

                curr[prev+1] = max(take,skip);
            }

            next = curr;
        }

        return next[0];
    }
};
