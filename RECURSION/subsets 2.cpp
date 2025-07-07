https://leetcode.com/problems/subsets-ii/description/


class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>& nums,vector<int>temp,int i){
        // no proper base case as want all subsets including empty set
        result.push_back(temp);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]){
                continue;
            }
            temp.push_back(nums[j]);
            solve(nums,temp,j+1);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        solve(nums,temp,0);
        return result;

    }
};

