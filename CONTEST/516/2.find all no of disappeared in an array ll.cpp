https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array-ii/description/


class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        long long curr=lower;

        for(int num:nums){
            if(num<lower || num>upper){
                continue;
            }
            if(curr<num){
                ans.push_back({(int)curr,num-1});
            }
            if(curr<=num){
                curr=(long long )num+1;
            }
        }
        if(curr<=upper){
            ans.push_back({(int)curr,upper});
        }
        return ans;
    }
};
