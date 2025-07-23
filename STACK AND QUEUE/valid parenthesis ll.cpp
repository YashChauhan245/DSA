https://leetcode.com/problems/valid-parenthesis-string/


class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openStack, starStack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openStack.push(i);
            }
            else if (s[i] == '*') {
                starStack.push(i);
            }
            else { // s[i] == ')'
                if (!openStack.empty()) {
                    openStack.pop(); // match with '('
                }
                else if (!starStack.empty()) {
                    starStack.pop(); // treat '*' as '('
                }
                else {
                    return false; // no matching '(' or '*'
                }
            }
        }

        // Now match any remaining '(' with '*' acting as ')'
        while (!openStack.empty() && !starStack.empty()) {
            if (openStack.top() < starStack.top()) {
                openStack.pop();
                starStack.pop();
             }
            else {
                // '*' is before '(', invalid---->(**( IE NO CLOSING
                return false;
            }
        }

        return openStack.empty();
    }
};
