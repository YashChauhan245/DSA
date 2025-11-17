https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/?envType=daily-question&envId=2025-11-17

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -1;  // last index where 1 was found

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                if(last != -1 && i - last - 1 < k) return false;
                last = i;
            }
        }
        return true;
    }
};
