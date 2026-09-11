https://leetcode.com/problems/unique-3-digit-even-numbers/description/?envType=daily-question&envId=2026-09-11




class Solution {
public:
    void solve(vector<int>& digits, vector<bool>& used, int num, int len, set<int>& st) {
        if (len == 3) {
            if (num % 2 == 0)
                st.insert(num);
            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (used[i]) continue;

            // No leading zero
            if (len == 0 && digits[i] == 0) continue;

            used[i] = true;
            solve(digits, used, num * 10 + digits[i], len + 1, st);
            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {
        set<int> st;
        vector<bool> used(digits.size(), false);
        solve(digits, used, 0, 0, st);
        return st.size();
    }
};
