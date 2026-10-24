https://leetcode.com/problems/difference-between-peaks-and-valleys/description/


class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int peaksum=0;
        int valleysum=0;

        for(int i=1;i<(int)nums.size()-1;i++){
            if(nums[i]>nums[i-1]  && nums[i]>nums[i+1]){
                peaksum+=nums[i];
            }
            else if (nums[i]<nums[i-1]  && nums[i]<nums[i+1]){
                valleysum+=nums[i];
            }
        }
        return peaksum-valleysum;
    }
};
