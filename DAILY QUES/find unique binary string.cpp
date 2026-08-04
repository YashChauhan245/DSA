https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2026-08-04


class Solution {
public:
    string solve(string curr, int n, vector<string>& nums) {
        if (curr.size() == n) {
            for (string s : nums) {
                if (s == curr)
                    return "";
            }
            return curr; // Found a valid string
        }

        string left = solve(curr + '0', n, nums);
        if (left != "") return left;

        return solve(curr + '1', n, nums);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        return solve("", nums.size(), nums);
    }
};
