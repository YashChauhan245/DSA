https://leetcode.com/problems/maximum-valid-pair-sum/

class Solution {
public:
    long long  maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=LLONG_MIN;
        int best=INT_MIN;
        for(int i=k;i<n;i++){
            best=max(best,nums[i-k]);
            ans=max(ans,(long long)best+nums[i]);
        }
        return ans;
    }
};
