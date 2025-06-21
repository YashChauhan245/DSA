// Leetcode - https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

// // BRUTE FORCE---> 2-POINTER(FINDING SUBARRAY THEN SUM):

        // int count=0;
        // for(int i=0;i<nums.size();i++){
        //     int sum=0;
        //     for(int j=i;j<nums.size();j++){
        //         sum=sum+nums[j];
        //         if(sum==k){
        //             count++;
        //         }
        //     }
        // }
        // return count;


// HASH MAP--->MORE OPTIMISED (imp):

        int result = 0;
        int sum = 0;
        map<int, int> mp;
        mp.insert({0,1});//inserting sum=0 with freq =1
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            sum += nums[i];//calc sum
            
            if(mp.find(sum-k)!=mp.end())  //If sum is in map .... then update result
                result += mp[sum-k];//mp[sum-k]... jitni baar freq update hui hai
            
            mp[sum]++;// map update: if 'sum 'not present than store it otherwise 'update' freq
        }
        return result;  
        
    }
};
