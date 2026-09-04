https://leetcode.com/problems/permutation-in-string/description/?envType=problem-list-v2&envId=dlab054g



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();

        if (k > s2.length()) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char c : s1) {
            freq1[c - 'a']++;
        }

        for (int right = 0; right < s2.length(); right++) {

            // Add current character
            freq2[s2[right] - 'a']++;

            // If window becomes bigger than k,
            // remove the leftmost character
            if (right >= k) {
                freq2[s2[right - k] - 'a']--;
            }

            // Once window size is k, compare
            if (right >= k - 1) {
                if (freq1 == freq2) {
                    return true;
                }
            }
        }

        return false;
    }
};
