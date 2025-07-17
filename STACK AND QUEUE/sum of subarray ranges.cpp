https://leetcode.com/problems/sum-of-subarray-ranges/

approach-1)BRUTE FORCE 

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int mini= nums[i], maxy = nums[i];
            for (int j = i; j < n; j++) { //CAN BE J=I+1 ALSO 
                mini= min(mini, nums[j]);
                maxy = max(maxy, nums[j]);
                sum += (maxy - mini);
            }
        }
        return sum;
    }
};


APPROACH-2)USING STACK...


