https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                else if ((ch == ')' && st.top() == '(') ||
                         (ch == '}' && st.top() == '{') ||
                         (ch == ']' && st.top() == '[')) {
                    st.pop();
                } else {
                    // if not matched ..but something still in stack 
                    return false;
                }
            }
        }

        return st.empty();  // true only if all brackets matched
    }
};

