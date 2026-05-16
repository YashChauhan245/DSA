https://leetcode.com/problems/count-digit-appearances/description/

class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        char target = digit + '0';

        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);

            for (int j = 0; j < s.size(); j++) {
                if (s[j] == target) {
                    count++;
                }
            }
        }
        return count;
    }
};
