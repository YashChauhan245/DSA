https://leetcode.com/problems/partition-equal-subset-sum/description/

// recursive
// class Solution {
// public:
//     bool solver(vector<int>&nums,int x,int i){
//         if(x==0){
//             return true;
//         }
//         if(i>=nums.size() || x<0){
//             return false;
//         }
//         bool take=solver(nums,x-nums[i],i+1);
//         bool skip=solver(nums,x,i+1);
//         return take||skip;
//     }
//     bool canPartition(vector<int>& nums) {
//         int sum=accumulate(nums.begin(),nums.end(),0);//0 is initial value
//         if(sum%2!=0){
//             return false;
//         }
//         int x=sum/2;
//         return solver(nums,x,0);
//     }
// };



//top down

// class Solution {
// public:
//     bool solver(vector<int>&nums,int x,int i,vector<vector<int>>&dp){//can use int solver too
//         if(x==0){
//             return true;
//         }
//         if(i>=nums.size() || x<0){
//             return false;
//         }
//         if(dp[x][i]!=-1){
//             return dp[x][i];
//         }
//         bool take=solver(nums,x-nums[i],i+1,dp);
//         bool skip=solver(nums,x,i+1,dp);
//         dp[x][i]=take||skip;
//         return dp[x][i];
//     }
//     bool canPartition(vector<int>& nums) {
//         int sum=accumulate(nums.begin(),nums.end(),0);
//         int n=nums.size();
//         if(sum%2!=0){
//             return false;
//         }
//         int x=sum/2;
//         vector<vector<int>>dp(x+1,vector<int>(n+1,-1));//also can write n as i goes from 0 to n-1
//         return solver(nums,x,0,dp);
//     }
// };





//bottom up 

class Solution {
public:
    bool solveTab(vector<int>&nums, int target){
        int n = nums.size();
        vector<vector<bool> >dp(target+1, vector<bool>(n+1,0));//0 to counter base case that return false
        for(int col = 0; col<=nums.size();col++){//for x==0->return true i.e ki oth row se sb coln kko true krdo
            dp[0][col] = true;
        }
        for(int t=1; t<=target;t++){
            for(int i = n-1; i>=0; i--){
                bool inc = 0;
                if(t-nums[i]>=0) inc = dp[t-nums[i]][i+1];
                bool exc = dp[t][i+1];
                dp[t][i] = inc|| exc;
            }
        }
        return dp[target][0];
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        int x=sum/2;
        return solveTab(nums,x); 
    }
};




//space
    bool solveSO(vector<int>&nums, int target){
        int n = nums.size();
        vector<int>curr(target+1,0);
        vector<int>next(target+1,0);

        for(int col = 0; col<=nums.size();col++){
            next[0]= true;
        }

        for(int i = n-1; i>=0; i--){
            for(int t=1; t<=target;t++){
                bool inc = 0;
                if(t-nums[i]>=0) inc = next[t-nums[i]];
                bool exc = next[t];
                curr[t] = inc|| exc;
            }
            // shifting
            next = curr;
        }
        return next[target];
    }
    
    bool solveSO2(vector<int>&nums, int target){
        int n = nums.size();
        vector<int>curr(target+1,0);

        for(int col = 0; col<=nums.size();col++){
            curr[0]= true;
        }

        for(int i = n-1; i>=0; i--){
            for(int t=target; t>=1;t--){
                bool inc = 0;
                if(t-nums[i]>=0) inc = curr[t-nums[i]];
                bool exc = curr[t];
                curr[t] = inc|| exc;
            }
        }
        return curr[target];
    }
    
