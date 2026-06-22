https://leetcode.com/problems/valid-subarrays-with-matching-sum-digits-i/description/


class Solution {
public:
    bool valid(long long sum, int x) {

        if (sum % 10 != x){ //last digit 
            return false;
        }

        long long first = sum;
        while (first >= 10) {  //iterate till the first digit
            first /= 10;
        }

        return first == x;
    }

    long long countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);

        //prefix array 
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        long long ans = 0;

        //check subarray in prefix array 
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                long long sum = pref[r + 1] - pref[l];

                if (valid(sum, x))
                    ans++;
            }
        }
        return ans;
    }
};
