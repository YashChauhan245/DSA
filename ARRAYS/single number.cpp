// Leetcode - https://leetcode.com/problems/single-number/description/
class Solution {
public:
    int singleNumber(vector<int>& nums) {

// USING HASH MAP:
        // unordered_map<int,int>mapp;
        // for (int i=0;i<nums.size();i++){
        //     mapp[nums[i]]++;
        // }
        // for(int i=0;i<nums.size();i++){
        //     if(mapp[nums[i]]==1){
        //         return nums[i];
        //     }

        // }
        // return -1;



// USING XOR:
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
             result ^= nums[i];  // XOR each element
        }
        return result;

        
    }
};
