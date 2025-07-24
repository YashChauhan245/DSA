https://leetcode.com/problems/subarrays-with-k-different-integers/submissions/1705837821/

APPROACH-1)TWO PASS 

class Solution {
public:
    int subarrayssw(vector<int>& nums, int k){
        int i=0;
        int j=0;
        int count=0;
        unordered_map<int,int>mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayssw(nums,k)-subarrayssw(nums,k-1);
    }
};



