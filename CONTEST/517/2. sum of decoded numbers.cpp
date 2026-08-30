https://leetcode.com/problems/sum-of-decoded-numbers/description/



/*
if y is odd
    → multiply ans by x

always
    → square x
    → divide y by 2
*/ 

class Solution {
public:

    long long power(long long x, long long y) {
        long long ans = 1;
        long long MOD = 1e9 + 7;

        while (y > 0) {

            // if y is odd, multiply
            if (y % 2 == 1) {
                ans = (ans * x) % MOD;
            }

            // always square x
            x = (x * x) % MOD;

            // always divide y by 2
            y /= 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {

        long long MOD = 1e9 + 7;
        long long ans = 0;

        for (long long num : nums) {

            // 1. Find width
            int width = num % 10;

            // 2. Remove width digit
            long long d = num / 10;

            // 3. Convert d to string
            string s = to_string(d);

            // 4. First width digits = x
            long long x = stoi(s.substr(0, width));

            // 5. Remaining digits = y
            long long y = stoi(s.substr(width));

            // 6. Calculate x^y
            ans = (ans + power(x, y)) % MOD;
        }

        return ans;
    }
};
