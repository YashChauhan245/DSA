https://leetcode.com/problems/count-subarrays-with-majority-element-ii/description/?envType=daily-question&envId=2026-06-26

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        //Instead of map we can use an array of size 2*n+1 as well because we can have cumulaive sum from -n to +n)

        unordered_map<int,int> mp;   // mp[cumSum] = frequency of how many times cumSum has occurred
        
        int currSum = 0;
        
        mp[0] = 1; //we have seen cumSum = 0 in the beginning once

        long long validLeftPoints = 0;

        long long result = 0;

        for (int x : nums) {
            if (x == target) {
                validLeftPoints += mp[currSum];
                currSum++;
            } else {
                currSum--;
                validLeftPoints -= mp[currSum];
            }

            mp[currSum]++;

            result += validLeftPoints;
        }

        return result;
    }
};
