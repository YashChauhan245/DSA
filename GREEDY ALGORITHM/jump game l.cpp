https://leetcode.com/problems/jump-game/description/

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
