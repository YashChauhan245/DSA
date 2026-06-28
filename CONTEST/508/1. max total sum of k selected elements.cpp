https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/description/

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<int>());

        long long ans=0;
        for(int i=0;i<k;i++){
            if(mul>1){
                ans+=1LL*nums[i]*mul;
            }
            else{
                ans+=nums[i];
            }
            mul--;
        }
        return ans;
    }
};
