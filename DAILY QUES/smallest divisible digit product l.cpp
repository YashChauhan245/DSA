https://leetcode.com/problems/smallest-divisible-digit-product-i/description/?envType=daily-question&envId=2026-08-06


class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; i <= n + 10; i++) {
            int num = i;
            int product = 1;

            while (num > 0) {
                int digit = num % 10;
                product *= digit;
                num /= 10;
            }

            if (product % t == 0) {
                return i;
            }
        }

        return -1; 
    }
};
