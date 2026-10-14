https://leetcode.com/problems/maximize-sum-of-squares-of-digits/description/?envType=daily-question&envId=2026-10-14




class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return ""; //if num=3 and sum=28 ..9*3=27

        string ans = "";

        for (int i = 0; i < num; i++) {
            int digit = min(9, sum);
            ans += to_string(digit);
            sum -= digit;
        }

        if (sum != 0) return "";

        return ans;
    }
};
