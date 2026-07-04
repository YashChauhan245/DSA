https://leetcode.com/problems/unique-middle-element/description/

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>freq;

        for(int num:nums){
            freq[num]++;
        }

        int mid=nums[nums.size()/2];
        if(freq[mid]==1){
            return true;
        }
        return false;
    }
};
