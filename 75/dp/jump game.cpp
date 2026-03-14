https://leetcode.com/problems/jump-game/description/


//optimised 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;  // farthest index we can reach
        
        for (int i = 0; i < n; i++) {
            if (i > maxReach) return false;  // stuck
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) return true; // can reach end
        }
        return true;
    }
};

//recursion 
// class Solution {
// public:
    
//     bool solver(vector<int>&nums,int idx){
//         int n=nums.size();
//         if(idx==n-1){      //last index reached
//             return true;
//         }
//         if(idx>=n){       //more than last index
//             return false;
//         }

//         for(int i=1;i<=nums[idx];i++){ //loop for all the jumps that can me made from nums[idx]
//             if(solver(nums,idx+i)){    //recursion for diff paths
//                 return true;
//             }
//         }
//         return false;

//     }

//     bool canJump(vector<int>& nums) {
//         return solver(nums,0);
//     }
// };



//top down 

// class Solution {
// public:
    
//     bool solver(vector<int>&nums,int idx,vector<int>&dp){
//         int n=nums.size();
//         if(idx==n-1){    
//             return true;
//         }
//         if(idx>=n){       
//             return false;
//         }

//         if(dp[idx]!=-1){
//             return dp[idx];
//         }

//         for(int i=1;i<=nums[idx];i++){
//             if(solver(nums,idx+i,dp)){   
//                 dp[idx]= 1;
//                 return true;
//             }
//         }
//         dp[idx]=0;
//         return false;

//     }

//     bool canJump(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n+1,-1);
//         return solver(nums,0,dp);
//     }
// };


//bottom up 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> dp(n,false);
        dp[n-1] = true;   // base case

        for(int idx = n-2; idx >= 0; idx--){
            for(int i = 1; i <= nums[idx]; i++){
                if(idx + i < n && dp[idx + i]){ 
            //boundary check to ensure we do not access an index outside the array.
                    dp[idx] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
