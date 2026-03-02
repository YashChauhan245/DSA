https://leetcode.com/problems/two-sum/description/

brute->tc-o(n^2) & sc->o(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i, j};    
                }
            }
        } 
        return {},
    }
};



optimized->o(n) & o(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;//value-index 
        for(int i=0;i<nums.size();i++){
            int ans=target-nums[i];
            if(mp.find(ans)!=mp.end()){ //search number
                return{mp[ans],i}; //index retrun 
            }
            mp[nums[i]]=i; //value-index 

        }
        return {};
    }
};
