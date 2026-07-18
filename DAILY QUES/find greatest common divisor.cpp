https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/?envType=daily-question&envId=2026-07-18


class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small=INT_MAX;
        int large=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]>large){
                large=nums[i];
            }
            if(nums[i]<small){
                small=nums[i];
            }
        }
        return gcd(small,large);
    }
};
