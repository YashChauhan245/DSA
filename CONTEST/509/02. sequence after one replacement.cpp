https://leetcode.com/problems/subsequence-after-one-replacement/description/


https://www.youtube.com/watch?v=EwxiqOkruL4

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if (n > m)
            return false;
        vector<int> pref(n, m), suff(n, -1);
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i])
                j++;
            if (j < m) {
                pref[i] = j;
                j++;
            } else
                break;
        }
        if (pref[n - 1] < m)
            return true;

        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i])
                j--;
            if (j >= 0) {
                suff[i] = j;
                j--;
            } else
                break;
        }

        for (int i = 0; i < n; i++) {
            int l = -1, r = m;
            if (i > 0)
                l = pref[i - 1];
            if (i < n - 1)
                r = suff[i + 1];
            if (l != m && r != -1 && l + 1 < r) {
                return true;
            }
        }
        return false;
    }
};
