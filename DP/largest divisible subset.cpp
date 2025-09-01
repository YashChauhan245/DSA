https://leetcode.com/problems/largest-divisible-subset/description/


https://leetcode.com/problems/largest-divisible-subset/

// recursive
// class Solution {
// public:
//     void solver(int i,vector<int>&nums,vector<int>&result,vector<int>&temp,int prev){
//         if(i==nums.size()){
//             //store max ans in result
//             if(temp.size()>result.size()){
//                 result=temp;
//             }
//             return;
//         }
//         //take
//         if(prev==-1 ||nums[i]%prev==0){
//             temp.push_back(nums[i]);
//             solver(i+1,nums,result,temp,nums[i]);
//             //again pop_back for skip case
//             temp.pop_back();
//         }
//         //skip 
//         solver(i+1,nums,result,temp,prev);
//     }
//     vector<int>largestDivisibleSubset(vector<int>& nums){
//         sort(nums.begin(),nums.end());
//         vector<int>result;
//         vector<int>temp;
//         solver(0,nums,result,temp,-1);
//         return result;
//     }
// };




//top down 

// class Solution {
// public:
//     void solver(int i,vector<int>&nums,vector<int>&result,vector<int>&temp,int prev,vector<vector<int>>&dp){
//         if(i==nums.size()){
//             //store max ans in result
//             if(temp.size()>result.size()){
//                 result=temp;
//             }
//             return;
//         }
//         if(dp[i][prev+1]!=-1){
//             return dp[i][prev+1];
//         }
//         //take
//         if(prev==-1 ||nums[i]%prev==0){
//             temp.push_back(nums[i]);
//             solver(i+1,nums,result,temp,nums[i],dp);
//             //again pop_back for skip case
//             temp.pop_back();
//         }
//         //skip 
//         solver(i+1,nums,result,temp,prev,dp);
//     }
//     vector<int>largestDivisibleSubset(vector<int>& nums){
//         int n=nums.size();
//         vector<int>result;
//         vector<int>temp;
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1);
//         solver(0,nums,result,temp,-1,dp);
//         return result;
//     }
// };




//bottom up 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // dp[i][j+1] = best length starting at i with prev=j (shift -1 -> 0)
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // fill bottom-up
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i - 1; j >= -1; --j) {
                int take = 0;
                if (j == -1 || nums[i] % nums[j] == 0) {
                    take = 1 + dp[i + 1][i + 1];   // new prev = i → column i+1
                }
                int skip = dp[i + 1][j + 1];
                dp[i][j + 1] = max(take, skip);
            }
        }

        // reconstruct by walking dp (only take if it's allowed AND matches dp choice)
        vector<int> subset;
        int i = 0, j = -1;
        while (i < n) {
            bool canTake = (j == -1 || nums[i] % nums[j] == 0);
            int wantTakeLen = canTake ? 1 + dp[i + 1][i + 1] : -1; // -1 to forbid accidental ties

            if (canTake && dp[i][j + 1] == wantTakeLen) {
                subset.push_back(nums[i]);
                j = i;
            }
            // whether we took or skipped, move to next i
            ++i;
        }
        return subset;
    }
};
