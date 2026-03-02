https://leetcode.com/problems/contains-duplicate/description/


brute-->map both o(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
            if(mp[num]>1){
                return true;
            }
        }
        return false;  
    }
};



// if array modification is allowed:
o(nlogn) and o(1)

sort(nums.begin(), nums.end());
for(int i = 1; i < nums.size(); i++){
    if(nums[i] == nums[i-1])
        return true;
}
return false;
