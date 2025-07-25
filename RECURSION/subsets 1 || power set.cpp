https://leetcode.com/problems/subsets/submissions/1689207220/

class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>& nums,int i,vector<int>&temp){
        if (i == nums.size()) {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, i + 1, temp);
        // Backtrack
        temp.pop_back();
        solve(nums, i + 1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        solve(nums,0,temp);
        return result;
    }
};
