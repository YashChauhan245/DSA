https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2026-09-28



class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for(char ch : s) {

            if(ch != ')') {
                st.push(ch);
            }

            else {
                string temp = "";

                while(st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                // Remove '('
                st.pop();
                // Put reversed string back
                for(char c : temp) {
                    st.push(c);
                }
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
