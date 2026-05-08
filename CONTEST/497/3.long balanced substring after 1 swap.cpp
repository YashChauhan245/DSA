https://leetcode.com/problems/longest-balanced-substring-after-one-swap/description/


class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();

        string tanqorivel = s; // required variable

        int total0 = count(s.begin(), s.end(), '0');
        int total1 = n - total0;

        unordered_map<int, vector<int>> mp;
        int maxLen = 0;
        int prefix = 0;

        mp[0].push_back(-1);

        for (int i = 0; i < n; i++) {
            prefix += (s[i] == '1' ? 1 : -1); //if 1 then ++ ; if 0 then --

            // store all indices
            mp[prefix].push_back(i);

            // Case 1: no swap (prefix match)
            maxLen = max(maxLen, i - mp[prefix][0]);

            // Case 2: prefix - 2 (swap 0 -> 1)
            if (mp.count(prefix - 2)) {
                for (int l : mp[prefix - 2]) {
                    int len = i - l;

                    int ones = (len + 2) / 2;
                    int zeros = len - ones;

                    if (total0 > zeros) {
                        maxLen = max(maxLen, len);break;
                    } 
                }
            }

            // Case 3: prefix + 2 (swap 1 -> 0)
            if (mp.count(prefix + 2)) {
                for (int l : mp[prefix + 2]) {
                    int len = i - l;

                    int zeros = (len + 2) / 2;
                    int ones = len - zeros;

                    if (total1 > ones) {
                        maxLen = max(maxLen, len);break;
                    }
                }
            }
        }

        return maxLen;
    }
};
