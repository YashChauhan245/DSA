https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/?envType=daily-question&envId=2026-06-04


//Approach (Linear Scan - Iterate over range and score each number)
//T.C : O((num2 - num1) * log10(num2))  — for each number we scan its digits
//S.C : O(log10(num2))                  — space for the digit string of each number

class Solution {
public:
    int findWaiveScore(int num) {
        string s = to_string(num);

        int l = s.length();
        if (l < 3)
            return 0;

        int waviness = 0;
        for (int i = 1; i <= l - 2; i++) {
            // peak
            if (s[i] > s[i - 1] && s[i] > s[i + 1]) waviness++;

            // valley
            if (s[i] < s[i - 1] && s[i] < s[i + 1]) waviness++;
        }
        return waviness;
    }

    int totalWaviness(int num1, int num2) {
        int waviness= 0;

        for (int num = num1; num <= num2; num++) {
            waviness+= findWaiveScore(num);
        }

        return waviness;
    }
};
