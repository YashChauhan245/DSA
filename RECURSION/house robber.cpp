https://leetcode.com/problems/house-robber/

class Solution {
public:
    int solve(vector<int>& nums,int i){
        if(i>=nums.size()){
            return 0;
        }
        int a=nums[i];
        int inc=a+solve(nums,i+2);
        int exc=solve(nums,i+1);
        return max(inc,exc);

    }
    int rob(vector<int>& nums) {
        int result=solve(nums,0);
        return result;
        
    }
};
