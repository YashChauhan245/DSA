https://leetcode.com/problems/score-of-parentheses/description/?envType=daily-question&envId=2026-10-05



class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int score = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                st.push(score);
                score = 0;
            }
            else {
                if (s[i - 1] == '(') {
                    // ()
                    score = st.top() + 1;  
                }
                else {
                    // (A)
                    score = st.top() + 2 * score;
                }

                st.pop();
            }
        }

        return score;
    }
};
