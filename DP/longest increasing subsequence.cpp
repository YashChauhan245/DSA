https://leetcode.com/problems/longest-increasing-subsequence/

//recursive 
// class Solution {
// public:
//     int solver(vector<int>&nums,int i,int p){
//         if(i==nums.size()){
//             return 0;
//         }
//         int take=0;
//         if(p==-1 ||nums[i]>nums[p]){//1st elements prev is -1 and afterthat if i>p
//             take=1+solver(nums,i+1,i);//update prev to curr element
//         }
//         int skip=solver(nums,i+1,p);
//         return max(take,skip);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         return solver(nums,0,-1);
//     }
// };


//top down 
// class Solution {
// public:
//     int solver(vector<int>&nums,int i,int p,vector<vector<int>>&dp){
//         if(i==nums.size()){
//             return 0;
//         }
//         if(dp[i][p+1]!=-1){  //p+1 to avoid 1st element as prev of 1st element is -1
//             return dp[i][p+1]; //p+1 to avoid negative coln as -1 as coln is not possible
//         }
//         int take=0;
//         if(p==-1 ||nums[i]>nums[p]){
//             take=1+solver(nums,i+1,i,dp);
//         }
//         int skip=solver(nums,i+1,p,dp);
//         return dp[i][p+1]=max(take,skip);
//     }
//     int lengthOfLIS(vector<int>& nums){
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return solver(nums,0,-1,dp);
//     }
// };




//bottom up 

class Solution {
public:
    int solver(vector<int>&nums,int i,int p){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){ //as prev is last i 
                int take=0;
                if(j==-1 ||nums[i]>nums[j]){
                take=1+dp[i+1][i+1]; //i+1 ,prev=i i.e j+1
                }
                int skip=dp[i+1][j+1]; //skip .so j+1 bcz prev (it should be j but due to shifting by +1 is top down too we write j+1 but ir its j/p only)
                dp[i][j+1]=max(take,skip);
            }
        }
        return dp[0][0]; //is -1 as shifted wth +1
    }
    int lengthOfLIS(vector<int>& nums){
        return solver(nums,0,-1);
    }
};
