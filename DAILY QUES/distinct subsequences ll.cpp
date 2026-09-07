https://leetcode.com/problems/distinct-subsequences-ii/description/?envType=daily-question&envId=2026-09-07



// class Solution {
// public:
//     void solve(string& s, int i, string curr, set<string>& st) {
//         if (i == s.length()) {
//             if (!curr.empty())
//                 st.insert(curr);
//             return;
//         }

//         solve(s, i + 1, curr, st);

//         solve(s, i + 1, curr + s[i], st);
//     }


//     int distinctSubseqII(string s) {
//         set<string> st;
//         solve(s, 0, "", st);
//         return st.size();
//     }
// };



class Solution {
public:
    int M = 1e9 + 7;

    vector<int> dp;
    vector<int> prev;

    int solve(int n) {
        if (n == 0)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int total = (2LL * solve(n - 1)) % M;

        if (prev[n] != 0) {
            int duplicates = solve(prev[n] - 1);
            total = (total - duplicates + M) % M;
        }

        return dp[n] = total;
    }

    int distinctSubseqII(string s) {
        int n = s.length();

        dp.assign(n + 1, -1);
        prev.assign(n + 1, 0);

        vector<int> lastSeen(26, 0);

        for (int i = 1; i <= n; i++) {
            int idx = s[i - 1] - 'a';

            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }

        return (solve(n) - 1 + M) % M;
    }
};
