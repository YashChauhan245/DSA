https://leetcode.com/problems/subarray-sums-divisible-by-k/description/?utm_source=chatgpt.com


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        int rem=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rem=((sum % k) + k) % k;; //deals if neg as normal sum%k fails

            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }

            mp[rem]++;
        }
        return ans;
    }
};
