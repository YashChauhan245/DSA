https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/?envType=daily-question&envId=2026-07-19


class Solution {
public:
    string smallestSubsequence(string s) {
        // last[i] = last index where character ('a' + i) appears
        vector<int> last(26);

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        stack<char> st;

        // Keeps track of whether a character is already in the stack
        vector<bool> inStack(26, false);

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if (inStack[ch - 'a'])
                continue;

            // Remove larger characters if:
            // 1. Current character is smaller.
            // 2. The top character appears again later.
            while (!st.empty() &&
                   ch < st.top() &&
                   last[st.top() - 'a'] > i) {

                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            // Add current character
            st.push(ch);
            inStack[ch - 'a'] = true;
        }

        // Stack gives answer in reverse order
        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
