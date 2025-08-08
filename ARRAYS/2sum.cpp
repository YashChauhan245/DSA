https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

// BRUTE FORCE:
        // vector<int>ans;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]+nums[j]==target){
        //             ans.push_back(i);
        //             ans.push_back(j);
                    
        //         }
        //     }
        // } 
        // return ans;


// OPTIMISED USING HASH

        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int ans=target-nums[i];
            if(mp.find(ans)!=mp.end()){//mapping ans with its index
                return{mp[ans],i}; //mp[ans] means ans(2) ka index
            }
            mp[nums[i]]=i;

        }
        return {};

    }
};
