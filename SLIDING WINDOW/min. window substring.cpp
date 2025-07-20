https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n < m) return "";

        unordered_map<char, int> mp;
        for(char c : t) {
            mp[c]++;
        }

        int count = mp.size();
        int i = 0, j = 0;
        int minLen = INT_MAX;
        int start = 0;

        while(j < n) {
            // Expand the window
            if(mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }

            // Try to contract the window when all characters matched
            while(count == 0) {
                // Update answer if smaller window found
                if(j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }
                if(mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if(mp[s[i]] > 0)
                        count++;
                }
                i++; // shrink from left
            }
            j++; // expand from right
        }
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
