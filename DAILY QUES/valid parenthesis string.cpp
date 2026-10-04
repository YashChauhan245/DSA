https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2026-10-04


class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool solve(int i, int balance, string& s) {
        if (balance < 0)
            return false;

        if (i == n)
            return balance == 0;

        if (dp[i][balance] != -1)
            return dp[i][balance];

        bool ans;

        if (s[i] == '(') {
            ans = solve(i + 1, balance + 1, s);
        }
        else if (s[i] == ')') {
            ans = solve(i + 1, balance - 1, s);
        }
        else { 
            ans = solve(i + 1, balance + 1, s) ||
                  solve(i + 1, balance - 1, s) ||
                  solve(i + 1, balance, s);
        }

        return dp[i][balance] = ans;
    }

    bool checkValidString(string s) {
        n = s.size();
        dp.assign(n, vector<int>(n + 1, -1));
        return solve(0, 0, s);
    }
};
