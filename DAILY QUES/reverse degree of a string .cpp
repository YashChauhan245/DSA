https://leetcode.com/problems/reverse-degree-of-a-string/description/?envType=daily-question&envId=2026-09-20



class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for(int i = 0; i < s.length(); i++) {
            int reverseValue = 'z' - s[i] + 1;
            
            sum += reverseValue * (i + 1);
        }

        return sum;
    }
};
