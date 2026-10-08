https://leetcode.com/problems/remove-outermost-parentheses/description/?envType=daily-question&envId=2026-10-08


class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;

        string result = "";

        for(char &ch : s) {
            if(ch == '(') {
                if(count != 0) result.push_back(ch);

                count++;
            } else {
                count--;
                if(count != 0) result.push_back(ch);
            }
        }

        return result;
    }
};
