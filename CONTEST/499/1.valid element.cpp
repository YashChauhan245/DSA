https://leetcode.com/problems/valid-elements-in-an-array/


class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;
        vector<int> rmax(n);

        // step-1 -> right max
        rmax[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--) {
            rmax[i] = max(nums[i], rmax[i+1]);
        }

        // step-2 -> maintain left max
        int lmax = nums[0];

        // first always valid
        res.push_back(nums[0]);
        for(int i = 1; i < n-1; i++) {
            if(nums[i] > rmax[i+1] || nums[i] > lmax) {
                res.push_back(nums[i]);
            }
            lmax = max(nums[i], lmax);
        }

        // last always valid
        if(n > 1) {
            res.push_back(nums[n-1]);
        }

        return res;
    }
};
