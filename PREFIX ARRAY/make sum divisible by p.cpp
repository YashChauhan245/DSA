https://leetcode.com/problems/make-sum-divisible-by-p/

// step-1) target=sum&p
// step-2) find sum from 0 to i-->prev 
// step-3) find sum from 0 to j -->curr
// step4) sum(i to j) = (curr-prev)= target
//note  prev=curr-target (o(n))

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int SUM = 0;

        //(a+b)%p = (a%p + b%p) % p
        for(int &num : nums) {
            SUM = (SUM + num) % p;
        }

        int target = SUM%p;

        if(target == 0) {
            return 0;
        }

        unordered_map<int, int> mp; //prev sum%p ko store karega

        int curr = 0;
        mp[0] = -1;

        int result = n;
        for(int j = 0; j < n; j++) {
            curr = (curr + nums[j]) % p;

            int remain = (curr - target + p) % p;
            if(mp.find(remain) != mp.end()) {
                result = min(result, j - mp[remain]);
            }
            mp[curr] = j;
        }
        return result == n ? -1 : result;

    }
};
