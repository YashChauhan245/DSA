https://leetcode.com/problems/minimum-score-by-changing-two-elements/description/?envType=daily-question&envId=2026-11-19


class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        
        //sort
        sort(begin(nums), end(nums));

        // low score = 0, bas high ko minimize karna hai
        return min({
            nums[n-3] - nums[0], // do sabse bade hatao
            nums[n-1] - nums[2], // do sabse chhote hatao
            nums[n-2] - nums[1]  // ek bada + ek chhota hatao
        });
    }
};
